use axum::{extract::State, http::StatusCode, response::IntoResponse};
use bytes::Bytes;
use prost::Message;                                   // 前端传过来是 二进制

use crate::{
    AppState, 
    pb::
        {
            request::{
                EmailCodeRequest, 
                RegisterRequest,
                LoginRequest
            },
            response::{
                AuthResponse, CodeResponse, UserData
                }
        }, 
    service::
    {
        em_service::
        {
            em_service
        },
        lo_service,
        re_service,
        redis_service::
        { 
            save_code_redis
        }
    },
    tool::{
        rand_str::{
            rand_code,
        }
    },
};

/**
 * 26_2_5
 * 登录的控制器
 * 
 */
pub async  fn lo_controller(
    State(state):State<AppState>,
    body : Bytes
)
    -> impl  IntoResponse
{
    let req = match LoginRequest::decode(body)
    {
        Ok(r) => r,
        Err(_) =>{
            return (
                StatusCode::BAD_REQUEST,
                "无效的数据"
            ).into_response()
        }
    };

    let mut res = AuthResponse::default();
    
    match lo_service::login_service(&state.pool, req).await{

        Ok(data) =>{
            res.code = 200;
            res.msg = "登录成功".into();
            res.data = Some(UserData{
                user_id : data.id.to_string(),
                token: data.token,
                username : data.username,
                avatar : data.avatar,
                created_at : "".to_string(),
            });
        }
        Err(code)=>{
            res.code = code as i32;
            res.msg = match code {
                500 =>{
                    "服务器错误".to_string()        // 这里的 to_string 就是让编译器 自动推导
                },
                401=>{
                    "用户名错误".into()
                }
                404 =>{
                    "用户不存在".into()
                }
                _=>{
                    "未知错误".into()
                }
            };
            res.data = None;
        }
    }

    let mut buf = Vec::new();
    if let Err(_) = res.encode(&mut buf){
        return (
            StatusCode::INTERNAL_SERVER_ERROR,
            "内部服务器错误"
        ).into_response()
    };

    (
        StatusCode::OK,
        [("content-type","application/x-protobuf")],
        buf
    ).into_response()

}



/**
 * 26_2_7
 * 注册的逻辑
 * 
 */

pub async fn re_controller(
    State(state): State<AppState>,
    body: Bytes,
) -> impl IntoResponse {
    let req = match RegisterRequest::decode(body) {
        Ok(r) => r,
        Err(_) => {
            return (StatusCode::BAD_REQUEST, "Unvalid data").into_response();
        }
    };

    let mut res = AuthResponse::default();

    match re_service::register_service(&state.pool, req).await {
        Ok(data) => {
            res.code = 200;
            res.msg = "register success".into();
            res.data = Some(UserData {
                user_id:data.id.to_string(),
                token: data.token,
                username: data.username,
                avatar: data.avatar,
                created_at: data.create_at,
            });
        }
        Err(code) => {
            res.code = code as i32;
            res.msg = match code {
                409 => "This email has already been registered".into(),
                400 => "Bad Request".into(),
                500 => "Internal Server Error".into(),
                _ => "Unkown mistake".into(),
            };
            res.data = None;
        }
    }

    let mut buf = Vec::new();
    if res.encode(&mut buf).is_err() {
        return (StatusCode::INTERNAL_SERVER_ERROR, "Internal Server Error").into_response();
    }

    (
        StatusCode::OK, 
        [("content-type", "application/x-protobuf")],
        buf,
    )
        .into_response()
}


/**
 * 26_2_7
 * 发送邮件的逻辑
 */
pub async fn em_controller(
    state: State<AppState>,
    body : Bytes
)
    -> impl IntoResponse
{

    let req = match EmailCodeRequest::decode(body){
        Ok(r) => r,
        Err(_) =>{
            return (
                StatusCode::BAD_REQUEST,
                "Request parsing error"
            ).into_response()
        }
    };

    let mut res = CodeResponse::default();
    let code = rand_code();

    match em_service(&req.email,code).await {
        Ok(()) => {
            res.code = 200;
            res.msg = "Verification code sent successfully.".to_string();
            res.verify_code = code;
        }
        Err(e) => {
            eprintln!("{:#}",e);
            res.code = 500;
            res.msg = "Internal Server Error".to_string();
            res.verify_code = -1;
        }
    }

    // 存到 redis里面
    if let Err(e) = save_code_redis(
        &state,
        &req.email,
        code,
        300
    ).await{
        return (
            StatusCode::INTERNAL_SERVER_ERROR,
            e
        ).into_response()
    }

    // 序列化 错误
    let mut buf = Vec::new();
    if let Err(_) = res.encode(&mut buf)
    {
        return (
            StatusCode::INTERNAL_SERVER_ERROR,
            "Serialization Error"
        ).into_response()         
    }

    // 成功的结果
    (
        StatusCode::OK,
        [("content-type","application/x-protobuf")],
        buf
    ).into_response()
}