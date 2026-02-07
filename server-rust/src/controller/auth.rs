use axum::{extract::State, http::StatusCode, response::IntoResponse};

use bytes::Bytes;
use prost::Message;                                   // 前端传过来是 二进制

use crate::{
    AppState, 
    pb::
        {
            request::LoginRequest, 
            response::{
                AuthResponse, 
                UserData
                }
        }, 
    service::lo_service
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
            res.message = "登录成功".into();
            res.data = Some(UserData{
                token: data.token,
                username : data.username,
                avatar : data.avatar,
                created_at : "".to_string(),
            });
        }
        Err(code)=>{
            res.code = code as i32;
            res.message = match code {
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
            "编码错误"
        ).into_response()
    };

    (
        StatusCode::OK,
        [("content-type","application/x-protobuf")],
        buf
    ).into_response()

}