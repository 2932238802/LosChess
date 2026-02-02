#include"ui/LoginDialog/LoginDialog.h"
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
	this->setStyleSheet(LoginDialogStyle::style);
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

}



/// <summary>
/// 创造账号的按钮的点击
/// </summary>
void LoginDialog::onBtnCreateClicked()
{
}



/// <summary>
/// 26_2_2
/// 初始化样式
/// </summary>
void LoginDialog::initStyle()
{
}



/// <summary>
/// 26_2_2
/// 初始化链接
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

}

