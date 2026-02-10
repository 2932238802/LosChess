#include <QApplication>
#include "mainwindow.h"
#include "ui/LoginDialog/LoginDialog.h"

#include "common/AuthState.h"
#include "common/logger.h"

int main(int argc, char* argv[])
{
    std::freopen("app.log", "a", stderr);

    QApplication a(argc, argv);
    Com::init();

    AuthState *state = new AuthState(&a);

    LoginDialog login(state);
    int loginResult = login.exec();
    if (loginResult == QDialog::Accepted)
    {
        MainWindow w(state);
        w.show();
        return a.exec();
    }

    return 0;
}