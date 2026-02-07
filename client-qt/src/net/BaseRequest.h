#pragma once

#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QObject>

#include "constants.h"


namespace Net {

	/// <summary>
	/// 26_2_2
	/// - 父类
	/// - 修正 用二进制流
	/// 
	/// </summary>
	class BaseRequest : public QObject {
		Q_OBJECT

	public:
		explicit BaseRequest(QObject* parent = nullptr) : QObject(parent) {}
		virtual ~BaseRequest() = default;

		// 这个要重写
		// 虚表指针 + 虚表
		virtual QString path() const = 0;
		virtual QByteArray body() const = 0;
		//virtual void handleResponse(const QJsonObject& json) = 0;
		virtual void handleResponse(const QByteArray& jsonBytes) = 0;
		virtual void handleError(const QString& error) = 0;

		// 这个默认 看情况
		virtual METHOD method() const {
			return METHOD::Post;
		}


		/// <summary>
		/// 26_2_4
		/// 创建基础的请求
		/// </summary>
		/// <returns></returns>
		QNetworkRequest buildRequest() const {
			QUrl url(BASE_URL);

			// 拼上 基础的 然后加上尾巴
			QString basepath = url.path();
			if (!basepath.endsWith('/') && !basepath.startsWith('/'))
			{
				basepath += '/';
			}

			url.setPath(basepath + path());
			QNetworkRequest request(url);

			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-protobuf");
			request.setRawHeader("Accept", "application/x-protobuf");

			/*request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
			request.setRawHeader("Accept", "application/json");*/

			return request;
		}
	};

}