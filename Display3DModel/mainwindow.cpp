#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "window.h"
#include <QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QScreen>
#include "QWidget"
#include "scene.h"
#include "scene_gles.h"

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
