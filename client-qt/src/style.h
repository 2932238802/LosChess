#pragma once
#include <QString>

namespace MainWindowStyle {
    const QString style = R"(
        QMainWindow, QWidget#centralwidget {
            background-color: #050505;
            color: #FFFFFF;
        }

        QFrame#sidebar {
            background-color: #0A0A0A;
            border-right: 1px solid #222222;
            min-width: 200px;
        }

        QPushButton.nav-btn {
            background-color: transparent;
            color: #888888;
            border: none;
            padding: 15px;
            text-align: left;
            font-size: 15px;
            font-weight: bold;
            border-left: 3px solid transparent;
        }

        QPushButton.nav-btn:hover {
            color: #FFFFFF;
            background-color: #111111;
        }

        QPushButton.nav-btn:checked {
            color: #FFFFFF;
            background-color: #1A1A1A;
            border-left: 3px solid #FFFFFF;
        }

        QFrame#header {
            background-color: #0A0A0A;
            border-bottom: 1px solid #222222;
            min-height: 80px;
        }

        QLabel#lblUserAvatar {
            background-color: #FFFFFF;
            border-radius: 25px;
            min-width: 50px;
            min-height: 50px;
        }

        QLabel#lblUserName {
            font-size: 18px;
            font-weight: bold;
            color: #FFFFFF;
        }

        QScrollArea {
            border: none;
            background-color: transparent;
        }

        QFrame#gameCard {
            background-color: #0F0F0F;
            border: 1px solid #222222;
            border-radius: 8px;
            min-width: 200px;
            min-height: 280px;
        }

        QFrame#gameCard:hover {
            border: 1px solid #FFFFFF;
            background-color: #151515;
        }

        QLabel#gameTitle {
            font-size: 20px;
            font-weight: bold;
            margin-top: 10px;
        }

        QPushButton#btnAction {
            background-color: #FFFFFF;
            color: #000000;
            border-radius: 4px;
            padding: 8px 20px;
            font-weight: bold;
        }

        QPushButton#btnAction:hover {
            background-color: #CCCCCC;
        }
    )";
}

