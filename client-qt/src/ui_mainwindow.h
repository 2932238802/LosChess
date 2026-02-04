/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QFrame *sidebar;
    QVBoxLayout *verticalLayout_sidebar;
    QLabel *lblLogo;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnLobby;
    QPushButton *btnTeam;
    QPushButton *btnProfile;
    QPushButton *btnSettings;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_content;
    QFrame *header;
    QHBoxLayout *horizontalLayout_header;
    QLabel *lblPageTitle;
    QSpacerItem *horizontalSpacer;
    QLabel *lblUserName;
    QLabel *lblUserAvatar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gameLayout;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 750);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setSpacing(0);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        horizontalLayout_main->setContentsMargins(0, 0, 0, 0);
        sidebar = new QFrame(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setMinimumSize(QSize(220, 0));
        sidebar->setMaximumSize(QSize(220, 16777215));
        sidebar->setFrameShape(QFrame::NoFrame);
        verticalLayout_sidebar = new QVBoxLayout(sidebar);
        verticalLayout_sidebar->setSpacing(5);
        verticalLayout_sidebar->setObjectName("verticalLayout_sidebar");
        verticalLayout_sidebar->setContentsMargins(0, 40, 0, -1);
        lblLogo = new QLabel(sidebar);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setMinimumSize(QSize(0, 60));
        lblLogo->setAlignment(Qt::AlignCenter);
        lblLogo->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: white; letter-spacing: 2px;"));

        verticalLayout_sidebar->addWidget(lblLogo);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_sidebar->addItem(verticalSpacer_3);

        btnLobby = new QPushButton(sidebar);
        btnLobby->setObjectName("btnLobby");
        btnLobby->setCheckable(true);
        btnLobby->setChecked(true);

        verticalLayout_sidebar->addWidget(btnLobby);

        btnTeam = new QPushButton(sidebar);
        btnTeam->setObjectName("btnTeam");
        btnTeam->setCheckable(true);

        verticalLayout_sidebar->addWidget(btnTeam);

        btnProfile = new QPushButton(sidebar);
        btnProfile->setObjectName("btnProfile");
        btnProfile->setCheckable(true);

        verticalLayout_sidebar->addWidget(btnProfile);

        btnSettings = new QPushButton(sidebar);
        btnSettings->setObjectName("btnSettings");
        btnSettings->setCheckable(true);

        verticalLayout_sidebar->addWidget(btnSettings);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_sidebar->addItem(verticalSpacer);


        horizontalLayout_main->addWidget(sidebar);

        verticalLayout_content = new QVBoxLayout();
        verticalLayout_content->setSpacing(0);
        verticalLayout_content->setObjectName("verticalLayout_content");
        header = new QFrame(centralwidget);
        header->setObjectName("header");
        header->setMinimumSize(QSize(0, 80));
        horizontalLayout_header = new QHBoxLayout(header);
        horizontalLayout_header->setObjectName("horizontalLayout_header");
        horizontalLayout_header->setContentsMargins(30, -1, 30, -1);
        lblPageTitle = new QLabel(header);
        lblPageTitle->setObjectName("lblPageTitle");
        lblPageTitle->setStyleSheet(QString::fromUtf8("font-size: 18px; color: #555; font-weight: bold;"));

        horizontalLayout_header->addWidget(lblPageTitle);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_header->addItem(horizontalSpacer);

        lblUserName = new QLabel(header);
        lblUserName->setObjectName("lblUserName");
        lblUserName->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

        horizontalLayout_header->addWidget(lblUserName);

        lblUserAvatar = new QLabel(header);
        lblUserAvatar->setObjectName("lblUserAvatar");
        lblUserAvatar->setMinimumSize(QSize(40, 40));
        lblUserAvatar->setMaximumSize(QSize(40, 40));

        horizontalLayout_header->addWidget(lblUserAvatar);


        verticalLayout_content->addWidget(header);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(30, 30, 30, 30);
        gameLayout = new QGridLayout();
        gameLayout->setObjectName("gameLayout");
        gameLayout->setHorizontalSpacing(20);
        gameLayout->setVerticalSpacing(20);

        verticalLayout_2->addLayout(gameLayout);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_content->addWidget(scrollArea);


        horizontalLayout_main->addLayout(verticalLayout_content);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BOARD GAME PLATFORM - \346\243\213\347\261\273\345\257\271\345\274\210\345\271\263\345\217\260", nullptr));
        lblLogo->setText(QCoreApplication::translate("MainWindow", "LOS CHESS", nullptr));
        btnLobby->setText(QCoreApplication::translate("MainWindow", "  \346\270\270\346\210\217\345\244\247\345\216\205", nullptr));
        btnLobby->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "nav-btn", nullptr)));
        btnTeam->setText(QCoreApplication::translate("MainWindow", "  \345\244\232\344\272\272\347\273\204\351\230\237", nullptr));
        btnTeam->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "nav-btn", nullptr)));
        btnProfile->setText(QCoreApplication::translate("MainWindow", "  \344\270\252\344\272\272\346\241\243\346\241\210", nullptr));
        btnProfile->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "nav-btn", nullptr)));
        btnSettings->setText(QCoreApplication::translate("MainWindow", "  \347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnSettings->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "nav-btn", nullptr)));
        lblPageTitle->setText(QCoreApplication::translate("MainWindow", "GAMES LOBBY", nullptr));
        lblUserName->setText(QCoreApplication::translate("MainWindow", "Player_Guest", nullptr));
        lblUserAvatar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
