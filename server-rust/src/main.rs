use bb8_redis::RedisConnectionManager;
use server_rust::{AppState,Config};
use sqlx::sqlite::SqlitePoolOptions;
use std::{env, sync::Arc};
use dotenvy::dotenv;
use anyhow::Result;

/**
 * 
 * 26_2_4
 * - 创建
 * 
 */
#[tokio::main]
async fn main() -> Result<()>{
    // 获取 根目录下的 .env么?
    // 取出 url
    dotenv().ok();
    let database_url = 
        env::var("DATABASE_URL")
        .expect("在 env 文件里面没有读取到 DATABASE_URL 的数据");

    let redis_url = 
        env::var("REDIS_URL")
        .expect("在 env 文件里面 没有读取到 REDIS_URL 的数据");
    
    // 
    let pool = SqlitePoolOptions::new()
        .max_connections(3)
        .connect(&database_url)
        .await?;

    let redis_manage = RedisConnectionManager::new(redis_url.clone())?;
    let redis_pool = bb8::Pool::builder()
        .max_size(5)
        .build(redis_manage)
        .await?;

    let state = AppState {
        config: Arc::new(Config { 
            db_url: database_url, 
            redis_url : redis_url
        }),
        pool: pool,
        redis_pool: redis_pool,
    };

    server_rust::net::serve::serve(state).await?;
    
    Ok(())
}
