#pragma once
#include <QString>

namespace LoginDialogStyle {
    const QString style = R"(
        QDialog {
            background-color: #000000;
        }

        QWidget#loginPage, QWidget#registerPage {
            background-color: transparent;
        }

        QLabel#label_title {
            color: #FFFFFF;
            font-size: 28px;
            font-family: "Segoe UI Semibold", "Microsoft YaHei";
            letter-spacing: 2px;
            margin-bottom: 10px;
        }

        QLabel {
            color: #666666;
            font-size: 11px;
            font-weight: bold;
            text-transform: uppercase;
        }

        QLineEdit {
            background-color: #111111;
            border: 1px solid #222222;
            border-radius: 0px;
            color: #FFFFFF;
            padding: 10px;
            font-size: 14px;
            margin-bottom: 5px;
        }

        QLineEdit:focus {
            border: 1px solid #FFFFFF;
            background-color: #151515;
        }

        QPushButton#btnLogin, QPushButton#btnExecuteRegister {
            background-color: #FFFFFF;
            color: #000000;
            border: none;
            border-radius: 0px;
            padding: 12px;
            font-weight: bold;
            font-size: 13px;
            margin-top: 10px;
        }

        QPushButton#btnLogin:hover, QPushButton#btnExecuteRegister:hover {
            background-color: #CCCCCC;
        }

        QPushButton#btnSwitchToRegister, QPushButton#btnBackToLogin {
            background-color: transparent;
            color: #888888;
            border: 1px solid #333333;
            border-radius: 0px;
            padding: 10px;
            font-size: 12px;
            margin-top: 5px;
        }

        QPushButton#btnSwitchToRegister:hover, QPushButton#btnBackToLogin:hover {
            color: #FFFFFF;
            border: 1px solid #FFFFFF;
        }

        QLabel#lblStatus {
            color: #AAAAAA;
            font-size: 11px;
        }

        QStackedWidget {
            background-color: transparent;
        }
    )";
}
