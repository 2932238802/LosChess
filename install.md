# 棋类自定义框架

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