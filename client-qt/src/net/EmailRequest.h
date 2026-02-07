
#pragma once
#include<QObject>
#include"BaseRequest.h"
#include"model/auth_request.pb.h"

class EmailRequest : public BaseRequest
{
	Q_OBJECT
public:
	 QString path() const override;
	 QByteArray body() const override;
	 void handleResponse(const QByteArray& jsonBytes) override;
	 void handleError(const QString& error) override;

private:
	auth_request::EmailCodeRequest request;
};