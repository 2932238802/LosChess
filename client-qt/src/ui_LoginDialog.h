/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *mainLayout;
    QLabel *label_title;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QVBoxLayout *loginLayout;
    QLabel *label_user_login;
    QLineEdit *editEmail;
    QLabel *label_pwd_login;
    QLineEdit *editPassword;
    QSpacerItem *spacer1;
    QPushButton *btnLogin;
    QPushButton *btnSwitchToRegister;
    QWidget *registerPage;
    QVBoxLayout *registerLayout;
    QLabel *label_user_reg;
    QLineEdit *editRegEmail;
    QWidget *confiemContain;
    QHBoxLayout *horizontalLayout;
    QLineEdit *editVerifyCode;
    QPushButton *btnSendCode;
    QLabel *label_pwd_reg;
    QLineEdit *editRegPassword;
    QLineEdit *editRegConfirm;
    QPushButton *btnExecuteRegister;
    QPushButton *btnBackToLogin;
    QLabel *lblStatus;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(400, 550);
        mainLayout = new QVBoxLayout(LoginDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(40, 40, 40, 40);
        label_title = new QLabel(LoginDialog);
        label_title->setObjectName("label_title");
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(label_title);

        stackedWidget = new QStackedWidget(LoginDialog);
        stackedWidget->setObjectName("stackedWidget");
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        loginLayout = new QVBoxLayout(loginPage);
        loginLayout->setSpacing(10);
        loginLayout->setObjectName("loginLayout");
        loginLayout->setContentsMargins(0, 20, 0, 0);
        label_user_login = new QLabel(loginPage);
        label_user_login->setObjectName("label_user_login");

        loginLayout->addWidget(label_user_login);

        editEmail = new QLineEdit(loginPage);
        editEmail->setObjectName("editEmail");

        loginLayout->addWidget(editEmail);

        label_pwd_login = new QLabel(loginPage);
        label_pwd_login->setObjectName("label_pwd_login");

        loginLayout->addWidget(label_pwd_login);

        editPassword = new QLineEdit(loginPage);
        editPassword->setObjectName("editPassword");
        editPassword->setEchoMode(QLineEdit::EchoMode::Password);

        loginLayout->addWidget(editPassword);

        spacer1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        loginLayout->addItem(spacer1);

        btnLogin = new QPushButton(loginPage);
        btnLogin->setObjectName("btnLogin");

        loginLayout->addWidget(btnLogin);

        btnSwitchToRegister = new QPushButton(loginPage);
        btnSwitchToRegister->setObjectName("btnSwitchToRegister");

        loginLayout->addWidget(btnSwitchToRegister);

        stackedWidget->addWidget(loginPage);
        registerPage = new QWidget();
        registerPage->setObjectName("registerPage");
        registerLayout = new QVBoxLayout(registerPage);
        registerLayout->setSpacing(10);
        registerLayout->setObjectName("registerLayout");
        registerLayout->setContentsMargins(0, 20, 0, 0);
        label_user_reg = new QLabel(registerPage);
        label_user_reg->setObjectName("label_user_reg");

        registerLayout->addWidget(label_user_reg);

        editRegEmail = new QLineEdit(registerPage);
        editRegEmail->setObjectName("editRegEmail");

        registerLayout->addWidget(editRegEmail);

        confiemContain = new QWidget(registerPage);
        confiemContain->setObjectName("confiemContain");
        horizontalLayout = new QHBoxLayout(confiemContain);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        editVerifyCode = new QLineEdit(confiemContain);
        editVerifyCode->setObjectName("editVerifyCode");
        editVerifyCode->setEchoMode(QLineEdit::EchoMode::Normal);

        horizontalLayout->addWidget(editVerifyCode);

        btnSendCode = new QPushButton(confiemContain);
        btnSendCode->setObjectName("btnSendCode");

        horizontalLayout->addWidget(btnSendCode);


        registerLayout->addWidget(confiemContain);

        label_pwd_reg = new QLabel(registerPage);
        label_pwd_reg->setObjectName("label_pwd_reg");

        registerLayout->addWidget(label_pwd_reg);

        editRegPassword = new QLineEdit(registerPage);
        editRegPassword->setObjectName("editRegPassword");
        editRegPassword->setEchoMode(QLineEdit::EchoMode::Password);

        registerLayout->addWidget(editRegPassword);

        editRegConfirm = new QLineEdit(registerPage);
        editRegConfirm->setObjectName("editRegConfirm");
        editRegConfirm->setEchoMode(QLineEdit::EchoMode::Password);

        registerLayout->addWidget(editRegConfirm);

        btnExecuteRegister = new QPushButton(registerPage);
        btnExecuteRegister->setObjectName("btnExecuteRegister");

        registerLayout->addWidget(btnExecuteRegister);

        btnBackToLogin = new QPushButton(registerPage);
        btnBackToLogin->setObjectName("btnBackToLogin");

        registerLayout->addWidget(btnBackToLogin);

        stackedWidget->addWidget(registerPage);

        mainLayout->addWidget(stackedWidget);

        lblStatus = new QLabel(LoginDialog);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(lblStatus);


        retranslateUi(LoginDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        label_title->setText(QCoreApplication::translate("LoginDialog", "BOARD GAME", nullptr));
        label_user_login->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261", nullptr));
        editEmail->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\276\223\345\205\245\351\202\256\347\256\261......", nullptr));
        label_pwd_login->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        editPassword->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\276\223\345\205\245\345\257\206\347\240\201......", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginDialog", "LOGIN", nullptr));
        btnSwitchToRegister->setText(QCoreApplication::translate("LoginDialog", "CREATE ACCOUNT", nullptr));
        label_user_reg->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261", nullptr));
        editRegEmail->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\276\223\345\205\245\351\202\256\347\256\261......", nullptr));
        editVerifyCode->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\276\223\345\205\245\351\202\256\347\256\261\351\252\214\350\257\201\347\240\201......", nullptr));
        btnSendCode->setText(QCoreApplication::translate("LoginDialog", "\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201", nullptr));
        label_pwd_reg->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        editRegPassword->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\276\223\345\205\245\345\257\206\347\240\201......", nullptr));
        editRegConfirm->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201......", nullptr));
        btnExecuteRegister->setText(QCoreApplication::translate("LoginDialog", "REGISTER NOW", nullptr));
        btnBackToLogin->setText(QCoreApplication::translate("LoginDialog", "BACK TO LOGIN", nullptr));
        lblStatus->setText(QString());
        (void)LoginDialog;
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
