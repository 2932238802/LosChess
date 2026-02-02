#include <QApplication>
#include "mainwindow.h"
#include "ui/LoginDialog/LoginDialog.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    LoginDialog login;
    int loginResult = login.exec();
    if (loginResult == QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }

    return 0;
}