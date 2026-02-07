#pragma once
#include<QDialog>
#include<QWidget>

#include"net/LoginRequest.h"
#include"LoginDialog/LoginDialog_style.h"
#include"net/NetManage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class LoginDialog;
}
QT_END_NAMESPACE

class LoginDialog : public QDialog{
	Q_OBJECT

public:
	LoginDialog(QWidget* parent = nullptr);
	~LoginDialog();

private slots:
	void onBtnLoginClicked();
	void onBtnCreateClicked();

private:
	void initStyle();
	void initConnect();

private:
	Ui::LoginDialog* ui;
};