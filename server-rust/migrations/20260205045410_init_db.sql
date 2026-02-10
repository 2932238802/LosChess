-- Add migration script here

CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    email TEXT NOT NULL UNIQUE,        
    password TEXT NOT NULL,                
    username TEXT,                              
    avatar TEXT DEFAULT 'default.png',     
    role INT DEFAULT 0,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO users (email, password, username, role) 
VALUES ('test@qq.com', '$2b$10$EixZ9dyJ9GsS6fKN5x.Cnu26798Jj89T95C6X.I6t6Q753uOnd7Ge', 'LosAngelous', 1);


