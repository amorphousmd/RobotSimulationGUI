/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widgetMain;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *verticalSlider_X;
    QSlider *verticalSlider_Y;
    QSlider *verticalSlider_Z;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1165, 701);
        widgetMain = new QWidget(MainWindow);
        widgetMain->setObjectName(QString::fromUtf8("widgetMain"));
        widgetMain->setGeometry(QRect(10, 10, 921, 681));
        widgetMain->setAutoFillBackground(false);
        horizontalLayoutWidget = new QWidget(MainWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(930, 230, 221, 171));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSlider_X = new QSlider(horizontalLayoutWidget);
        verticalSlider_X->setObjectName(QString::fromUtf8("verticalSlider_X"));
        verticalSlider_X->setMaximum(360);
        verticalSlider_X->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_X);

        verticalSlider_Y = new QSlider(horizontalLayoutWidget);
        verticalSlider_Y->setObjectName(QString::fromUtf8("verticalSlider_Y"));
        verticalSlider_Y->setMaximum(360);
        verticalSlider_Y->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Y);

        verticalSlider_Z = new QSlider(horizontalLayoutWidget);
        verticalSlider_Z->setObjectName(QString::fromUtf8("verticalSlider_Z"));
        verticalSlider_Z->setMaximum(360);
        verticalSlider_Z->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Z);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RobotSimulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
