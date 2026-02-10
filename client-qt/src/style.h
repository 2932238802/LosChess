#pragma once
#include <QString>

namespace MainWindowStyle {
    const QString style = R"(
        QMainWindow, QWidget#centralwidget {
            background-color: #050505;
            color: #FFFFFF;
            font-family: "Microsoft YaHei", "Segoe UI", sans-serif;
        }

        QFrame#sidebar {
            background-color: #0A0A0A;
            border-right: 1px solid #222222;
        }

        QLabel#lblLogo {
            color: #FFFFFF;
            font-size: 22px;
            font-weight: bold;
            letter-spacing: 4px;
            margin-bottom: 20px;
        }

        QPushButton.nav-btn {
            background-color: transparent;
            color: #888888;
            border: none;
            padding: 12px 25px;
            text-align: left;
            font-size: 14px;
            font-weight: bold;
            border-left: 4px solid transparent;
        }

        QPushButton.nav-btn:hover {
            color: #FFFFFF;
            background-color: #151515;
        }

        QPushButton.nav-btn:checked {
            color: #FFFFFF;
            background-color: #1A1A1A;
            border-left: 4px solid #FFFFFF;
        }

        QFrame#header {
            background-color: #0A0A0A;
            border-bottom: 1px solid #222222;
        }

        QLabel#lblPageTitle {
            font-size: 16px;
            letter-spacing: 2px;
            color: #FFFFFF;
            font-weight: bold;
            text-transform: uppercase;
        }

        QLabel#lblUserName {
            font-size: 14px;
            color: #CCCCCC;
            margin-right: 10px;
        }

        QLabel#lblUserAvatar {
            background-color: #222222;
            border: 1px solid #444444;
            border-radius: 20px; /* 对应40x40的一半 */
        }

        /* 滚动区域 */
        QScrollArea {
            border: none;
            background-color: transparent;
        }

        QWidget#scrollAreaWidgetContents {
            background-color: transparent;
        }

        QPushButton {
            background-color: #111111;
            color: #FFFFFF;
            border: 1px solid #333333;
            border-radius: 4px;
            padding: 8px;
            font-size: 14px;
            font-weight: bold;
        }

        QPushButton:hover {
            background-color: #FFFFFF;
            color: #000000;
            border: 1px solid #FFFFFF;
        }

        QPushButton:pressed {
            background-color: #CCCCCC;
        }

        QWidget#hall QPushButton {
            font-size: 18px;
            letter-spacing: 2px;
            border-radius: 8px;
            background-color: #0F0F0F;
        }

        /* 输入组件样式 (ComboBox) */
        QComboBox {
            background-color: #111111;
            border: 1px solid #333333;
            border-radius: 4px;
            padding: 5px 15px;
            color: #FFFFFF;
        }

        QComboBox:hover {
            border: 1px solid #666666;
        }

        QComboBox::drop-down {
            border: none;
        }

        QComboBox QAbstractItemView {
            background-color: #111111;
            border: 1px solid #333333;
            selection-background-color: #333333;
            color: #FFFFFF;
        }

        /* 列表控件样式 (对局历史) */
        QListWidget {
            background-color: #0A0A0A;
            border: 1px solid #222222;
            border-radius: 6px;
            padding: 5px;
            color: #CCCCCC;
        }

        QListWidget::item {
            padding: 10px;
            border-bottom: 1px solid #1A1A1A;
        }

        QListWidget::item:selected {
            background-color: #1A1A1A;
            color: #FFFFFF;
            border-left: 3px solid #FFFFFF;
        }

        /* 个人档案卡片 */
        QFrame#profileHeaderFrame {
            background-color: #0F0F0F;
            border: 1px solid #222222;
            border-radius: 10px;
        }

        /* 设置页单选框 */
        QRadioButton {
            color: #888888;
            spacing: 8px;
        }

        QRadioButton:checked {
            color: #FFFFFF;
            font-weight: bold;
        }

        QRadioButton::indicator {
            width: 16px;
            height: 16px;
            border-radius: 8px;
            border: 2px solid #444444;
        }

        QRadioButton::indicator:checked {
            background-color: #FFFFFF;
            border: 2px solid #FFFFFF;
        }

        /* 分割线 */
        Line {
            background-color: #222222;
        }

        /* 滚动条美化 */
        QScrollBar:vertical {
            background: #050505;
            width: 8px;
            margin: 0px;
        }

        QScrollBar::handle:vertical {
            background: #222222;
            min-height: 20px;
            border-radius: 4px;
        }

        QScrollBar::handle:vertical:hover {
            background: #444444;
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0px;
        }
    )";
}
