
#pragma once

#include<QObject>

#include "BaseRequest.h"
#include "auth_request.pb.h"
#include "logger.h"

namespace Net {


class RegisterRequest : public BaseRequest {
	Q_OBJECT

public:
	RegisterRequest(
		const QString& email,
		const QString& password,
		const QString& re_password,
		const qint32 verify_code
	);

	QString path() const override;
	QByteArray body() const override;

	void handleResponse(const QByteArray& jsonBytes) override;
	void handleError(const QString& error) override;

private:

	auth_request::RegisterRequest LOS_request;

signals:
	void _registerFinished(bool isSuc, const QString& message, UserData data);
};


}
