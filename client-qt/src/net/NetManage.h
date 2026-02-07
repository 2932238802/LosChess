#pragma once

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <memory>
#include <QPointer>
#include <QNetworkReply>

#include "BaseRequest.h"


namespace Net {

    /// <summary>
    /// 26_2_7
    /// 网络传输
    /// </summary>
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
        void sendRequest(BaseRequest* req) {
            if (!req) return;

            QNetworkRequest nreq = req->buildRequest();
            QNetworkReply* reply = LOS_net->post(nreq, req->body());
            QPointer<BaseRequest> point(req);

            connect(reply, &QNetworkReply::finished, this, [=]() {
                reply->deleteLater();

                if (point.isNull()) return;

                QByteArray body = reply->readAll();

                if (reply->error() != QNetworkReply::NoError) {
                    point->handleError(QString::fromUtf8(body));
                }
                else {
                    point->handleResponse(reply->readAll());
                }
                point->deleteLater();
                });
        }

    private:
        NetManage() { LOS_net = std::make_unique<QNetworkAccessManager>(); }
        NetManage(const NetManage&) = delete;
        NetManage(NetManage&&) = delete;
        ~NetManage() = default;

        std::unique_ptr<QNetworkAccessManager> LOS_net;
    };
}