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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
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
    QStackedWidget *stackedWidget;
    QWidget *hall;
    QGridLayout *gridLayout_hall;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QWidget *multiple;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_4;
    QWidget *personal;
    QVBoxLayout *verticalLayout_4;
    QFrame *profileHeaderFrame;
    QHBoxLayout *horizontalLayout_profile;
    QLabel *lblPersonalAvatar;
    QVBoxLayout *verticalLayout_info;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_6;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblHistory;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_2;
    QListWidget *listWidget;
    QWidget *settings;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QHBoxLayout *hLayout_1;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *hSpacer_1;
    QLabel *label_5;
    QHBoxLayout *hLayout_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QSpacerItem *hSpacer_2;
    QLabel *label_6;
    QHBoxLayout *hLayout_3;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QSpacerItem *hSpacer_3;
    QLabel *label_7;
    QHBoxLayout *hLayout_4;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QSpacerItem *hSpacer_4;
    QSpacerItem *vSpacer_settings;
    QPushButton *pushButton_7;
    QPushButton *btnLogout;
    QButtonGroup *groupMusic;
    QButtonGroup *groupSound;
    QButtonGroup *groupTheme;
    QButtonGroup *groupLanguage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 759);
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
        sidebar->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayout_sidebar = new QVBoxLayout(sidebar);
        verticalLayout_sidebar->setSpacing(8);
        verticalLayout_sidebar->setObjectName("verticalLayout_sidebar");
        verticalLayout_sidebar->setContentsMargins(15, 40, 15, 20);
        lblLogo = new QLabel(sidebar);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setMinimumSize(QSize(0, 60));
        lblLogo->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: white; letter-spacing: 2px;"));
        lblLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_sidebar->addWidget(lblLogo);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_sidebar->addItem(verticalSpacer_3);

        btnLobby = new QPushButton(sidebar);
        btnLobby->setObjectName("btnLobby");
        btnLobby->setMinimumSize(QSize(0, 45));
        btnLobby->setCheckable(true);
        btnLobby->setChecked(true);

        verticalLayout_sidebar->addWidget(btnLobby);

        btnTeam = new QPushButton(sidebar);
        btnTeam->setObjectName("btnTeam");
        btnTeam->setMinimumSize(QSize(0, 45));
        btnTeam->setCheckable(true);

        verticalLayout_sidebar->addWidget(btnTeam);

        btnProfile = new QPushButton(sidebar);
        btnProfile->setObjectName("btnProfile");
        btnProfile->setMinimumSize(QSize(0, 45));
        btnProfile->setCheckable(true);

        verticalLayout_sidebar->addWidget(btnProfile);

        btnSettings = new QPushButton(sidebar);
        btnSettings->setObjectName("btnSettings");
        btnSettings->setMinimumSize(QSize(0, 45));
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
        lblUserName->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_header->addWidget(lblUserName);

        lblUserAvatar = new QLabel(header);
        lblUserAvatar->setObjectName("lblUserAvatar");
        lblUserAvatar->setMinimumSize(QSize(40, 40));
        lblUserAvatar->setMaximumSize(QSize(40, 40));

        horizontalLayout_header->addWidget(lblUserAvatar);


        verticalLayout_content->addWidget(header);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 878, 677));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(30, 20, 30, 30);
        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName("stackedWidget");
        hall = new QWidget();
        hall->setObjectName("hall");
        gridLayout_hall = new QGridLayout(hall);
        gridLayout_hall->setSpacing(25);
        gridLayout_hall->setObjectName("gridLayout_hall");
        gridLayout_hall->setContentsMargins(50, 50, 50, 50);
        pushButton = new QPushButton(hall);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 120));

        gridLayout_hall->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(hall);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 120));

        gridLayout_hall->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(hall);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(0, 120));

        gridLayout_hall->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(hall);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 120));

        gridLayout_hall->addWidget(pushButton_2, 1, 1, 1, 1);

        stackedWidget->addWidget(hall);
        multiple = new QWidget();
        multiple->setObjectName("multiple");
        verticalLayout_3 = new QVBoxLayout(multiple);
        verticalLayout_3->setSpacing(25);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(150, 80, 150, 80);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        comboBox = new QComboBox(multiple);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(comboBox);

        label = new QLabel(multiple);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label);

        pushButton_5 = new QPushButton(multiple);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(0, 60));

        verticalLayout_3->addWidget(pushButton_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        stackedWidget->addWidget(multiple);
        personal = new QWidget();
        personal->setObjectName("personal");
        verticalLayout_4 = new QVBoxLayout(personal);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(20, 20, 20, 20);
        profileHeaderFrame = new QFrame(personal);
        profileHeaderFrame->setObjectName("profileHeaderFrame");
        profileHeaderFrame->setMinimumSize(QSize(0, 100));
        profileHeaderFrame->setFrameShape(QFrame::Shape::StyledPanel);
        profileHeaderFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_profile = new QHBoxLayout(profileHeaderFrame);
        horizontalLayout_profile->setSpacing(20);
        horizontalLayout_profile->setObjectName("horizontalLayout_profile");
        lblPersonalAvatar = new QLabel(profileHeaderFrame);
        lblPersonalAvatar->setObjectName("lblPersonalAvatar");
        lblPersonalAvatar->setMinimumSize(QSize(80, 80));
        lblPersonalAvatar->setMaximumSize(QSize(80, 80));
        lblPersonalAvatar->setStyleSheet(QString::fromUtf8("background-color: #ddd; border-radius: 40px;"));

        horizontalLayout_profile->addWidget(lblPersonalAvatar);

        verticalLayout_info = new QVBoxLayout();
        verticalLayout_info->setObjectName("verticalLayout_info");
        label_2 = new QLabel(profileHeaderFrame);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold;"));

        verticalLayout_info->addWidget(label_2);

        label_3 = new QLabel(profileHeaderFrame);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: #777;"));

        verticalLayout_info->addWidget(label_3);


        horizontalLayout_profile->addLayout(verticalLayout_info);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_profile->addItem(horizontalSpacer_2);

        pushButton_6 = new QPushButton(profileHeaderFrame);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(100, 35));

        horizontalLayout_profile->addWidget(pushButton_6);


        verticalLayout_4->addWidget(profileHeaderFrame);

        line = new QFrame(personal);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblHistory = new QLabel(personal);
        lblHistory->setObjectName("lblHistory");
        lblHistory->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        horizontalLayout_2->addWidget(lblHistory);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        comboBox_2 = new QComboBox(personal);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(personal);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("background: white; border-radius: 10px; border: 1px solid #eee;"));

        verticalLayout_4->addWidget(listWidget);

        stackedWidget->addWidget(personal);
        settings = new QWidget();
        settings->setObjectName("settings");
        verticalLayout_5 = new QVBoxLayout(settings);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(60, 40, 60, 40);
        label_4 = new QLabel(settings);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        verticalLayout_5->addWidget(label_4);

        hLayout_1 = new QHBoxLayout();
        hLayout_1->setObjectName("hLayout_1");
        radioButton = new QRadioButton(settings);
        groupMusic = new QButtonGroup(MainWindow);
        groupMusic->setObjectName("groupMusic");
        groupMusic->addButton(radioButton);
        radioButton->setObjectName("radioButton");
        radioButton->setChecked(true);

        hLayout_1->addWidget(radioButton);

        radioButton_2 = new QRadioButton(settings);
        groupMusic->addButton(radioButton_2);
        radioButton_2->setObjectName("radioButton_2");

        hLayout_1->addWidget(radioButton_2);

        hSpacer_1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayout_1->addItem(hSpacer_1);


        verticalLayout_5->addLayout(hLayout_1);

        label_5 = new QLabel(settings);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        verticalLayout_5->addWidget(label_5);

        hLayout_2 = new QHBoxLayout();
        hLayout_2->setObjectName("hLayout_2");
        radioButton_3 = new QRadioButton(settings);
        groupSound = new QButtonGroup(MainWindow);
        groupSound->setObjectName("groupSound");
        groupSound->addButton(radioButton_3);
        radioButton_3->setObjectName("radioButton_3");

        hLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(settings);
        groupSound->addButton(radioButton_4);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setChecked(true);

        hLayout_2->addWidget(radioButton_4);

        hSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayout_2->addItem(hSpacer_2);


        verticalLayout_5->addLayout(hLayout_2);

        label_6 = new QLabel(settings);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        verticalLayout_5->addWidget(label_6);

        hLayout_3 = new QHBoxLayout();
        hLayout_3->setObjectName("hLayout_3");
        radioButton_7 = new QRadioButton(settings);
        groupTheme = new QButtonGroup(MainWindow);
        groupTheme->setObjectName("groupTheme");
        groupTheme->addButton(radioButton_7);
        radioButton_7->setObjectName("radioButton_7");
        radioButton_7->setChecked(true);

        hLayout_3->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(settings);
        groupTheme->addButton(radioButton_8);
        radioButton_8->setObjectName("radioButton_8");

        hLayout_3->addWidget(radioButton_8);

        hSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayout_3->addItem(hSpacer_3);


        verticalLayout_5->addLayout(hLayout_3);

        label_7 = new QLabel(settings);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        verticalLayout_5->addWidget(label_7);

        hLayout_4 = new QHBoxLayout();
        hLayout_4->setObjectName("hLayout_4");
        radioButton_9 = new QRadioButton(settings);
        groupLanguage = new QButtonGroup(MainWindow);
        groupLanguage->setObjectName("groupLanguage");
        groupLanguage->addButton(radioButton_9);
        radioButton_9->setObjectName("radioButton_9");
        radioButton_9->setChecked(true);

        hLayout_4->addWidget(radioButton_9);

        radioButton_10 = new QRadioButton(settings);
        groupLanguage->addButton(radioButton_10);
        radioButton_10->setObjectName("radioButton_10");

        hLayout_4->addWidget(radioButton_10);

        hSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayout_4->addItem(hSpacer_4);


        verticalLayout_5->addLayout(hLayout_4);

        vSpacer_settings = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(vSpacer_settings);

        pushButton_7 = new QPushButton(settings);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(0, 45));

        verticalLayout_5->addWidget(pushButton_7);

        btnLogout = new QPushButton(settings);
        btnLogout->setObjectName("btnLogout");
        btnLogout->setMinimumSize(QSize(0, 40));
        btnLogout->setStyleSheet(QString::fromUtf8("\n"
"																		QPushButton#btnLogout {\n"
"																		background-color: #331111;\n"
"																		color: #ff4444;\n"
"																		border: 1px solid #552222;\n"
"																		}\n"
"																		QPushButton#btnLogout:hover {\n"
"																		background-color: #aa0000;\n"
"																		color: white;\n"
"																		}\n"
"																	"));

        verticalLayout_5->addWidget(btnLogout);

        stackedWidget->addWidget(settings);

        verticalLayout_2->addWidget(stackedWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_content->addWidget(scrollArea);


        horizontalLayout_main->addLayout(verticalLayout_content);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LosChess", nullptr));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\255\345\233\275\350\261\241\346\243\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213(\344\272\272\346\234\272)", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\233\275\351\231\205\350\261\241\346\243\213(\344\272\272\346\234\272)", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\234\250\347\272\277\350\201\224\346\234\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\344\270\255\345\233\275\350\261\241\346\243\213", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\233\275\351\231\205\350\261\241\346\243\213", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\256\265\344\275\215\347\247\257\345\210\206: 0", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\345\274\200 \345\247\213 \345\214\271 \351\205\215", nullptr));
        lblPersonalAvatar->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "LosAngelous", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "2932238802@qq.com", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\350\265\204\346\226\231", nullptr));
        lblHistory->setText(QCoreApplication::translate("MainWindow", "\345\257\271\345\261\200\345\216\206\345\217\262", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\344\270\255\345\233\275\350\261\241\346\243\213", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\345\233\275\351\231\205\350\261\241\346\243\213", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\350\203\214\346\231\257\351\237\263\344\271\220", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\237\263\346\225\210\350\256\276\347\275\256", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "\351\253\230\351\237\263\351\207\217", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "\351\200\202\344\270\255", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\225\214\351\235\242\344\270\273\351\242\230", nullptr));
        radioButton_7->setText(QCoreApplication::translate("MainWindow", "\346\230\216\344\272\256\346\250\241\345\274\217", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainWindow", "\346\267\261\350\211\262\346\250\241\345\274\217", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\257\255\350\250\200\351\200\211\346\213\251", nullptr));
        radioButton_9->setText(QCoreApplication::translate("MainWindow", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));
        radioButton_10->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\233\264\346\224\271", nullptr));
        btnLogout->setText(QCoreApplication::translate("MainWindow", "\351\200\200 \345\207\272 \347\231\273 \345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
