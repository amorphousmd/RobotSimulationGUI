#include "window.h"
#include "mainwindow.h"
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
    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    QObject::connect(&w, &MainWindow::destroyed, widget, &QWidget::deleteLater); // Make widget close as mainwindow closes
    w.show();
    //widget->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.setCentralWidget(widget);
    return a.exec();
//    QApplication app(argc, argv);

//    QCoreApplication::setApplicationName("Qt Hello GL 2 Example");
//    QCoreApplication::setOrganizationName("QtProject");
//    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

//    QSurfaceFormat fmt;
//    fmt.setDepthBufferSize(24);
//    QSurfaceFormat::setDefaultFormat(fmt);

//    MainWindow mainWindow;
//    int widgetArea = mainWindow.width() * mainWindow.height();
//    if (((float)widgetArea / (float)desktopArea) < 0.75f)
//        mainWindow.show();
//    else
//        mainWindow.showMaximized();
//    return app.exec();

    // Embedding window code
//    QApplication app(argc, argv);
//    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
//    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
//    QWidget *container = QWidget::createWindowContainer(view);
//    QSize screenSize = view->screen()->size();
//    container->setMinimumSize(QSize(200, 100));
//    container->setMaximumSize(screenSize);

//    QWidget *widget = new QWidget;
//    QHBoxLayout *hLayout = new QHBoxLayout(widget);
//    QVBoxLayout *vLayout = new QVBoxLayout();
//    vLayout->setAlignment(Qt::AlignTop);
//    hLayout->addWidget(container, 1);
//    hLayout->addLayout(vLayout);

//    widget->setWindowTitle(QStringLiteral("Basic shapes"));

//    // Root entity
//    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

//    // Camera
//    Qt3DRender::QCamera *cameraEntity = view->camera();

//    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
//    cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
//    cameraEntity->setUpVector(QVector3D(0, 1, 0));
//    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

//    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
//    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
//    light->setColor("white");
//    light->setIntensity(1);
//    lightEntity->addComponent(light);
//    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
//    lightTransform->setTranslation(cameraEntity->position());
//    lightEntity->addComponent(lightTransform);

//    // For camera controls
//    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
//    camController->setCamera(cameraEntity);

//    // Scenemodifier
//    SceneModifier *modifier = new SceneModifier(rootEntity);

//    // Set root object of the scene
//    view->setRootEntity(rootEntity);

//    // Create control widgets
//    QCommandLinkButton *info = new QCommandLinkButton();
//    info->setText(QStringLiteral("Qt3D ready-made meshes"));
//    info->setDescription(QString::fromLatin1("Qt3D provides several ready-made meshes, like torus, cylinder, cone, "
//                                             "cube, plane and sphere."));
//    info->setIconSize(QSize(0,0));

//    QCheckBox *torusCB = new QCheckBox(widget);
//    torusCB->setChecked(true);
//    torusCB->setText(QStringLiteral("Torus"));

//    QCheckBox *coneCB = new QCheckBox(widget);
//    coneCB->setChecked(true);
//    coneCB->setText(QStringLiteral("Cone"));

//    QCheckBox *cylinderCB = new QCheckBox(widget);
//    cylinderCB->setChecked(true);
//    cylinderCB->setText(QStringLiteral("Cylinder"));

//    QCheckBox *cuboidCB = new QCheckBox(widget);
//    cuboidCB->setChecked(true);
//    cuboidCB->setText(QStringLiteral("Cuboid"));

//    QCheckBox *planeCB = new QCheckBox(widget);
//    planeCB->setChecked(true);
//    planeCB->setText(QStringLiteral("Plane"));

//    QCheckBox *sphereCB = new QCheckBox(widget);
//    sphereCB->setChecked(true);
//    sphereCB->setText(QStringLiteral("Sphere"));

//    vLayout->addWidget(info);
//    vLayout->addWidget(torusCB);
//    vLayout->addWidget(coneCB);
//    vLayout->addWidget(cylinderCB);
//    vLayout->addWidget(cuboidCB);
//    vLayout->addWidget(planeCB);
//    vLayout->addWidget(sphereCB);

//    QObject::connect(torusCB, &QCheckBox::stateChanged,
//                     modifier, &SceneModifier::enableTorus);
//    QObject::connect(coneCB, &QCheckBox::stateChanged,
//                     modifier, &SceneModifier::enableCone);
//    QObject::connect(cylinderCB, &QCheckBox::stateChanged,
//                     modifier, &SceneModifier::enableCylinder);
//    QObject::connect(cuboidCB, &QCheckBox::stateChanged,
//                     modifier, &SceneModifier::enableCuboid);
//    QObject::connect(planeCB, &QCheckBox::stateChanged,
//                     modifier, &SceneModifier::enablePlane);
//    QObject::connect(sphereCB, &QCheckBox::stateChanged,
//                     modifier, &SceneModifier::enableSphere);

//    torusCB->setChecked(true);
//    coneCB->setChecked(true);
//    cylinderCB->setChecked(true);
//    cuboidCB->setChecked(true);
//    planeCB->setChecked(true);
//    sphereCB->setChecked(true);

//    // Show window
//    widget->show();
//    widget->resize(1200, 800);

    //return app.exec();
}
