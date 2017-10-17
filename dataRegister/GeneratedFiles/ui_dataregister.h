/********************************************************************************
** Form generated from reading UI file 'dataregister.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAREGISTER_H
#define UI_DATAREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataRegisterClass
{
public:
    QWidget *centralWidget;
    QPushButton *recordButton;
    QLabel *webcamLabel;
    QLabel *label;
    QLabel *touchStateLabel;
    QLabel *label_2;
    QLabel *gestureLabel;
    QLabel *label_3;
    QLabel *gyroxLabel;
    QLabel *gyroxLabel_2;
    QLabel *gyroxLabel_3;
    QLabel *gyroxLabel_4;
    QLabel *gyroyLabel;
    QLabel *gyrozLabel;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *pitchLabel;
    QLabel *yawLabel;
    QLabel *rollLabel;
    QPushButton *stopButton;
    QPushButton *saveButton;
    QLabel *webcam2Label;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QLabel *label_8;
    QLabel *positionLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dataRegisterClass)
    {
        if (dataRegisterClass->objectName().isEmpty())
            dataRegisterClass->setObjectName(QStringLiteral("dataRegisterClass"));
        dataRegisterClass->resize(804, 552);
        QPalette palette;
        QBrush brush(QColor(85, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(39, 39, 39, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        dataRegisterClass->setPalette(palette);
        centralWidget = new QWidget(dataRegisterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        recordButton = new QPushButton(centralWidget);
        recordButton->setObjectName(QStringLiteral("recordButton"));
        recordButton->setGeometry(QRect(30, 450, 75, 23));
        webcamLabel = new QLabel(centralWidget);
        webcamLabel->setObjectName(QStringLiteral("webcamLabel"));
        webcamLabel->setGeometry(QRect(20, 20, 381, 281));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 350, 91, 16));
        touchStateLabel = new QLabel(centralWidget);
        touchStateLabel->setObjectName(QStringLiteral("touchStateLabel"));
        touchStateLabel->setGeometry(QRect(50, 370, 131, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 350, 91, 16));
        gestureLabel = new QLabel(centralWidget);
        gestureLabel->setObjectName(QStringLiteral("gestureLabel"));
        gestureLabel->setGeometry(QRect(210, 370, 131, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 350, 47, 13));
        gyroxLabel = new QLabel(centralWidget);
        gyroxLabel->setObjectName(QStringLiteral("gyroxLabel"));
        gyroxLabel->setGeometry(QRect(400, 370, 81, 21));
        gyroxLabel_2 = new QLabel(centralWidget);
        gyroxLabel_2->setObjectName(QStringLiteral("gyroxLabel_2"));
        gyroxLabel_2->setGeometry(QRect(380, 370, 16, 21));
        gyroxLabel_3 = new QLabel(centralWidget);
        gyroxLabel_3->setObjectName(QStringLiteral("gyroxLabel_3"));
        gyroxLabel_3->setGeometry(QRect(380, 390, 16, 21));
        gyroxLabel_4 = new QLabel(centralWidget);
        gyroxLabel_4->setObjectName(QStringLiteral("gyroxLabel_4"));
        gyroxLabel_4->setGeometry(QRect(380, 410, 20, 21));
        gyroyLabel = new QLabel(centralWidget);
        gyroyLabel->setObjectName(QStringLiteral("gyroyLabel"));
        gyroyLabel->setGeometry(QRect(400, 390, 81, 21));
        gyrozLabel = new QLabel(centralWidget);
        gyrozLabel->setObjectName(QStringLiteral("gyrozLabel"));
        gyrozLabel->setGeometry(QRect(400, 410, 81, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(470, 350, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(490, 370, 31, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(490, 390, 31, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(490, 410, 31, 16));
        pitchLabel = new QLabel(centralWidget);
        pitchLabel->setObjectName(QStringLiteral("pitchLabel"));
        pitchLabel->setGeometry(QRect(520, 410, 41, 21));
        yawLabel = new QLabel(centralWidget);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));
        yawLabel->setGeometry(QRect(520, 370, 41, 21));
        rollLabel = new QLabel(centralWidget);
        rollLabel->setObjectName(QStringLiteral("rollLabel"));
        rollLabel->setGeometry(QRect(520, 390, 41, 21));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(120, 450, 75, 23));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(210, 450, 75, 23));
        webcam2Label = new QLabel(centralWidget);
        webcam2Label->setObjectName(QStringLiteral("webcam2Label"));
        webcam2Label->setGeometry(QRect(410, 20, 381, 281));
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(390, 450, 75, 23));
        resumeButton = new QPushButton(centralWidget);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));
        resumeButton->setGeometry(QRect(480, 450, 75, 23));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(580, 350, 47, 13));
        positionLabel = new QLabel(centralWidget);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setGeometry(QRect(600, 370, 131, 16));
        dataRegisterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dataRegisterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 804, 21));
        dataRegisterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dataRegisterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dataRegisterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dataRegisterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dataRegisterClass->setStatusBar(statusBar);

        retranslateUi(dataRegisterClass);

        QMetaObject::connectSlotsByName(dataRegisterClass);
    } // setupUi

    void retranslateUi(QMainWindow *dataRegisterClass)
    {
        dataRegisterClass->setWindowTitle(QApplication::translate("dataRegisterClass", "dataRegister", 0));
        recordButton->setText(QApplication::translate("dataRegisterClass", "record", 0));
        webcamLabel->setText(QString());
        label->setText(QApplication::translate("dataRegisterClass", "Touch sensors", 0));
        touchStateLabel->setText(QApplication::translate("dataRegisterClass", "waiting for connection..", 0));
        label_2->setText(QApplication::translate("dataRegisterClass", "Myo gesture", 0));
        gestureLabel->setText(QApplication::translate("dataRegisterClass", "waiting for connection..", 0));
        label_3->setText(QApplication::translate("dataRegisterClass", "Gyro", 0));
        gyroxLabel->setText(QApplication::translate("dataRegisterClass", "0", 0));
        gyroxLabel_2->setText(QApplication::translate("dataRegisterClass", "x:", 0));
        gyroxLabel_3->setText(QApplication::translate("dataRegisterClass", "y:", 0));
        gyroxLabel_4->setText(QApplication::translate("dataRegisterClass", "z:", 0));
        gyroyLabel->setText(QApplication::translate("dataRegisterClass", "0", 0));
        gyrozLabel->setText(QApplication::translate("dataRegisterClass", "0", 0));
        label_4->setText(QApplication::translate("dataRegisterClass", "Rotation", 0));
        label_5->setText(QApplication::translate("dataRegisterClass", "yaw:", 0));
        label_6->setText(QApplication::translate("dataRegisterClass", "roll:", 0));
        label_7->setText(QApplication::translate("dataRegisterClass", "pitch:", 0));
        pitchLabel->setText(QApplication::translate("dataRegisterClass", "0", 0));
        yawLabel->setText(QApplication::translate("dataRegisterClass", "0", 0));
        rollLabel->setText(QApplication::translate("dataRegisterClass", "0", 0));
        stopButton->setText(QApplication::translate("dataRegisterClass", "stop", 0));
        saveButton->setText(QApplication::translate("dataRegisterClass", "save", 0));
        webcam2Label->setText(QString());
        pauseButton->setText(QApplication::translate("dataRegisterClass", "pause", 0));
        resumeButton->setText(QApplication::translate("dataRegisterClass", "resume", 0));
        label_8->setText(QApplication::translate("dataRegisterClass", "Position", 0));
        positionLabel->setText(QApplication::translate("dataRegisterClass", "waining for connection...", 0));
    } // retranslateUi

};

namespace Ui {
    class dataRegisterClass: public Ui_dataRegisterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAREGISTER_H
