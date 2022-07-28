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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widgetMain;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lnETransX;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lnETransY;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lnETransZ;
    QSpacerItem *horizontalSpacer_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *verticalSlider_transX;
    QSlider *verticalSlider_transY;
    QSlider *verticalSlider_transZ;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSlider *verticalSlider_Roll;
    QSlider *verticalSlider_Pitch;
    QSlider *verticalSlider_Yaw;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lnERotX;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lnERotY;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lnERotZ;
    QSpacerItem *horizontalSpacer_8;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lnEJoint1;
    QLineEdit *lnEJoint2;
    QLineEdit *lnEJoint3;
    QLineEdit *lnEJoint4;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSlider *horizontalSliderJ1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSlider *horizontalSliderJ2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSlider *horizontalSliderJ3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSlider *horizontalSliderJ4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lnEEffectorY;
    QLineEdit *lnEEffectorX;
    QLineEdit *lnEEffectorPitch;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_3;
    QLineEdit *lnEEffectorZ;
    QLineEdit *lnEEffectorRoll;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lnEEffectorYaw;
    QLabel *label_14;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1326, 720);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        widgetMain = new QWidget(MainWindow);
        widgetMain->setObjectName(QString::fromUtf8("widgetMain"));
        widgetMain->setGeometry(QRect(10, 30, 941, 691));
        widgetMain->setAutoFillBackground(false);
        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(960, 0, 361, 721));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayoutWidget_5 = new QWidget(tab);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 250, 386, 31));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        lnETransX = new QLineEdit(horizontalLayoutWidget_5);
        lnETransX->setObjectName(QString::fromUtf8("lnETransX"));
        lnETransX->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(lnETransX);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        lnETransY = new QLineEdit(horizontalLayoutWidget_5);
        lnETransY->setObjectName(QString::fromUtf8("lnETransY"));
        lnETransY->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(lnETransY);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        lnETransZ = new QLineEdit(horizontalLayoutWidget_5);
        lnETransZ->setObjectName(QString::fromUtf8("lnETransZ"));
        lnETransZ->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(lnETransZ);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 321, 171));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSlider_transX = new QSlider(layoutWidget);
        verticalSlider_transX->setObjectName(QString::fromUtf8("verticalSlider_transX"));
        verticalSlider_transX->setMinimum(-200);
        verticalSlider_transX->setMaximum(200);
        verticalSlider_transX->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_transX);

        verticalSlider_transY = new QSlider(layoutWidget);
        verticalSlider_transY->setObjectName(QString::fromUtf8("verticalSlider_transY"));
        verticalSlider_transY->setMinimum(-200);
        verticalSlider_transY->setMaximum(200);
        verticalSlider_transY->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_transY);

        verticalSlider_transZ = new QSlider(layoutWidget);
        verticalSlider_transZ->setObjectName(QString::fromUtf8("verticalSlider_transZ"));
        verticalSlider_transZ->setMinimum(-200);
        verticalSlider_transZ->setMaximum(200);
        verticalSlider_transZ->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_transZ);


        verticalLayout_3->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 300, 321, 171));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalSlider_Roll = new QSlider(layoutWidget1);
        verticalSlider_Roll->setObjectName(QString::fromUtf8("verticalSlider_Roll"));
        verticalSlider_Roll->setMaximum(360);
        verticalSlider_Roll->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Roll);

        verticalSlider_Pitch = new QSlider(layoutWidget1);
        verticalSlider_Pitch->setObjectName(QString::fromUtf8("verticalSlider_Pitch"));
        verticalSlider_Pitch->setMaximum(360);
        verticalSlider_Pitch->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Pitch);

        verticalSlider_Yaw = new QSlider(layoutWidget1);
        verticalSlider_Yaw->setObjectName(QString::fromUtf8("verticalSlider_Yaw"));
        verticalSlider_Yaw->setMaximum(360);
        verticalSlider_Yaw->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_Yaw);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutWidget_6 = new QWidget(tab);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 480, 386, 31));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        lnERotX = new QLineEdit(horizontalLayoutWidget_6);
        lnERotX->setObjectName(QString::fromUtf8("lnERotX"));
        lnERotX->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(lnERotX);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        lnERotY = new QLineEdit(horizontalLayoutWidget_6);
        lnERotY->setObjectName(QString::fromUtf8("lnERotY"));
        lnERotY->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(lnERotY);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        lnERotZ = new QLineEdit(horizontalLayoutWidget_6);
        lnERotZ->setObjectName(QString::fromUtf8("lnERotZ"));
        lnERotZ->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(lnERotZ);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 420, 76, 171));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lnEJoint1 = new QLineEdit(verticalLayoutWidget);
        lnEJoint1->setObjectName(QString::fromUtf8("lnEJoint1"));
        lnEJoint1->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lnEJoint1);

        lnEJoint2 = new QLineEdit(verticalLayoutWidget);
        lnEJoint2->setObjectName(QString::fromUtf8("lnEJoint2"));
        lnEJoint2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lnEJoint2);

        lnEJoint3 = new QLineEdit(verticalLayoutWidget);
        lnEJoint3->setObjectName(QString::fromUtf8("lnEJoint3"));
        lnEJoint3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lnEJoint3);

        lnEJoint4 = new QLineEdit(verticalLayoutWidget);
        lnEJoint4->setObjectName(QString::fromUtf8("lnEJoint4"));
        lnEJoint4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lnEJoint4);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 390, 91, 20));
        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 420, 251, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        horizontalSliderJ1 = new QSlider(verticalLayoutWidget_2);
        horizontalSliderJ1->setObjectName(QString::fromUtf8("horizontalSliderJ1"));
        horizontalSliderJ1->setMinimum(-180);
        horizontalSliderJ1->setMaximum(180);
        horizontalSliderJ1->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSliderJ1);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        horizontalSliderJ2 = new QSlider(verticalLayoutWidget_2);
        horizontalSliderJ2->setObjectName(QString::fromUtf8("horizontalSliderJ2"));
        horizontalSliderJ2->setMinimum(-180);
        horizontalSliderJ2->setMaximum(180);
        horizontalSliderJ2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSliderJ2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        horizontalSliderJ3 = new QSlider(verticalLayoutWidget_2);
        horizontalSliderJ3->setObjectName(QString::fromUtf8("horizontalSliderJ3"));
        horizontalSliderJ3->setMinimum(0);
        horizontalSliderJ3->setMaximum(180);
        horizontalSliderJ3->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSliderJ3);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        horizontalSliderJ4 = new QSlider(verticalLayoutWidget_2);
        horizontalSliderJ4->setObjectName(QString::fromUtf8("horizontalSliderJ4"));
        horizontalSliderJ4->setMinimum(-180);
        horizontalSliderJ4->setMaximum(180);
        horizontalSliderJ4->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSliderJ4);


        verticalLayout_2->addLayout(horizontalLayout_7);

        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 60, 141, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lnEEffectorY = new QLineEdit(gridLayoutWidget);
        lnEEffectorY->setObjectName(QString::fromUtf8("lnEEffectorY"));

        gridLayout->addWidget(lnEEffectorY, 1, 1, 1, 1);

        lnEEffectorX = new QLineEdit(gridLayoutWidget);
        lnEEffectorX->setObjectName(QString::fromUtf8("lnEEffectorX"));

        gridLayout->addWidget(lnEEffectorX, 0, 1, 1, 1);

        lnEEffectorPitch = new QLineEdit(gridLayoutWidget);
        lnEEffectorPitch->setObjectName(QString::fromUtf8("lnEEffectorPitch"));

        gridLayout->addWidget(lnEEffectorPitch, 4, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lnEEffectorZ = new QLineEdit(gridLayoutWidget);
        lnEEffectorZ->setObjectName(QString::fromUtf8("lnEEffectorZ"));

        gridLayout->addWidget(lnEEffectorZ, 2, 1, 1, 1);

        lnEEffectorRoll = new QLineEdit(gridLayoutWidget);
        lnEEffectorRoll->setObjectName(QString::fromUtf8("lnEEffectorRoll"));

        gridLayout->addWidget(lnEEffectorRoll, 3, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 4, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 5, 0, 1, 1);

        lnEEffectorYaw = new QLineEdit(gridLayoutWidget);
        lnEEffectorYaw->setObjectName(QString::fromUtf8("lnEEffectorYaw"));

        gridLayout->addWidget(lnEEffectorYaw, 5, 1, 1, 1);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(40, 30, 81, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget_3 = new QWidget(tab_3);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(90, 100, 160, 169));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(verticalLayoutWidget_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider);

        horizontalSlider_2 = new QSlider(verticalLayoutWidget_3);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_2);

        horizontalSlider_3 = new QSlider(verticalLayoutWidget_3);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_3);

        horizontalSlider_4 = new QSlider(verticalLayoutWidget_3);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_4);

        horizontalSlider_5 = new QSlider(verticalLayoutWidget_3);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_5);

        horizontalSlider_6 = new QSlider(verticalLayoutWidget_3);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_6);

        tabWidget->addTab(tab_3, QString());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RobotSimulation", nullptr));
        lnETransX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnETransY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnETransZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Translation Control", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Rotation Control", nullptr));
        lnERotX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnERotY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnERotZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Scene Control", nullptr));
        lnEJoint1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnEJoint2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnEJoint3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnEJoint4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Joint Control", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "J1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "J2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "J3", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "J4", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Pitch", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Yaw", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "End Effector", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Robot Control", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Inverse Kinematics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
