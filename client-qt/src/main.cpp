#include <QApplication>
#include "mainwindow.h"
#include "ui/LoginDialog/LoginDialog.h"
#include "common/logger.h"

int main(int argc, char* argv[])
{
    std::freopen("app.log", "a", stderr);

    QApplication a(argc, argv);
    Com::init();

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