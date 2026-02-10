#pragma once
#include<QDialog>
#include<QWidget>
#include<QObject>
#include<QMainWindow>
#include<QButtonGroup>

#include"style.h"
#include"common/AuthState.h"
#include"common/logger.h"
#include"net/NetManage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE



/// <summary>
/// 26_2_8
/// - 主要界面
/// </summary>
class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(AuthState* state, QWidget* parent = nullptr);
	~MainWindow();

	void setAuthState(AuthState* state);
	void setCurrentIndex(int index);					// 设置当前界面
private:
	void initStyle();
	void initConnect();									// 初始化连接

private:
	Ui::MainWindow* ui;
	AuthState* LOS_state;
};