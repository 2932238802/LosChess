#include"LoginDialog/LoginDialog.h"
#include"ui_LoginDialog.h"


/// <summary>
/// 26_2_2
/// 登录对话设置
/// initConnect();
/// initStyle();
/// </summary>
/// <param name="parent"></param>
LoginDialog::LoginDialog(QWidget* parent)
	:
	QDialog(parent),
	ui(new Ui::LoginDialog)
{
	ui->setupUi(this);
	initConnect();
	initStyle();
}



/// <summary>
/// 析构函数
/// </summary>
LoginDialog::~LoginDialog()
{
	delete ui;
}



/// <summary>
/// 登录 按钮的点击
/// </summary>
void LoginDialog::onBtnLoginClicked()
{
	Net::BaseRequest* request = new Net::LoginRequest(
		ui->editEmail->text() ,
		ui->editPassword->text()
	);
	Net::NetManage::getInstance().sendRequest(request);
}


/// <summary>
/// 26_2_7
/// 发送验证码的逻辑
/// </summary>
void LoginDialog::onBtnSendCodeClicked()
{
	LOGD() << u8"发送效验码按钮点击";
	Net::BaseRequest* req = new Net::EmailRequest(
		ui->editRegEmail->text()
	);
	Net::NetManage::getInstance().sendRequest(req);
}



/// <summary>
/// 26_2_7
/// 创造账号的按钮的点击
/// RegisterRequest(
/// const QString& email,
/// const QString& password,
/// const QString& re_password,
/// const qint32 verify_code
/// );
/// </summary>
void LoginDialog::onBtnCreateClicked()
{
	Net::BaseRequest* request = new Net::RegisterRequest(
		ui->editEmail->text(),
		ui->editPassword->text(),
		ui->editRegPassword->text(),
		ui->editVerifyCode->text().toInt()
	);

	Net::NetManage::getInstance().sendRequest(request);
}



/// <summary>
/// 26_2_2
/// 初始化样式
/// </summary>
void LoginDialog::initStyle()
{
	this->setStyleSheet(LoginDialogStyle::style);
}



/// <summary>
/// 26_2_2
/// 初始化链接
/// 
/// 26_2_4
/// 增加点击 登录按钮的逻辑
/// </summary>
void LoginDialog::initConnect()
{
	connect(ui->btnSwitchToRegister, &QPushButton::clicked, this, [this]() {
		ui->stackedWidget->setCurrentIndex(1);
		ui->lblStatus->clear();
		});

	connect(ui->btnBackToLogin, &QPushButton::clicked, this, [this]() {
		ui->stackedWidget->setCurrentIndex(0);
		ui->lblStatus->clear();
	});

	connect(ui->btnLogin, &QPushButton::clicked, this, &LoginDialog::onBtnLoginClicked);
	connect(ui->btnSendCode, &QPushButton::clicked, this, &LoginDialog::onBtnSendCodeClicked);
}

