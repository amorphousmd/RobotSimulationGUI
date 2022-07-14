#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "window.h"
#include <QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QScreen>
#include "QWidget"
#include "scene.h"
#include "scene_gles.h"

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

void MainWindow::on_verticalSlider_X_valueChanged(int value)
{
    nRotationX = value;
}


void MainWindow::on_verticalSlider_Y_valueChanged(int value)
{
    nRotationY = value;
}


void MainWindow::on_verticalSlider_Z_valueChanged(int value)
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
