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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widgetMain;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *verticalSlider_transX;
    QSlider *verticalSlider_transY;
    QSlider *verticalSlider_transZ;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSlider *verticalSlider_Roll;
    QSlider *verticalSlider_Pitch;
    QSlider *verticalSlider_Yaw;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1165, 701);
        widgetMain = new QWidget(MainWindow);
        widgetMain->setObjectName(QString::fromUtf8("widgetMain"));
        widgetMain->setGeometry(QRect(10, 10, 921, 681));
        widgetMain->setAutoFillBackground(false);
        verticalLayoutWidget_4 = new QWidget(MainWindow);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(940, 120, 211, 391));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSlider_transX = new QSlider(verticalLayoutWidget_4);
        verticalSlider_transX->setObjectName(QString::fromUtf8("verticalSlider_transX"));
        verticalSlider_transX->setMinimum(-200);
        verticalSlider_transX->setMaximum(200);
        verticalSlider_transX->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_transX);

        verticalSlider_transY = new QSlider(verticalLayoutWidget_4);
        verticalSlider_transY->setObjectName(QString::fromUtf8("verticalSlider_transY"));
        verticalSlider_transY->setMinimum(-200);
        verticalSlider_transY->setMaximum(200);
        verticalSlider_transY->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_transY);

        verticalSlider_transZ = new QSlider(verticalLayoutWidget_4);
        verticalSlider_transZ->setObjectName(QString::fromUtf8("verticalSlider_transZ"));
        verticalSlider_transZ->setMinimum(-200);
        verticalSlider_transZ->setMaximum(200);
        verticalSlider_transZ->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_transZ);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(verticalLayoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalSlider_Roll = new QSlider(verticalLayoutWidget_4);
        verticalSlider_Roll->setObjectName(QString::fromUtf8("verticalSlider_Roll"));
        verticalSlider_Roll->setMaximum(360);
        verticalSlider_Roll->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Roll);

        verticalSlider_Pitch = new QSlider(verticalLayoutWidget_4);
        verticalSlider_Pitch->setObjectName(QString::fromUtf8("verticalSlider_Pitch"));
        verticalSlider_Pitch->setMaximum(360);
        verticalSlider_Pitch->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Pitch);

        verticalSlider_Yaw = new QSlider(verticalLayoutWidget_4);
        verticalSlider_Yaw->setObjectName(QString::fromUtf8("verticalSlider_Yaw"));
        verticalSlider_Yaw->setMaximum(360);
        verticalSlider_Yaw->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Yaw);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RobotSimulation", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Translation Control", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Rotation Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
