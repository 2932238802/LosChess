#include"mainwindow.h"
#include"ui_mainwindow.h"

/// <summary>
/// 26_2_2
/// </summary>
/// <param name="parent">
/// </param>
MainWindow::MainWindow(AuthState* state, QWidget* parent):
	QMainWindow{parent},
	LOS_state(state),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	initStyle();
	initConnect();

	QString saveDir = QCoreApplication::applicationDirPath() + "/image";
	Net::NetManage::getInstance().downloadImage("https://gitee.com/lsjwillwin/sources/raw/master/tx.jpg", saveDir);
}



/// <summary>
/// 26_2_2
/// </summary>
MainWindow::~MainWindow() 
{
	delete ui;
}



/// <summary>
/// 26_2_8
/// 设置全局 属性
/// </summary>
/// 
/// <param name="state">
/// 
/// </param>
void MainWindow::setAuthState(AuthState* state)
{
	if (state) LOS_state = state;
	
}



/// <summary>
/// 26_2_9
/// 设置当前的功能界面
/// </summary>
/// <param name="index"></param>
void MainWindow::setCurrentIndex(int id)
{
	ui->stackedWidget->setCurrentIndex(id);
	if (id == 0)
	{
		ui->lblPageTitle->setText("GAMES LOBBY");
	}
	else if (id == 1)
	{
		ui->lblPageTitle->setText("GAMES TEAM");
	}
	else if (id == 2)
	{
		ui->lblPageTitle->setText("GAMES PROFILE");
	}
	else {
		ui->lblPageTitle->setText("GAMES SETTINGS");
	}
}





/// <summary>
/// 26_2_6
/// - 初始化样式
/// 
/// 26_2_9
/// - 增加 按钮与界面逻辑对应
/// </summary>
void MainWindow::initStyle()
{
	QButtonGroup* qbg = new QButtonGroup(this);
	qbg->addButton(ui->btnLobby, 0);
	qbg->addButton(ui->btnTeam, 1);
	qbg->addButton(ui->btnProfile, 2);
	qbg->addButton(ui->btnSettings,3);
	qbg->setExclusive(true);

	connect(qbg, &QButtonGroup::idClicked, this, [=](int id) {
		setCurrentIndex(id);
	});

	ui->btnLobby->setChecked(true);								// 默认是游戏大厅
	ui->stackedWidget->setCurrentIndex(0);						// 默认是游戏大厅
	setStyleSheet(MainWindowStyle::style);
}



/// <summary>
/// 26_2_10
/// 初始化连接
/// 
/// 26_2_10
/// 下载远程仓库的图片
/// </summary>
void MainWindow::initConnect()
{
	// 下载 远程 仓库
	connect(LOS_state, &AuthState::_avatarUrlChanged, this, [=](const QString& avatar_url) {
		QString saveDir = QCoreApplication::applicationDirPath() + "/image";
		Net::NetManage::getInstance().downloadImage("https://gitee.com/lsjwillwin/sources/raw/master/tx.jpg", saveDir);
	});

	//
	connect(LOS_state, &AuthState::_usernameChanged, this, [=](const QString& user_name) {
		ui->lblUserName->setText(user_name);
	});

	// 图片下载完毕
	connect(&Net::NetManage::getInstance(), &Net::NetManage::_imageDone, this, [=](const QString& path) {
		QPixmap pixmap(path);
		if (!pixmap.isNull())
		{
			ui->lblUserAvatar->setPixmap(pixmap
				.scaled(
					ui->lblUserAvatar->size(),
					Qt::KeepAspectRatio,
					Qt::SmoothTransformation
				)
			);

			LOGD() << "前端渲染成功!";
		}
		else {
			LOGD() << "前端渲染图片失败!";
		}
	});
}
