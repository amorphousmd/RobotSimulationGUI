#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

void calculateInverseKinematics(float EEffectorX, float EEffectorY, float EEffectorZ, float pitch);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget* getWidgetMain();



    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void setEffectorX(float value);

    void setEffectorY(float value);

    void setEffectorZ(float value);

    void setEffectorRoll(float value);

    void setEffectorPitch(float value);

    void setEffectorYaw(float value);

    void updateEffector(float EffectorX, float EffectorY, float EffectorZ, float EffectorRoll, float EffectorPitch, float EffectorYaw);

private slots:

    void on_verticalSlider_Roll_valueChanged(int value);

    void on_verticalSlider_Pitch_valueChanged(int value);

    void on_verticalSlider_Yaw_valueChanged(int value);

    void on_verticalSlider_transX_valueChanged(int value);

    void on_verticalSlider_transY_valueChanged(int value);

    void on_verticalSlider_transZ_valueChanged(int value);

    void on_horizontalSliderJ1_valueChanged(int value);

    void on_horizontalSliderJ2_valueChanged(int value);

    void on_horizontalSliderJ3_valueChanged(int value);

    void on_horizontalSliderJ4_valueChanged(int value);

    void on_lnETransX_textChanged(const QString &arg1);

    void on_lnETransY_textChanged(const QString &arg1);

    void on_lnETransZ_textChanged(const QString &arg1);

    void on_lnERotX_textChanged(const QString &arg1);

    void on_lnERotY_textChanged(const QString &arg1);

    void on_lnERotZ_textChanged(const QString &arg1);

    void on_lnEJoint1_textChanged(const QString &arg1);

    void on_lnEJoint2_textChanged(const QString &arg1);

    void on_lnEJoint3_textChanged(const QString &arg1);

    void on_lnEJoint4_textChanged(const QString &arg1);

    void on_horizontalSliderInvX_valueChanged(int value);

    void on_horizontalSliderInvY_valueChanged(int value);

    void on_horizontalSliderInvZ_valueChanged(int value);

    void on_horizontalSliderInvRoll_valueChanged(int value);

    void on_horizontalSliderInvPitch_valueChanged(int value);

    void on_horizontalSliderInvYaw_valueChanged(int value);

    void on_pushButton_clicked();

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
MainWindow* getMainWinPtr();



#endif // MAINWINDOW_H
