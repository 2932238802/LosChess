
#pragma once
#include<QObject>
#include"BaseRequest.h"
#include"model/auth_request.pb.h"


namespace Net {

	/// <summary>
	/// 26_2_27
	/// 创建并 初始化
	/// </summary>
	class EmailRequest : public BaseRequest
	{
		Q_OBJECT
	public:

		EmailRequest(const QString& email);


		QString path() const override;
		QByteArray body() const override;
		void handleResponse(const QByteArray& jsonBytes) override;
		void handleError(const QString& error) override;

	private:
		auth_request::EmailCodeRequest LOS_request;


	signals:
		void _emailFinished(bool is_suc, qint32 verify_code, const QString& message);
	};

}