#include "window.h"

#include <QKeyEvent>
#include <QOpenGLContext>
#include <QTimer>
#include <QDebug>
#include "scenebase.h"
#include <QCoreApplication>

OpenGLWindow::OpenGLWindow( SceneSelector *sceneSelector, int refreshRate, int major, int minor, QScreen* screen )
    : QWindow(screen)
{
    QSurfaceFormat requestedFormat;
    requestedFormat.setDepthBufferSize( 24 );
    requestedFormat.setMajorVersion( major );
    requestedFormat.setMinorVersion( minor );

    requestedFormat.setSamples( 4 );
    requestedFormat.setProfile( QSurfaceFormat::CoreProfile );

    m_context = new QOpenGLContext;
    m_context->setFormat( requestedFormat );
    m_context->create();

    if(m_context->format().version() == qMakePair(3,3)) {
        qDebug() << "Using OpenGL 3.3 context";
        m_scene = sceneSelector->getScene(qMakePair(3,3), false);
    }
    else {
        m_context->deleteLater();
        requestedFormat.setMajorVersion(2);
        requestedFormat.setMinorVersion(1);
        m_context = new QOpenGLContext;
        m_context->setFormat( requestedFormat );
        m_context->create();

        if (m_context->format().version().first < 2) {
            qDebug() << "Unable to get a valid version of OpenGL, aborting";
            exit(1);
        }

        qDebug() << "Unable to get an OpenGL 3.3 context. Version is " << m_context->format().version() << ", Using OpenGL 2.1/OpenGL ES context";
        m_scene = sceneSelector->getScene(m_context->format().version(), m_context->format().renderableType() == QSurfaceFormat::OpenGLES);
    }

    setSurfaceType(OpenGLSurface);
    setFormat( m_context->format() );
    resize( 800, 600 );
    create();

    connect( this, SIGNAL( widthChanged( int ) ), this, SLOT( resizeGL() ) );
    connect( this, SIGNAL( heightChanged( int ) ), this, SLOT( resizeGL() ) );
    connect( m_context, SIGNAL(aboutToBeDestroyed()), this, SLOT(cleanup()), Qt::DirectConnection );

    initializeGL();
    resizeGL();

    m_timer = new QTimer;
    m_timer->setInterval(refreshRate);
    connect(m_timer, &QTimer::timeout, this, &OpenGLWindow::updateGL);
    m_timer->start();
}

OpenGLWindow::~OpenGLWindow()
{
    m_context->deleteLater();
}

void OpenGLWindow::initializeGL()
{
    m_context->makeCurrent( this );

    m_scene->initialize();
}

void OpenGLWindow::updateGL()
{
    if(!isExposed())
        return;

    m_context->makeCurrent( this );

    m_scene->update();

    m_context->swapBuffers( this );
}

void OpenGLWindow::resizeGL()
{
    m_context->makeCurrent( this );

    m_scene->resize( width(), height() );
    updateGL();
}

void OpenGLWindow::cleanup()
{
    m_context->makeCurrent( this );

    m_scene->cleanup();
}
