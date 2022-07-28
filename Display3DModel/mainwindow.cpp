#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "window.h"
#include <QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QScreen>
#include "QWidget"
#include <QFileDialog>
#include "scene.h"
#include "scene_gles.h"
#include <QtMath>

int nTranslationX = 0;
int nTranslationY = 0;
int nTranslationZ = 0;
int nRotationX = 0;
int nRotationY = 0;
int nRotationZ = 0;
int nAngleJ1 = 0;
int nAngleJ2 = 0;
int nAngleJ3 = 0;
int nAngleJ4 = 0;
double theta1Solution = 0.0f;
double theta2Solution = 0.0f;
double theta3Solution = 0.0f;
double theta4Solution = 0.0f;

MainWindow* pMainWindow = nullptr;

double constrainAngle(double x){
    x = fmod(x + 180,360);
    if (x < 0)
        x += 360;
    return x - 180;
}

void calculateInverseKinematics(float EEffectorX, float EEffectorY, float EEffectorZ, float pitch)
{
    // Normal Mode Inverse Kinematics
    double theta1 = qAtan2(EEffectorY, EEffectorX) * 180 / M_PI;

    double Y = EEffectorZ - 65.2f;
    double X = sqrt(EEffectorX * EEffectorX + EEffectorY * EEffectorY) ;
    double beta = 0.0f;
    beta = -pitch;

    double P2x = X - 93 * qCos(beta * M_PI / 180);
    double P2y = Y - 93 * qSin(beta * M_PI / 180);
    double theta3 = qAcos((P2x*P2x + P2y*P2y - 300*300 - 383*383) / (2 * 300 * 383)) * 180 / M_PI ;
    double theta2 = (qAtan(P2y/ P2x) - qAtan2( (383 * qSin(theta3 * M_PI / 180))  ,
                                            ( 300 + 383 * qCos(theta3 * M_PI / 180) ) ) )* 180 / M_PI;
    double theta4 = beta - theta3 - theta2;

    theta1Solution = theta1;
    theta2Solution = theta2;
    theta3Solution = theta3;
    theta4Solution = theta4;

    qDebug() << round(constrainAngle(theta1Solution));
    qDebug() << round(constrainAngle(theta2Solution));
    qDebug() << round(theta3Solution);
    qDebug() << round(constrainAngle(theta4Solution));
}

QWidget* MainWindow::getWidgetMain()
{
    return ui->widgetMain;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pMainWindow = this;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verticalSlider_Roll_valueChanged(int value)
{
    nRotationX = value;
    ui->lnERotX->setText(QString::number(value));
}


void MainWindow::on_verticalSlider_Pitch_valueChanged(int value)
{
    nRotationY = value;
    ui->lnERotY->setText(QString::number(value));
}


void MainWindow::on_verticalSlider_Yaw_valueChanged(int value)
{
    nRotationZ = value;
    ui->lnERotZ->setText(QString::number(value));
}


int getRotationX()
{
    return nRotationX;
}

int getRotationY()
{
    return nRotationY;
}

int getRotationZ()
{
    return nRotationZ;
}

void MainWindow::on_verticalSlider_transX_valueChanged(int value)
{
    nTranslationX = value;
    ui->lnETransX->setText(QString::number(value));
}


void MainWindow::on_verticalSlider_transY_valueChanged(int value)
{
    nTranslationY = value;
    ui->lnETransY->setText(QString::number(value));
}


void MainWindow::on_verticalSlider_transZ_valueChanged(int value)
{
    nTranslationZ = value;
    ui->lnETransZ->setText(QString::number(value));
}

int getTranslationX()
{
    return nTranslationX;
}

int getTranslationY()
{
    return nTranslationY;
}

int getTranslationZ()
{
    return nTranslationZ;
}




void MainWindow::on_horizontalSliderJ1_valueChanged(int value)
{
    nAngleJ1 = value;
    ui->lnEJoint1->setText(QString::number(value));
}


void MainWindow::on_horizontalSliderJ2_valueChanged(int value)
{
    nAngleJ2 = value;
    ui->lnEJoint2->setText(QString::number(value));
}


void MainWindow::on_horizontalSliderJ3_valueChanged(int value)
{
    nAngleJ3 = value;
    ui->lnEJoint3->setText(QString::number(value));
}


void MainWindow::on_horizontalSliderJ4_valueChanged(int value)
{
    nAngleJ4 = value;
    ui->lnEJoint4->setText(QString::number(value));
}

int getAngleJ1()
{
    return nAngleJ1;
}

int getAngleJ2()
{
    return nAngleJ2;
}

int getAngleJ3()
{
    return nAngleJ3;
}

int getAngleJ4()
{
    return nAngleJ4;
}



void MainWindow::on_lnETransX_textChanged(const QString &arg1)
{
    ui->verticalSlider_transX->setValue(arg1.toInt());
}


void MainWindow::on_lnETransY_textChanged(const QString &arg1)
{
    ui->verticalSlider_transY->setValue(arg1.toInt());
}


void MainWindow::on_lnETransZ_textChanged(const QString &arg1)
{
    ui->verticalSlider_transZ->setValue(arg1.toInt());
}


void MainWindow::on_lnERotX_textChanged(const QString &arg1)
{
    ui->verticalSlider_Roll->setValue(arg1.toInt());
}


void MainWindow::on_lnERotY_textChanged(const QString &arg1)
{
    ui->verticalSlider_Pitch->setValue(arg1.toInt());
}


void MainWindow::on_lnERotZ_textChanged(const QString &arg1)
{
    ui->verticalSlider_Yaw->setValue(arg1.toInt());
}


void MainWindow::on_lnEJoint1_textChanged(const QString &arg1)
{
    ui->horizontalSliderJ1->setValue(arg1.toInt());
}


void MainWindow::on_lnEJoint2_textChanged(const QString &arg1)
{
    ui->horizontalSliderJ2->setValue(arg1.toInt());
}


void MainWindow::on_lnEJoint3_textChanged(const QString &arg1)
{
    ui->horizontalSliderJ3->setValue(arg1.toInt());
}


void MainWindow::on_lnEJoint4_textChanged(const QString &arg1)
{
    ui->horizontalSliderJ4->setValue(arg1.toInt());
}

void MainWindow::setEffectorX(float value)
{
    ui->lnEEffectorX->setText(QString::number(value));
}

void MainWindow::setEffectorY(float value)
{
    ui->lnEEffectorY->setText(QString::number(value));
}

void MainWindow::setEffectorZ(float value)
{
    ui->lnEEffectorZ->setText(QString::number(value));
}

void MainWindow::setEffectorRoll(float value)
{
    ui->lnEEffectorRoll->setText(QString::number(value));
}

void MainWindow::setEffectorPitch(float value)
{
    ui->lnEEffectorPitch->setText(QString::number(value));
}

void MainWindow::setEffectorYaw(float value)
{
    ui->lnEEffectorYaw->setText(QString::number(value));
}

MainWindow* getMainWinPtr()
{
    return pMainWindow;
}

void MainWindow::updateEffector(float EffectorX, float EffectorY, float EffectorZ, float EffectorRoll, float EffectorPitch, float EffectorYaw)
{
    ui->lnEEffectorX->setText(QString::number(EffectorX, 'f', 2));
    ui->lnEEffectorY->setText(QString::number(EffectorY, 'f', 2));
    ui->lnEEffectorZ->setText(QString::number(EffectorZ, 'f', 2));
    ui->lnEEffectorRoll->setText(QString::number(EffectorRoll, 'f', 2));
    ui->lnEEffectorPitch->setText(QString::number(EffectorPitch, 'f', 2));
    ui->lnEEffectorYaw->setText(QString::number(EffectorYaw, 'f', 2));
}

void MainWindow::on_horizontalSliderInvX_valueChanged(int value)
{
    ui->lnEInvX->setText(QString::number((float)value / 100));
    calculateInverseKinematics(ui->horizontalSliderInvX->value() / (float) 100,
                               ui->horizontalSliderInvY->value() / (float) 100,
                               ui->horizontalSliderInvZ->value() / (float) 100,
                               ui->horizontalSliderInvPitch->value()
);
    ui->horizontalSliderJ1->setValue((int) theta1Solution);
    ui->horizontalSliderJ2->setValue((int) theta2Solution);
    ui->horizontalSliderJ3->setValue((int) theta3Solution);
    ui->horizontalSliderJ4->setValue((int) theta4Solution);
}


void MainWindow::on_horizontalSliderInvY_valueChanged(int value)
{
    ui->lnEInvY->setText(QString::number((float)value / 100));
    calculateInverseKinematics(ui->horizontalSliderInvX->value() / (float) 100,
                               ui->horizontalSliderInvY->value() / (float) 100,
                               ui->horizontalSliderInvZ->value() / (float) 100,
                               ui->horizontalSliderInvPitch->value()
);
    ui->horizontalSliderJ1->setValue((int) theta1Solution);
    ui->horizontalSliderJ2->setValue((int) theta2Solution);
    ui->horizontalSliderJ3->setValue((int) theta3Solution);
    ui->horizontalSliderJ4->setValue((int) theta4Solution);
}


void MainWindow::on_horizontalSliderInvZ_valueChanged(int value)
{
    ui->lnEInvZ->setText(QString::number((float)value / 100));
    calculateInverseKinematics(ui->horizontalSliderInvX->value() / (float) 100,
                               ui->horizontalSliderInvY->value() / (float) 100,
                               ui->horizontalSliderInvZ->value() / (float) 100,
                               ui->horizontalSliderInvPitch->value()
);
    ui->horizontalSliderJ1->setValue((int) theta1Solution);
    ui->horizontalSliderJ2->setValue((int) theta2Solution);
    ui->horizontalSliderJ3->setValue((int) theta3Solution);
    ui->horizontalSliderJ4->setValue((int) theta4Solution);
}


void MainWindow::on_horizontalSliderInvRoll_valueChanged(int value)
{
    ui->lnEInvRoll->setText(QString::number(value));
    calculateInverseKinematics(ui->horizontalSliderInvX->value() / (float) 100,
                               ui->horizontalSliderInvY->value() / (float) 100,
                               ui->horizontalSliderInvZ->value() / (float) 100,
                               ui->horizontalSliderInvPitch->value()
);
    ui->horizontalSliderJ1->setValue((int) theta1Solution);
    ui->horizontalSliderJ2->setValue((int) theta2Solution);
    ui->horizontalSliderJ3->setValue((int) theta3Solution);
    ui->horizontalSliderJ4->setValue((int) theta4Solution);
}


void MainWindow::on_horizontalSliderInvPitch_valueChanged(int value)
{
    ui->lnEInvPitch->setText(QString::number(value));
    calculateInverseKinematics(ui->horizontalSliderInvX->value() / (float) 100,
                               ui->horizontalSliderInvY->value() / (float) 100,
                               ui->horizontalSliderInvZ->value() / (float) 100,
                               ui->horizontalSliderInvPitch->value()
);
    ui->horizontalSliderJ1->setValue((int) theta1Solution);
    ui->horizontalSliderJ2->setValue((int) theta2Solution);
    ui->horizontalSliderJ3->setValue((int) theta3Solution);
    ui->horizontalSliderJ4->setValue((int) theta4Solution);
}


void MainWindow::on_horizontalSliderInvYaw_valueChanged(int value)
{
    ui->lnEInvYaw->setText(QString::number(value));
    calculateInverseKinematics(ui->horizontalSliderInvX->value() / (float) 100,
                               ui->horizontalSliderInvY->value() / (float) 100,
                               ui->horizontalSliderInvZ->value() / (float) 100,
                               ui->horizontalSliderInvPitch->value()
);
    ui->horizontalSliderJ1->setValue((int) theta1Solution);
    ui->horizontalSliderJ2->setValue((int) theta2Solution);
    ui->horizontalSliderJ3->setValue((int) theta3Solution);
    ui->horizontalSliderJ4->setValue((int) theta4Solution);
}


void MainWindow::on_pushButton_clicked()
{
    ui->lnEInvX->setText(QString::number((float)(ui->horizontalSliderInvX->value()) / 100));
    ui->lnEInvY->setText(QString::number((float)(ui->horizontalSliderInvY->value()) / 100));
    ui->lnEInvZ->setText(QString::number((float)(ui->horizontalSliderInvZ->value()) / 100));
    ui->lnEInvRoll->setText(QString::number((float)(ui->horizontalSliderInvRoll->value())));
    ui->lnEInvPitch->setText(QString::number((float)(ui->horizontalSliderInvPitch->value())))
    ;
    calculateInverseKinematics(ui->horizontalSliderInvX->value() / (float) 100,
                               ui->horizontalSliderInvY->value() / (float) 100,
                               ui->horizontalSliderInvZ->value() / (float) 100,
                               ui->horizontalSliderInvPitch->value()
                              );
    ui->horizontalSliderJ1->setValue((int) theta1Solution);
    ui->horizontalSliderJ2->setValue((int) theta2Solution);
    ui->horizontalSliderJ3->setValue((int) theta3Solution);
    ui->horizontalSliderJ4->setValue((int) theta4Solution);
}

