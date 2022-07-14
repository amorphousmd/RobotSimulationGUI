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

QWidget* MainWindow::getWidgetMain()
{
    return ui->widgetMain;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verticalSlider_Roll_valueChanged(int value)
{
    nRotationX = value;
}


void MainWindow::on_verticalSlider_Pitch_valueChanged(int value)
{
    nRotationY = value;
}


void MainWindow::on_verticalSlider_Yaw_valueChanged(int value)
{
    nRotationZ = value;
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
}


void MainWindow::on_verticalSlider_transY_valueChanged(int value)
{
    nTranslationY = value;
}


void MainWindow::on_verticalSlider_transZ_valueChanged(int value)
{
    nTranslationZ = value;
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


void MainWindow::on_pushButton_pressed()
{
    QString filename= QFileDialog::getOpenFileName(this, "Choose File");
    QFile f(filename);
    QFileInfo fileInfo(f.fileName());
    QString nameFile(fileInfo.fileName());
    ui->txtFileName->setText(nameFile);
}

