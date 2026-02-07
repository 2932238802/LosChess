
use sqlx::{Row, SqlitePool, query};

use bcrypt::verify;
use crate::{pb::{request::LoginRequest, response::UserData}, tool::jwt_tool};


pub struct LoginData{
    pub  id: i64,
    pub username : String,
    pub token: String,
    pub avatar: String
}

pub async fn login_service(
    pool: &SqlitePool,
    req: LoginRequest
) -> Result<LoginData, u32> { 
    let query_result = sqlx::query(
        "SELECT id, password, username, avatar, role FROM users WHERE email=?1"
    )
    .bind(&req.email)
    .fetch_optional(pool)
    .await
    .map_err(|e| {
        println!("数据库查询失败: {:?}", e);
        500u32 
    })?;

    let user = query_result.ok_or(404u32)?; // 如果是 None，直接返回 404

    let db_password: String = user.get("password");
    let is_valid = verify(&req.password, &db_password).map_err(|_| 500u32)?;

    if !is_valid {
        return Err(401); 
    }

    let user_id: i64 = user.get("id");
    let role: i32 = user.get("role");
    let username: String = user.get("username");
    let avatar: String = user.get("avatar");

    let token = jwt_tool::create_jwt(&user_id.to_string(), role as u8)
        .map_err(|_| 500u32)?; 

    Ok(LoginData {
        id: user_id,
        username,
        token,
        avatar,
    })
}
