#include "RegisterRequest.h"
namespace Net {


    /// <summary>
    /// 26_2_7
    /// 默认构造函数
    /// </summary>
    /// <param name="email">
    /// 
    /// </param>
    /// <param name="password">
    /// 
    /// </param>
    /// <param name="re_password">-
    /// 
    /// 
    /// </param>
    /// <param name="verify_code">
    /// 
    /// </param>
    RegisterRequest::RegisterRequest(const QString& email, const QString& password, const QString& re_password, const qint32 verify_code)
    {
        LOS_request.set_email(email.toStdString());
        LOS_request.set_password(password.toStdString());
        LOS_request.set_re_password(re_password.toStdString());
        LOS_request.set_verify_code(static_cast<int>(verify_code));
    }



    /// <summary>
    /// 26_2_7 
    /// - 创建
    /// - 初始化
    /// </summary>
    /// <returns></returns>
    QString RegisterRequest::path() const
    {
        return "api/auth/register";
    }



    /// <summary>
    /// 26_2_27
    /// 创建 并 定义
    /// </summary>
    /// <returns></returns>
    QByteArray RegisterRequest::body() const
    {
        QByteArray data;
        size_t size_ = static_cast<size_t>(LOS_request.ByteSizeLong());
        data.resize(size_);
        LOS_request.SerializeToArray(data.data(), size_);
        return data;
    }



    /// <summary>
    /// 26_2_27
    /// - 完成初始化
    /// </summary>
    /// <param name="jsonBytes"></param>
    void RegisterRequest::handleResponse(const QByteArray& jsonBytes)
    {
        auth_response::AuthResponse authResponse;

        // 传入字符串 和 大小
        if (!authResponse.ParseFromArray(jsonBytes.data(), jsonBytes.size()))
        {
            emit _registerFinished(false, u8"Parsing response failed", UserData());
            return;
        }
        //"code" : 401(密码错误) 404(用户不存在)  500(服务器错误)
        if (authResponse.code() != 200)
        {
            emit _registerFinished(false, QString::fromStdString(authResponse.msg()), UserData());
            return;
        }

        // 200 注册成功
        if (authResponse.has_data())
        {
            UserData data;
            data.formProtoData(authResponse.data());
            emit _registerFinished(true, u8"Registered!", data);
        }
        else {
            emit _registerFinished(false, u8"Backend parsing failed", UserData());
        }
    }



    /// <summary>
    /// 26_2_7
    /// 完成初始化
    /// </summary>
    /// <param name="error"></param>
    void RegisterRequest::handleError(const QString& error)
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
        emit _registerFinished(false, msg, UserData());
    }
}