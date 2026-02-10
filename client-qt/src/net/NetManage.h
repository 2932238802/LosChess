#pragma once

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <memory>
#include <QPointer>
#include <QNetworkReply>
#include <QFile>
#include <QDir>

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

                if (point.isNull()) return;

                QByteArray body = reply->readAll();

                if (reply->error() != QNetworkReply::NoError) {
                    point->handleError(reply->errorString() + " " + QString::fromUtf8(body));
                }
                else {
                    point->handleResponse(body);
                }
                reply->deleteLater();
                point->deleteLater();
            });
        }

        void downloadImage(
            const QString& image_url,
            const QString& image_path
        )
        {
            QDir dir;
            if (!dir.exists(image_path)) {
                dir.mkpath(image_path);
            }

            QUrl url(image_url);
            QString fileName = url.fileName();
            if (fileName.isEmpty()) {
                fileName = "default_avatar.png"; 
            }
            QString fullPath = image_path + "/" + fileName;

            QNetworkRequest request(url);
            request.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0");
            QNetworkReply* reply = LOS_net->get(request);

            connect(reply, &QNetworkReply::finished, this, [=]() {
                if (reply->error() == QNetworkReply::NoError) {
                    QFile file(fullPath);
                    if (file.open(QIODevice::WriteOnly)) {
                        file.write(reply->readAll());
                        file.close();
                        qDebug() << "下载成功，保存至:" << fullPath;
                        emit _imageDone(fullPath);
                    }
                    else {
                        qDebug() << "无法创建文件";
                    }
                }
                else {
                    qDebug() << "下载失败:" << reply->errorString();
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


    signals:
        void _imageDone(const QString& path);
    };
}