#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLFunctions>
#include "modelloader.h"
#include "scenebase.h"


class Scene : public QOpenGLFunctions_3_3_Core, public SceneBase
{
public:
    Scene(QString filepath, QString filepath2, QString filepath3, QString filepath4, QString filepath5, QString filepath6, ModelLoader::PathType pathType, QString texturePath="");
    void initialize();
    void resize(int w, int h);
    void update();
    void cleanup();

private:
    void createShaderProgram( QString vShader, QString fShader);
    void createBuffers();
    void createBuffers1();
    void createBuffers2();
    void createBuffers3();
    void createBuffers4();
    void createBuffers5();
    void createAttributes();
    void setupLightingAndMatrices();

    void draw();
    void drawNode(const Node *node, QMatrix4x4 objectMatrix);
    void setMaterialUniforms(MaterialInfo &mater);

    QOpenGLShaderProgram m_shaderProgram;

    QOpenGLVertexArrayObject m_vao;

    QOpenGLBuffer m_vertexBuffer;
    QOpenGLBuffer m_normalBuffer;
    QOpenGLBuffer m_textureUVBuffer;
    QOpenGLBuffer m_indexBuffer;

    QSharedPointer<Node> m_rootNode;

    QMatrix4x4 m_projection, m_view, m_model;

    QString m_filepath;
    QString m_filepath2;
    QString m_filepath3;
    QString m_filepath4;
    QString m_filepath5;
    QString m_filepath6;
    ModelLoader::PathType m_pathType;
    QString m_texturePath;

    LightInfo m_lightInfo;
    MaterialInfo m_materialInfo;

    bool m_error;
};

QMatrix4x4 calculateDHMatrix(float theta, float alpha, float r, float d);

#endif // SCENE_H
