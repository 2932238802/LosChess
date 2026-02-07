
use anyhow::Ok;
use jsonwebtoken::encode;
use jsonwebtoken::Header;
use jsonwebtoken::EncodingKey;
use serde::Deserialize;
use serde::Serialize;

use std::time::SystemTime;      // 系统时间
use std::time::UNIX_EPOCH;      // 单元时间

#[derive(Debug,Serialize,Deserialize)]
struct Cliams
{
    pub sub: String,            // 用户 id
    pub exp: usize,             // 过期 时间
    pub iat: usize,             // 
    pub role: u8                // 校色
}

pub fn create_jwt(user_id : &str , role : u8) -> anyhow::Result<String>{

    let now: SystemTime = SystemTime::now();
    let since_epoch = now.duration_since(UNIX_EPOCH)?;

    let two_day: usize = 24 * 60 * 2 * 60 ;
    let all_exp  = two_day + since_epoch.as_secs() as usize;

    let new_claims: Cliams = Cliams { 
        sub: user_id.to_owned(), 
        exp: all_exp, 
        iat: since_epoch.as_secs() as usize, 
        role: role
    };

    let jwt_key = std::env::var("JWT_KEY").unwrap();
    let key = EncodingKey::from_secret(jwt_key.as_bytes());
    
    let token = encode(
        &Header::default(), 
        &new_claims, 
        &key)?;

    Ok(token)
}