/********************************************************************************
** Form generated from reading UI file 'csvPreferences.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSVPREFERENCES_H
#define UI_CSVPREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_csvPreferences
{
public:
    QLabel *label;
    QCheckBox *cameraCheckBox;
    QCheckBox *gesturesCheckBox;
    QCheckBox *touchCheckBox;
    QLabel *label_2;
    QComboBox *ratioComboBox;
    QCheckBox *rotationCheckBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *csvPreferences)
    {
        if (csvPreferences->objectName().isEmpty())
            csvPreferences->setObjectName(QStringLiteral("csvPreferences"));
        csvPreferences->resize(412, 297);
        QPalette palette;
        QBrush brush(QColor(85, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(9, 32, 39, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        csvPreferences->setPalette(palette);
        label = new QLabel(csvPreferences);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 261, 20));
        cameraCheckBox = new QCheckBox(csvPreferences);
        cameraCheckBox->setObjectName(QStringLiteral("cameraCheckBox"));
        cameraCheckBox->setGeometry(QRect(40, 80, 101, 17));
        cameraCheckBox->setChecked(true);
        gesturesCheckBox = new QCheckBox(csvPreferences);
        gesturesCheckBox->setObjectName(QStringLiteral("gesturesCheckBox"));
        gesturesCheckBox->setGeometry(QRect(160, 80, 111, 17));
        gesturesCheckBox->setChecked(true);
        touchCheckBox = new QCheckBox(csvPreferences);
        touchCheckBox->setObjectName(QStringLiteral("touchCheckBox"));
        touchCheckBox->setGeometry(QRect(270, 80, 101, 17));
        touchCheckBox->setChecked(true);
        label_2 = new QLabel(csvPreferences);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 251, 16));
        ratioComboBox = new QComboBox(csvPreferences);
        ratioComboBox->setObjectName(QStringLiteral("ratioComboBox"));
        ratioComboBox->setGeometry(QRect(30, 190, 69, 22));
        rotationCheckBox = new QCheckBox(csvPreferences);
        rotationCheckBox->setObjectName(QStringLiteral("rotationCheckBox"));
        rotationCheckBox->setGeometry(QRect(40, 110, 111, 17));
        rotationCheckBox->setChecked(true);
        saveButton = new QPushButton(csvPreferences);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(250, 250, 75, 23));
        cancelButton = new QPushButton(csvPreferences);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(160, 250, 75, 23));

        retranslateUi(csvPreferences);

        QMetaObject::connectSlotsByName(csvPreferences);
    } // setupUi

    void retranslateUi(QWidget *csvPreferences)
    {
        csvPreferences->setWindowTitle(QApplication::translate("csvPreferences", "csvPreferences", 0));
        label->setText(QApplication::translate("csvPreferences", "Select what you want to include in your .csv file", 0));
        cameraCheckBox->setText(QApplication::translate("csvPreferences", "camera frames", 0));
        gesturesCheckBox->setText(QApplication::translate("csvPreferences", "myo gestures", 0));
        touchCheckBox->setText(QApplication::translate("csvPreferences", "touch sensors", 0));
        label_2->setText(QApplication::translate("csvPreferences", "camera frames/sensors recordings", 0));
        ratioComboBox->clear();
        ratioComboBox->insertItems(0, QStringList()
         << QApplication::translate("csvPreferences", "1/1", 0)
         << QApplication::translate("csvPreferences", "1/2", 0)
         << QApplication::translate("csvPreferences", "1/3", 0)
         << QApplication::translate("csvPreferences", "1/4", 0)
         << QApplication::translate("csvPreferences", "1/5", 0)
        );
        rotationCheckBox->setText(QApplication::translate("csvPreferences", "myo arm rotation", 0));
        saveButton->setText(QApplication::translate("csvPreferences", "save", 0));
        cancelButton->setText(QApplication::translate("csvPreferences", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class csvPreferences: public Ui_csvPreferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSVPREFERENCES_H
