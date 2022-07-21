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

    void on_verticalSlider_Roll_valueChanged(int value);

    void on_verticalSlider_Pitch_valueChanged(int value);

    void on_verticalSlider_Yaw_valueChanged(int value);

    void on_verticalSlider_transX_valueChanged(int value);

    void on_verticalSlider_transY_valueChanged(int value);

    void on_verticalSlider_transZ_valueChanged(int value);

    void on_pushButton_pressed();

    void on_horizontalSliderJ1_valueChanged(int value);

    void on_horizontalSliderJ2_valueChanged(int value);

    void on_horizontalSliderJ3_valueChanged(int value);

    void on_horizontalSliderJ4_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

int getRotationX();
int getRotationY();
int getRotationZ();
int getTranslationX();
int getTranslationY();
int getTranslationZ();
int getAngleJ1();
int getAngleJ2();
int getAngleJ3();
int getAngleJ4();


#endif // MAINWINDOW_H
