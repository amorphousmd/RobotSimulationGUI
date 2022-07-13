#ifndef SCENE_GLES_H
#define SCENE_GLES_H

#include <string>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include "modelloader.h"
#include "scenebase.h"

// OpenGL 2.1/OpenGL ES -- Inherit from QOpenGLFunctions to get OpenGL 2.1/OpenGL ES 2.0 functions
class Scene_GLES : public QOpenGLFunctions, public SceneBase
{
public:
    Scene_GLES(QString filepath, ModelLoader::PathType pathType, QString texturePath="");
    void initialize();
    void resize(int w, int h);
    void update();
    void cleanup();

private:
    void createShaderProgram( QString vShader, QString fShader);
    void createBuffers();
    void createAttributes();
    void setupLightingAndMatrices();

    void draw();
    void drawNode(const Node *node, QMatrix4x4 objectMatrix);
    void setMaterialUniforms(MaterialInfo &mater);

    QOpenGLShaderProgram m_shaderProgram;

    QOpenGLBuffer m_vertexBuffer;
    QOpenGLBuffer m_normalBuffer;
    QOpenGLBuffer m_textureUVBuffer;
    QOpenGLBuffer m_indexBuffer;

    QSharedPointer<Node> m_rootNode;

    QMatrix4x4 m_projection, m_view, m_model;

    QString m_filepath;
    ModelLoader::PathType m_pathType;
    QString m_texturePath;

    LightInfo m_lightInfo;
    MaterialInfo m_materialInfo;

    bool m_error;
};

#endif // SCENE_H
