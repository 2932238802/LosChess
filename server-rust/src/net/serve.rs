use crate::AppState;

use tower_http::cors::{Any, CorsLayer}; // 跨域传送
use std::net::{Ipv4Addr, SocketAddr};
use anyhow::Ok;
use tokio::net::TcpListener;
use axum::routing::post;
use axum::Router;

use crate::
    {
        controller::auth::
        {
            lo_controller,
            em_controller,
            re_controller
        },
    };

/**
 * 注册路由
 */
pub async  fn api_router(ctx:AppState) -> Router
{
    Router::new()
        .route("/api/auth/login", post(lo_controller))
        .route("/api/auth/email", post(em_controller))
        .route("/api/auth/register", post(re_controller))
        .layer( CorsLayer::new()
                .allow_origin(Any)
                .allow_methods(Any)
                .allow_headers(Any)
            )
        .with_state(ctx)
}


/**
 * 26_2_4
 * 创建基本的路由
 */
pub async fn serve(ctx: AppState) -> anyhow::Result<()>{
    let api_router_init = api_router(ctx).await;                                        // 路由
    // UNSPECIFIED 0.0.0.0
    let addr = SocketAddr::from((Ipv4Addr::UNSPECIFIED,3000));              // 端口号
    let listener = TcpListener::bind(addr).await?;                                      // 倾听
    axum::serve(listener,api_router_init).await?;
    Ok(())
}
