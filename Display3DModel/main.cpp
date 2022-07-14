#include "window.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QScreen>
#include "QWidget"
#include "scene.h"
#include "scene_gles.h"

QString OpenGL_Model("re3dmodel/Link0.stl");

// OpenGL ES 2.0, a single vertex buffer can have at max std::numeric_limits<unsigned short>::max() vertices,
// so use a smaller model if rendering with OpenGL ES
QString OpenGLES_Model("demon_head/demon_head.3ds");

class SceneSelect : public SceneSelector {
    SceneBase* getScene(QPair<int, int> glVersion, bool isOpenGLES) {
        // use Scene class when GL version is 3.3
        if (glVersion == qMakePair(3,3) && !isOpenGLES) {
            return new Scene(OpenGL_Model, ModelLoader::RelativePath);
        }
        // just use GL ES scene for any other version
        else if (isOpenGLES) {
            return new Scene_GLES(OpenGLES_Model, ModelLoader::RelativePath);
        }
        else {
            return new Scene_GLES(OpenGL_Model, ModelLoader::RelativePath);
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    //return a.exec();
    SceneSelect sceneSelect;

    OpenGLWindow w1(&sceneSelect, 40, 3, 3);
    QWidget *container = QMainWindow::createWindowContainer(&w1);

    QSize screenSize = w.screen()->size();
    container->setMinimumSize(QSize(200, 200));
    container->setMaximumSize(QSize(screenSize.width() / 2, screenSize.height()));
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);
    QWidget *widget = w.getWidgetMain();
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    //vLayout->setAlignment(Qt::AlignAbsolute);
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    QObject::connect(&w, &MainWindow::destroyed, widget, &QWidget::deleteLater); // Make widget close as mainwindow
    //widget->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();
    return a.exec();

}
