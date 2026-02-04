#pragma once

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <memory>
#include <QPointer>
#include <QNetworkReply>

#include "BaseRequest.h"


class NetManage : public QObject {
	Q_OBJECT

public:

	static NetManage& getInstance()
	{
		static NetManage manager;
		return manager;
	}


	/// <summary>
	/// 26_2_4
	/// 1. 修正 发送请求的逻辑
	/// </summary>
	/// <param name="req"></param>
	void sendRequest(BaseRequest* req)
	{
		QNetworkRequest nreq;

		nreq.setUrl(req->path());
		nreq.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-protobuf");
		QNetworkReply* reply;

		reply = LOS_net->post(nreq, req->body());

		QPointer<BaseRequest> point(req);

		connect(reply, &QNetworkReply::finished, this, [=]() {

			if (!point)
			{
				reply->deleteLater();
				return;
			}

			if (reply->error() != QNetworkReply::NoError)
			{
				req->handleError(reply->errorString());
			}
			else {
				// 没有问题
				QByteArray resData = reply->readAll();
				req->handleResponse(resData);
			}

			reply->deleteLater();
		});
	}

private:
	NetManage() { LOS_net = std::make_unique<QNetworkAccessManager>(); }
	NetManage(const NetManage&) = delete;
	NetManage(NetManage&&) = delete;
	~NetManage() = default;
	std::unique_ptr<QNetworkAccessManager> LOS_net;
};