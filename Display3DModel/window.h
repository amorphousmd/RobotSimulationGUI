#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QWindow>
#include <QOpenGLContext>

class SceneBase;

class SceneSelector {
public:
    virtual SceneBase* getScene(QPair<int,int> glVersion, bool isOpenGLES) = 0;
};

class OpenGLWindow : public QWindow
{
    Q_OBJECT

public:
    OpenGLWindow( SceneSelector *scene, int refreshRate, int major=3, int minor=3, QScreen* screen = 0 );
    ~OpenGLWindow();

protected:
    void initializeGL();

private:
    QTimer *m_timer;
    SceneBase *m_scene;
    QOpenGLContext* m_context;

protected slots:
    void updateGL();
    void resizeGL();
    void cleanup();
};

#endif // OPENGLWINDOW_H
