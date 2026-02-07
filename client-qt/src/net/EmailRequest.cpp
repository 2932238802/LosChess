#include "EmailRequest.h"
#include"EmailRequest.h"

namespace Net {

    /// <summary>
    /// 26_2_7
    /// 创建并初始化
    /// </summary>
    /// <param name="email"></param>
    EmailRequest::EmailRequest(const QString& email)
    {
        LOS_request.set_email(email.toStdString());
    }


    /// <summary>
    /// 26_2_4
    /// - 创建
    /// </summary>
    /// <returns>
    /// 
    /// </returns>
    QString EmailRequest::path() const
    {
        return "api/auth/email";
    }


    /// <summary>
    /// 26_2_4
    /// - 创建
    /// </summary>
    /// <returns>
    /// 
    /// </returns>
    QByteArray EmailRequest::body() const
    {
        QByteArray ba;
        size_t size = static_cast<size_t>(LOS_request.ByteSizeLong());
        ba.resize(size);
        LOS_request.SerializeToArray(ba.data(), size);
        return QByteArray(ba.data(), ba.size());
    }



    /// <summary>
    /// 26_2_4
    /// - 创建
    /// {
    ///     code: 200,                  // 状态码  200 OK 
    ///     verify_code = 293223        // 验证码
    /// 
    /// }
    /// 
    /// 26_2_7
    /// - 接受 邮件的功能
    /// </summary>
    /// <param name="jsonBytes">
    /// 
    /// </param>
    void EmailRequest::handleResponse(const QByteArray& jsonBytes)
    {
        auth_response::CodeResponse codeResponse;

        if (!codeResponse.ParseFromArray(jsonBytes.data(), jsonBytes.size()))
        {
            emit _emailFinished(false, -1, "Reply parsing failed");
            return;
        }

        if (codeResponse.code() != 200)
        {
            emit _emailFinished(false, -1, QString::fromStdString(codeResponse.msg()));
            return;
        }

        emit _emailFinished(true, codeResponse.code(), QStringLiteral("Verification code sent successfully!"));
    }




    /// <summary>
    /// 26_2_4
    /// - 创建
    /// 
    /// 26_2_7
    /// 完成对函数的定义
    /// </summary>
    /// <param name="error">
    /// 
    /// </param>
    void EmailRequest::handleError(const QString& error)
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
        emit _emailFinished(false, -1, msg);
    }


}