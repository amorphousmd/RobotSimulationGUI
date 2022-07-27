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

MainWindow* pMainWindow = nullptr;

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
