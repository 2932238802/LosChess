#include"mainwindow.h"
#include"ui_mainwindow.h"

/// <summary>
/// 26_2_2
/// 
/// 
/// </summary>
/// <param name="parent"></param>
MainWindow::MainWindow(QWidget* parent):
	QMainWindow{parent},
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	initStyle();
}

/// <summary>
/// 26_2_2
/// 
/// </summary>
MainWindow::~MainWindow() 
{
	delete ui;
}


/// <summary>
/// 26_2_26
/// - 初始化样式
/// </summary>
void MainWindow::initStyle()
{
	setStyleSheet(MainWindowStyle::style);
}