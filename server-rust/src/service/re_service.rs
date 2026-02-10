use sqlx::{ SqlitePool, Row };
use bcrypt::{ hash, DEFAULT_COST };

use crate::{ pb::request::RegisterRequest, tool::jwt_tool };

pub struct RegisterData {
    pub username: String,
    pub avatar: String,
    pub token: String,
    pub id: i64,
    pub create_at: String,
}

pub async fn register_service(
    pool: &SqlitePool,
    req: RegisterRequest
) -> Result<RegisterData, u32> {
    if req.email.is_empty() || req.password.is_empty() {
        return Err(400);
    }

    let exists = sqlx
        ::query("SELECT 1 FROM users WHERE email=?1 LIMIT 1")
        .bind(&req.email)
        .fetch_optional(pool).await
        .map_err(|e| {
            eprintln!("数据库查询失败: {e:?}");
            500u32
        })?;

    if exists.is_some() {
        return Err(409);
    }

    let pwd_hash = hash(&req.password, DEFAULT_COST).map_err(|_| 500u32)?;

    let username = req.email.clone();

    let avatar = String::new();
    let role: i32 = 0;

    let row = sqlx
        ::query(
            r#"
    INSERT INTO users (email, password, username, avatar, role, created_at)
    VALUES (?1, ?2, ?3, ?4, ?5, datetime('now','localtime'))
    RETURNING id, created_at
    "#
        )
        .bind(&req.email)
        .bind(&pwd_hash)
        .bind(&username)
        .bind(&avatar)
        .bind(role)
        .fetch_one(pool).await
        .map_err(|e| {
            eprintln!("Failed to insert user: {e:?}");
            500u32
        })?;

    let user_id: i64 = row.get("id");
    let created_at: String = row.get("created_at");


    let token = jwt_tool::create_jwt(&user_id.to_string(), role as u8).map_err(|_| 500u32)?;

    Ok(RegisterData {
        id: user_id,
        username,
        avatar,
        token,
        create_at:created_at
    })
}
