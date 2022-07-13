#include "window.h"
#include <QApplication>
#include "scene.h"
#include "scene_gles.h"

QString OpenGL_Model("re3dmodel/velociraptor_mesh_materials.dae");

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

    SceneSelect sceneSelect;

    OpenGLWindow w1(&sceneSelect, 40, 3, 3);
    w1.show();

    return a.exec();
}
