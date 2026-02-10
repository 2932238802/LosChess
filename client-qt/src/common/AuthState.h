#pragma once
#include <QObject>
#include <QString>

/// <summary>
/// 26_2_9
/// - 用户状态更新
/// 
/// 用户状态信息
/// </summary>
class AuthState : public QObject {
    Q_OBJECT
        Q_PROPERTY(bool isLogin READ isLogin NOTIFY _sessionChanged)
        Q_PROPERTY(QString username READ username NOTIFY _usernameChanged)
        Q_PROPERTY(QString avatarUrl READ avatarUrl NOTIFY _avatarUrlChanged)

public:
    explicit AuthState(QObject* parent = nullptr) : QObject(parent) {}
    bool isLogin() const { return !LOS_token.isEmpty(); }
    QString token() const { return LOS_token; }
    QString username() const { return LOS_username; }
    QString avatarUrl() const { return LOS_avatarUrl; }
    QString userId() const { return LOS_userId; }


    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="id"></param>
    /// <param name="token"></param>
    /// <param name="name"></param>
    /// <param name="avatar"></param>
    void login(const QString& id, const QString& token, const QString& name, const QString& avatar) {
        LOS_userId = id;
        LOS_token = token;
        LOS_username = name;
        LOS_avatarUrl = avatar;

        emit _tokenChanged(LOS_token);
        emit _usernameChanged(LOS_username);
        emit _avatarUrlChanged(LOS_avatarUrl);
        emit _sessionChanged();
    }



    /// <summary>
    /// 26_2_10
    /// - 登出
    /// </summary>
    void logout() {
        LOS_userId = "-1";
        LOS_token.clear();
        LOS_username.clear();
        LOS_avatarUrl.clear();
        emit _sessionChanged();
    }


    /// <summary>
    /// 26_2_10
    /// - 设置图片的 url
    /// 设置图片的 Url
    /// </summary>
    /// <param name="url"></param>
    void setAvatarUrl(const QString& url) {
        if (LOS_avatarUrl != url) {
            LOS_avatarUrl = url;
            emit _avatarUrlChanged(url);
        }
    }



    /// <summary>
    /// 26_2_10
    /// 设置图片的 token
    /// </summary>
    /// <param name="token"></param>
    void setToken(const QString& token) {
        if (LOS_token != token) {
            LOS_token = token;
            emit _tokenChanged(token);
            emit _sessionChanged();
        }
    }

private:
    QString LOS_userId = "-1";
    QString LOS_token;
    QString LOS_username;
    QString LOS_avatarUrl;

signals:
    void _sessionChanged();
    void _tokenChanged(const QString& token);
    void _usernameChanged(const QString& name);
    void _avatarUrlChanged(QString url);
};
