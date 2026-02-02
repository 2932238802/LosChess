#pragma once
#include<QDialog>
#include<QWidget>
#include<QObject>
#include<QMainWindow>
#include"style.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private:
	void initStyle();

private:
	Ui::MainWindow* ui;
};