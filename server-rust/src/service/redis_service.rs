
use redis::AsyncCommands;
use crate::AppState;


/**
 * 26_1_25
 * 存字段
 */
pub async fn save_code_redis(
    state : &AppState,
    email : &str,
    code : i32,
    time : u64
)
    -> Result<(),String>
{
    let mut conn = state
        .redis_pool
        .get()
        .await
        .map_err(|e|{
            e.to_string()
        })?;
    
    let key = format!("code:{}",email);

    let _:() = conn
        .set_ex(key, code, time)
        .await
        .map_err(|e|{
            e.to_string()
        })?;

    Ok(())
}



/**
 * 取 字段
 */
pub async fn get_code_redis(
    state : &AppState,
    email :&str
) -> Option<String>
{
    let mut conn = state.redis_pool
        .get()
        .await
        .ok()?;

    let key = format!("code:{}",email);

    conn
        .get(key)
        .await
        .ok()
}