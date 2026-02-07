#include "LoginRequest.h"


namespace Net {



    /// <summary>
    /// 26_2_2
    /// 默认构造
    /// </summary>
    /// <param name="email"></param>
    /// <param name="password"></param>
    LoginRequest::LoginRequest(const QString& email, const QString& password)
    {
        LOS_request.set_email(email.toStdString());
        LOS_request.set_password(password.toStdString());
    }



    /// <summary>
    /// 26_2_2
    /// 返回基础路径 
    /// 
    /// 26_2_3 
    /// "/api/auth/login"
    /// 
    /// 
    /// </summary>
    /// <returns></returns>
    QString LoginRequest::path() const
    {
        return "api/auth/login";
    }



    /// <summary>
    /// 请求体
    /// 26_2_3
    /// 修正 seri.data()
    /// 这样不会截断
    /// 
    /// 26_2_4
    /// 减少一次 拷贝的写法
    /// </summary>
    /// <returns></returns>
    QByteArray LoginRequest::body() const
    {
        //std::string seri = LOS_request.SerializeAsString();
        //return QByteArray(seri.c_str(), static_cast<size_t>(seri.size()));

        QByteArray ba;
        size_t size = static_cast<size_t>(LOS_request.ByteSizeLong());
        ba.resize(size);
        LOS_request.SerializeToArray(ba.data(), size);
        return QByteArray(ba.data(), ba.size());
    }



    /// <summary>
    /// 26_2_2
    /// - 处理回复
    /// 
    /// 26_2_3
    /// - 完善代码
    /// - token
    /// {
    /// "code" : 200,
    /// "message" : "登录成功!" // "注册成功"
    /// "data" : {
    ///             "token" : "sda7d901d31hd01yd8shadh1gb",
    ///             "avatar" : "default.png",
    ///             "created_at" : "BJ 26_2_2:21:20",
    ///             "username" : "LosAngelous",
    ///           }
    /// }
    /// 
    /// 26_2_4
    /// 完善好代码
    /// </summary>
    /// <param name="jsonBytes"></param>
    void LoginRequest::handleResponse(const QByteArray& jsonBytes)
    {
        auth_response::AuthResponse authResponse;

        // 传入字符串 和 大小
        if (!authResponse.ParseFromArray(jsonBytes.data(), jsonBytes.size()))
        {
            emit _loginFinished(false, QStringLiteral("reply parsing failed"), UserData());
            return;
        }
        //"code" : 401(密码错误) 404(用户不存在)  500(服务器错误)
        if (authResponse.code() != 200)
        {
            emit _loginFinished(false, QString::fromStdString(authResponse.msg()), UserData());
            return;
        }

        // 200 登录成功
        if (authResponse.has_data())
        {
            UserData data;
            data.formProtoData(authResponse.data());
            emit _loginFinished(true, QString::fromStdString(authResponse.msg()), data);
        }
        else {
            emit _loginFinished(false, QStringLiteral("backend parsing failed"), UserData());
        }
    }


    /// <summary>
    /// 处理业务层的错误
    /// </summary>
    /// <param name="error"></param>
    void LoginRequest::handleError(const QString& error)
    {
        QString msg;
        if (error.contains("refused")) {
            msg = QStringLiteral("failed to connect to the server. Check your network");
        }
        else if (error.contains("timeout")) {
            msg = QStringLiteral("Connection timed out. Please try again later");
        }
        else {
            msg = "netword error:" + error;
        }
        emit _loginFinished(false, msg, UserData());
    }
}
