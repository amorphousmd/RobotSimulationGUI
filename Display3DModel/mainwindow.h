#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget* getWidgetMain();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_verticalSlider_X_valueChanged(int value);

    void on_verticalSlider_Y_valueChanged(int value);

    void on_verticalSlider_Z_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

int getRotationX();
int getRotationY();
int getRotationZ();
#endif // MAINWINDOW_H
