#include"LoginDialog/LoginDialog.h"
#include"ui_LoginDialog.h"



/// <summary>
/// 26_2_2
/// 登录对话设置
/// initConnect();
/// initStyle();
/// </summary>
/// <param name="parent"></param>
LoginDialog::LoginDialog(AuthState* state, QWidget* parent)
	:
	LOS_state(state),
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
/// 26_2_10
/// - 登录 按钮的点击
/// </summary>
void LoginDialog::onBtnLoginClicked()
{
	auto request = new Net::LoginRequest(
		ui->editEmail->text() ,
		ui->editPassword->text()
	);
	Net::NetManage::getInstance().sendRequest(request);

	connect(request, &Net::LoginRequest::_loginFinished, this,
	[=](bool isSuc, const QString& message, UserData data) {
			if (isSuc)
			{
				QMessageBox::information(this, QStringLiteral("Suc"), QStringLiteral("successful!"));
				//int id, const QString& token, const QString& name, const QString& avatar
				LOS_state->login(
					data.user_id,
					data.token,
					data.username,
					data.avatar
				);
				accept();
			}
			else {
				QMessageBox::warning(this, QStringLiteral("failed"), message);
			}

			request->deleteLater();
	});
}



/// <summary>
/// 26_2_7
/// - 发送验证码的逻辑
/// 
/// 26_2_8
/// - 完善接受显示逻辑
/// - 接收到验证码 直接 放到 显示上
/// </summary>
void LoginDialog::onBtnSendCodeClicked()
{
	LOGD() << "1: " << ui->editRegEmail->text();

	auto req = new Net::EmailRequest(
		ui->editRegEmail->text()
	);

	connect(req, &Net::EmailRequest::_emailFinished, this,
	[=](bool is_suc, qint32 verify_code, const QString& message) {
			if (is_suc)
			{
				QMessageBox::information(this, QStringLiteral("prompt"), QStringLiteral("Verification code has been sent, please check your email"));
				//ui->editVerifyCode->setText(QString::number(verify_code));
			}
			else {
				QMessageBox::warning(this, QStringLiteral("Send failed"), message);
			}
			req->deleteLater();
	});

	Net::NetManage::getInstance().sendRequest(req);
}



/// <summary>
/// 26_2_8
/// - 登录按钮的点击的逻辑
/// 
/// 26_2_10
/// - 增加打印回复信息的逻辑
/// </summary>
void LoginDialog::onBtnExecuteRegister()
{
	Net::RegisterRequest* request = new Net::RegisterRequest(
		ui->editRegEmail->text(),
		ui->editRegPassword->text(),
		ui->editRegPassword->text(),
		ui->editVerifyCode->text().toInt()
	);

	Net::NetManage::getInstance().sendRequest(request);
	connect(request, &Net::RegisterRequest::_registerFinished, this,
	[=](bool isSuc, const QString& message, UserData data) {
		//ui->lblStatus->setText(message);

		LOGD() << message;

		if (isSuc) {
			accept();
			return;
		}
		QMessageBox::warning(this, tr("Register failed"), message);

		request->deleteLater();
	});
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
	connect(ui->btnExecuteRegister, &QPushButton::clicked, this, &LoginDialog::onBtnExecuteRegister);
}
