# 棋类自定义框架

https://blog.csdn.net/Shivy_/article/details/121372908



## 项目结构
```tex
BoardGamePlatform/
├── client-qt/				# Qt 前端代码 (C++)
│   ├── src/
│   │   ├── network/       # 网络通信封装 (与 Rust 后端交互)
│   │   ├── ui/            # QML 或 Widgets 界面文件
│   │   ├── models/        # 客户端数据模型
│   │   └── main.cpp
│   ├── resources/          # 图片、音效、QML 资源
│   └── CMakeLists.txt
├── server-rust/            # Rust 后端代码
│   ├── src/
│   │   ├── engine/       # 核心游戏引擎 (各棋类逻辑实现)
│   │   ├── network/      # WebSocket/TCP 处理、会话管理
│   │   ├── room/         # 房间逻辑、匹配、观战逻辑
│   │   └── main.rs
│   └── Cargo.toml
├── common/                # 通用定义
│   ├── protocols/        # 协议定义 (如 .proto 文件)
│   └── assets/           # 公共静态资源
└── docs/                  # 项目文档
```



## protobuf格式


```json
// 登录的请求
{
	"email" : "2932238802@qq.com",
    "password" : 16731726319
}

// 注册的请求
{	
	"email" : "2932238802@qq.com",
    "password" : 12313154151,
    "re_password" : 1318131863619,
    "verify_code" : 2342,
}

// 邮箱验证码
{
	"email" : "2932238802@qq.com"
}


// 登录的答复
{
	"code" : 200,
    "message" : "登录成功!" // "注册成功"
    "data" :{
		"token" : "sda7d901d31hd01yd8shadh1gb",
    	"avatar" : "default.png",
    	"created_at" : "BJ 26_2_2:21:20",
    	"username" : "LosAngelous",
        "role" : 1              // 1就是 管理员 2是普通
    }
}
{
	"code" : 401(密码错误),  400(请求失败), 403(拒绝请求)
    "message" : "",
    "data" : None
}
```











