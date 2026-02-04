#pragma once

#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QObject>
#include "constants.h"

/// <summary>
/// 26_2_2
/// - 父类
/// - 修正 用二进制流
/// 
/// </summary>
class BaseRequest {
	Q_OBJECT

public:

	virtual ~BaseRequest() = default;

	// 这个要重写
	virtual QString path() const = 0;
	virtual QByteArray body() const = 0;
	//virtual void handleResponse(const QJsonObject& json) = 0;
	virtual void handleResponse(const QByteArray& jsonBytes) = 0;
	virtual void handleError(const QString& error) = 0;

	// 这个默认 看情况
	virtual METHOD method() const {
		return METHOD::Post;
	}

	QNetworkRequest buildRequest(const QString& baseUrl = "127.0.0.1:5000") const {
		QUrl url(baseUrl);

		// 拼上 基础的 然后加上尾巴
		QString basepath = url.path();
		if (!basepath.endsWith('/') && !basepath.startsWith('/'))
		{
			basepath += '/';
		}

		url.setPath(path());
		QNetworkRequest request(url);

		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-protobuf");
		request.setRawHeader("Accept", "application/x-protobuf");

		/*request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
		request.setRawHeader("Accept", "application/json");*/

		return request;
	}
};