#pragma once
#include <QObject>
#include <QString>
#include <string>

#include "net/BaseRequest.h"
#include "auth_request.pb.h"
#include "auth_response.pb.h"
#include "constants.h"



namespace Net {



	/// <summary>
	/// 26_2_2
	/// 登录的请求
	/// 
	/// 26_2_4
	/// 更新登录 成功的信号
	/// </summary>
	class LoginRequest : public BaseRequest {
		Q_OBJECT

	public:

		LoginRequest(const QString& email, const QString& password);

		QString path() const override;
		QByteArray body() const override;

		void handleResponse(const QByteArray& jsonBytes) override;
		void handleError(const QString& error) override;

	private:
		auth_request::LoginRequest LOS_request;

	signals:
		//void _loginFailed(QString msg);
		//void _loginSuc(const QString& messag e,UserData data);
		void _loginFinished(bool isSuc, const QString& message, UserData data);
	};


}