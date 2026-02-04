
#pragma once

#include<QString>
#include"model/auth_response.pb.h"

/// <summary>
/// 网络传输的方式
/// </summary>
enum class METHOD {
	Get,
	Post,
	Put,
	Delete
};


/// <summary>
/// token token
/// avatar 头像位置
/// username 用户名称
/// </summary>
struct UserData {
	QString token;
	QString avatar;
	QString username;
	
	void formProtoData(const auth_response::userData& data)
	{
		if (data.IsInitialized())
		{
			token = QString::fromStdString(data.token());
			avatar = QString::fromStdString(data.avatar());
			username = QString::fromStdString(data.username());
		}
	}
};
