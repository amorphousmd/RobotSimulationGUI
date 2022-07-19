#include "window.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QScreen>
#include "QWidget"
#include "scene.h"
//#include "scene_gles.h"

// Declare STL model that needs loading
QString OpenGL_Model("re3dmodel/Link0.stl");
QString OpenGL_Model1("re3dmodel/Link1.stl");

//QString OpenGLES_Model("demon_head/demon_head.3ds");

class SceneSelect : public SceneSelector {
    SceneBase* getScene(QPair<int, int> glVersion, bool isOpenGLES) {
        // use Scene class when GL version is 3.3
        if (glVersion == qMakePair(3,3) && !isOpenGLES) {
            return new Scene(OpenGL_Model, OpenGL_Model1, ModelLoader::RelativePath);
        }
//        // just use GL ES scene for any other version
//        else if (isOpenGLES) {
//            //return new Scene_GLES(OpenGLES_Model, ModelLoader::RelativePath);
//        }
        else {
            return new Scene(OpenGL_Model, OpenGL_Model1, ModelLoader::RelativePath);
//            return new Scene_GLES(OpenGL_Model, ModelLoader::RelativePath);
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SceneSelect sceneSelect;
    SceneSelect sceneSelect2;

    OpenGLWindow w1(&sceneSelect, 40, 3, 3);
    OpenGLWindow w2(&sceneSelect2, 40, 3, 3);

    QWidget *container = QMainWindow::createWindowContainer(&w2);
    QWidget *widget = w.getWidgetMain();
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    QObject::connect(&w, &MainWindow::destroyed, widget, &QWidget::deleteLater); // Make widget close as mainwindow
    w.show();
    return a.exec();

}
