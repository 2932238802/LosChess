
pub mod net;
pub mod controller;
pub mod tool;
pub mod service;

use std::sync::Arc;
use sqlx::SqlitePool;

use bb8_redis::RedisConnectionManager;
use bb8::Pool;

/**
 * 26_2_4
 * - 读取 指定 proto文件
 * -
 */
pub mod pb {
    pub mod request {
        include!(concat!(env!("OUT_DIR"), "/auth_request.rs"));
    }
    pub mod response {
        include!(concat!(env!("OUT_DIR"), "/auth_response.rs"));
    }
}

#[derive(Clone)]
pub struct Config{
    pub db_url: String,
    pub redis_url: String
}

/**
 * 26_2_6
 * 1. 数据库 redis + 数据库的路径
 */
#[derive(Clone)]
pub struct AppState{
    pub config : Arc<Config>,
    pub pool : SqlitePool,
    pub redis_pool: Pool<RedisConnectionManager>
}