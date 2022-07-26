#include "scene.h"
#include "QTime"
#include "mainwindow.h"
#include <QDebug>
#include <QtMath>

double dRotationX = 0.0f;
double dRotationY = 0.0f;
double dRotationZ = 0.0f;
float fTranslationXE = 0.0f;
float fTranslationYE = 0.0f;
float fTranslationZE = 0.0f;
float fRollAngleE = 0.0f;
float fPitchAngleE = 0.0f;
float fYawAngleE = 0.0f;

float getTranslationXEffector()
{
    return fTranslationXE;
}

float getTranslationYEffector()
{
    return fTranslationXE;
}

float getTranslationZEffector()
{
    return fTranslationXE;
}

float getRollAngleE()
{
    return fRollAngleE;
}

float getPitchAngleE()
{
    return fPitchAngleE;
}

float getYawAngleE()
{
    return fYawAngleE;
}

//QMatrix4x4 calculateXRotationMatrix(float theta)
//{
//    QMatrix4x4 matrix = QMatrix4x4(1, 0, 0, 0,
//                                   0, qCos(theta * M_PI / 180), -qSin(theta * M_PI / 180), 0,
//                                   0, qSin(theta* M_PI / 180), qCos(theta* M_PI / 180), 0,
//                                   0, 0, 0, 1);
//    return matrix;
//}

//QMatrix4x4 calculateYRotationMatrix(float theta)
//{
//    QMatrix4x4 matrix = QMatrix4x4( qCos(theta * M_PI / 180), 0, qSin(theta * M_PI / 180), 0,
//                                   0, 1, 0, 0,
//                                   -qSin(theta * M_PI / 180), 0, qCos(theta* M_PI / 180), 0,
//                                   0, 0, 0, 1);
//    return matrix;
//}

QMatrix4x4 calculateZRotationMatrix(float theta)
{
    QMatrix4x4 matrix = QMatrix4x4(qCos(theta * M_PI / 180), -qSin(theta * M_PI / 180), 0, 0,
                                   qSin(theta * M_PI / 180), qCos(theta * M_PI / 180), 0, 0,
                                   0, 0, 1, 0,
                                   0, 0, 0, 1);
    return matrix;
}

QMatrix4x4 calculateDHMatrix(float theta, float alpha, float r, float d)
{
    QMatrix4x4 matrix = QMatrix4x4(qCos(theta * M_PI / 180), -qSin(theta * M_PI / 180) * qCos(alpha * M_PI / 180), qSin(theta * M_PI / 180) * qSin(alpha * M_PI / 180), r * qCos(theta * M_PI / 180),
                                   qSin(theta * M_PI / 180), qCos(theta * M_PI / 180) * qCos(alpha * M_PI / 180), -qCos(theta * M_PI / 180) * qSin(alpha * M_PI / 180), r * qSin(theta * M_PI / 180),
                                   0, qSin(alpha* M_PI / 180), qCos(alpha* M_PI / 180), d,
                                   0, 0, 0, 1);
    return matrix;
}

Scene::Scene(QString filepath, QString filepath2, QString filepath3, QString filepath4, QString filepath5, QString filepath6, ModelLoader::PathType pathType, QString texturePath) :
    m_indexBuffer(QOpenGLBuffer::IndexBuffer)
  , m_filepath(filepath)
  , m_filepath2(filepath2)
  , m_filepath3(filepath3)
  , m_filepath4(filepath4)
  , m_filepath5(filepath5)
  , m_filepath6(filepath6)
  , m_pathType(pathType)
  , m_texturePath(texturePath)
  , m_error(false)
{

}

void Scene::initialize()
{
    this->initializeOpenGLFunctions();

    createShaderProgram(":/ads_fragment.vert", ":/ads_fragment.frag");

    createBuffers();
    createAttributes();
    setupLightingAndMatrices();

    glEnable(GL_DEPTH_TEST);
    glClearColor(.9f, .9f, .93f ,1.0f); // Background color
    m_vao.create();

}

void Scene::createShaderProgram(QString vShader, QString fShader)
{
    // Compile vertex shader
    if ( !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, vShader.toUtf8() ) )
        qCritical() << "Unable to compile vertex shader. Log:" << m_shaderProgram.log();

    // Compile fragment shader
    if ( !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, fShader.toUtf8() ) )
        qCritical() << "Unable to compile fragment shader. Log:" << m_shaderProgram.log();

    // Link the shaders together into a program
    if ( !m_shaderProgram.link() )
        qCritical() << "Unable to link shader program. Log:" << m_shaderProgram.log();
}

void Scene::createBuffers()
{
    ModelLoader model;

    if(!model.Load(m_filepath, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model.getBufferData(&vertices, &normals, &indices);
    model.getTextureData(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model.getNodeData();
}

void Scene::createBuffers1()
{
    ModelLoader model1;

    if(!model1.Load(m_filepath2, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model1.getBufferData(&vertices, &normals, &indices);
    model1.getTextureData(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model1.getNodeData();
}

void Scene::createBuffers2()
{
    ModelLoader model2;

    if(!model2.Load(m_filepath3, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model2.getBufferData(&vertices, &normals, &indices);
    model2.getTextureData(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model2.getNodeData();
}

void Scene::createBuffers3()
{
    ModelLoader model3;

    if(!model3.Load(m_filepath4, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model3.getBufferData(&vertices, &normals, &indices);
    model3.getTextureData(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model3.getNodeData();
}

void Scene::createBuffers4()
{
    ModelLoader model4;

    if(!model4.Load(m_filepath5, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model4.getBufferData(&vertices, &normals, &indices);
    model4.getTextureData(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model4.getNodeData();
}

void Scene::createBuffers5()
{
    ModelLoader model5;

    if(!model5.Load(m_filepath6, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model5.getBufferData(&vertices, &normals, &indices);
    model5.getTextureData(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model5.getNodeData();
}

void Scene::createAttributes()
{
    if(m_error)
        return;

    m_vao.bind();
    // Set up the vertex array state
    m_shaderProgram.bind();

    // Map vertex data to the vertex shader's layout location '0'
    m_vertexBuffer.bind();
    m_shaderProgram.enableAttributeArray( 0 );      // layout location
    m_shaderProgram.setAttributeBuffer( 0,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        3);         // number of components (3 for x,y,z)

    // Map normal data to the vertex shader's layout location '1'
    m_normalBuffer.bind();
    m_shaderProgram.enableAttributeArray( 1 );      // layout location
    m_shaderProgram.setAttributeBuffer( 1,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        3);         // number of components (3 for x,y,z)

    if(!m_textureUVBuffer.isCreated())
        return;
    m_textureUVBuffer.bind();
    m_shaderProgram.enableAttributeArray( 2 );      // layout location
    m_shaderProgram.setAttributeBuffer( 2,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        2);         // number of components (2 for u,v)

}

void Scene::setupLightingAndMatrices()
{
    m_view.setToIdentity();
    m_view.lookAt(
                QVector3D(400.0f, 400.0f, 200.0f),    // Camera Position
                QVector3D(0.0f, 100.0f, 0.0f),    // Point camera looks towards
                QVector3D(0.0f, 1.0f, 0.0f));   // Up vector

    float aspect = 4.0f/3.0f;
    m_projection.setToIdentity();
    m_projection.perspective(
                60.0f,          // field of vision
                aspect,         // aspect ratio
                0.3f,           // near clipping plane
                1000.0f);       // far clipping plane
    m_lightInfo.Position = QVector4D( -1.0f, 1.0f, 1.0f, 1.0f );
    //m_lightInfo.Intensity = QVector3D( .5f, .5f, .f5);
    m_lightInfo.Intensity = QVector3D( 1.0f, 1.0f, 1.0f);

    m_materialInfo.Ambient = QVector3D( 0.1f, 0.05f, 0.0f );
    m_materialInfo.Diffuse = QVector3D( .9f, .6f, .2f );
    m_materialInfo.Specular = QVector3D( .2f, .2f, .2f );
    m_materialInfo.Shininess = 50.0f;
}

void Scene::resize(int w, int h)
{
    glViewport( 0, 0, w, h );

    m_projection.setToIdentity();
    m_projection.perspective(60.0f, (float)w/h, .3f, 2000);
}

void Scene::update()
{
    if(m_error)
        return;

    // Clear color and depth buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind shader program
    m_shaderProgram.bind();

    // Draw the model here, the coordinates of m_model variable is where we draw the robot
    m_model.setToIdentity();
    m_model.translate(0.0f + float(getTranslationX()) * 3, 0.0f + float(getTranslationY()) * 3, float(getTranslationZ()) * 3);
    m_model.rotate(float(getRotationX()) - 90.0f, 1.0f, 0.0f, 0.0f);
    m_model.rotate(float(getRotationY()), 0.0f, 1.0f, 0.0f);
    m_model.rotate(float(getRotationZ()) - 180.0f, 0.0f, 0.0f, 1.0f);

    // Set shader uniforms for light information
    m_shaderProgram.setUniformValue( "lightPosition", m_lightInfo.Position );
    m_shaderProgram.setUniformValue( "lightIntensity", m_lightInfo.Intensity );

    // Bind VAO and draw everything
    m_vao.bind();
    createBuffers();
    createAttributes();
    drawNode(m_rootNode.data(), QMatrix4x4());
    QMatrix4x4 reframeMatrixBase = QMatrix4x4(1.0f, 0.0f, 0.0f, 0.0f,
                                          0.0f, 1.0f, 0.0f, 0.0f,
                                          0.0f, 0.0f, 1.0f, 24.0f,
                                          0.0f, 0.0f, 0.0f, 1.0f);
    QMatrix4x4 baseMatrix = m_model * reframeMatrixBase;
    QMatrix4x4 effectorCMatrix = baseMatrix.inverted();

    QMatrix4x4 frameMatrix1 = baseMatrix;
    QMatrix4x4 frameMatrix1draw = frameMatrix1 * calculateZRotationMatrix(getAngleJ1());
    m_model = frameMatrix1draw * calculateDHMatrix(0.0f, -90.0f , 0.0f, 65.2f);
    createBuffers1(); 
    drawNode(m_rootNode.data(), QMatrix4x4());

    
    QMatrix4x4 frameMatrix2 = frameMatrix1 * calculateDHMatrix(getAngleJ1(), 90.0f, 0.0f, 65.2f);
    QMatrix4x4 frameMatrix2draw = frameMatrix2 * calculateZRotationMatrix(getAngleJ2());
    m_model = frameMatrix2draw * calculateDHMatrix(180.0f, 180.0f , 0.0f, 135.7f);
    createBuffers2();
    drawNode(m_rootNode.data(), QMatrix4x4());

    QMatrix4x4 frameMatrix3 = frameMatrix2 * calculateDHMatrix(getAngleJ2(), 0.0f, 300.0f, 0.0f);
    QMatrix4x4 frameMatrix3draw = frameMatrix3 * calculateZRotationMatrix(getAngleJ3());
    m_model = frameMatrix3draw * calculateDHMatrix(0.0f, 180.0f , 383.0f, 4.8f);
    createBuffers3();
    drawNode(m_rootNode.data(), QMatrix4x4());

    QMatrix4x4 frameMatrix4 = frameMatrix3 * calculateDHMatrix(getAngleJ3(), 0.0f, 383.0f, 0.0f);
    QMatrix4x4 frameMatrix4draw = frameMatrix4 * calculateZRotationMatrix(getAngleJ4());
    m_model = frameMatrix4draw * calculateDHMatrix(0.0f, 0.0f , 60.0f, 4.8f);
    createBuffers4();
    drawNode(m_rootNode.data(), QMatrix4x4());

    QMatrix4x4 endEffectorMatrix = frameMatrix4draw * calculateDHMatrix(0.0f, 0.0f, 33.0f, 0.0f);
    createBuffers5();
    drawNode(m_rootNode.data(), QMatrix4x4());

    QMatrix4x4 effectorMatrix = effectorCMatrix * endEffectorMatrix;
    float* pEffector = effectorMatrix.data();
    float yaw = qAtan2(*(pEffector + 1), *pEffector);
    float pitch = qAtan2(-*(pEffector + 2), qSqrt(*(pEffector + 6) * *(pEffector + 6) + *(pEffector + 10) * *(pEffector + 10)));
    float roll = qAtan2(*(pEffector + 6), *(pEffector + 10));
    MainWindow *mw = getMainWinPtr();
    mw->updateEffector(*(pEffector + 12), *(pEffector + 13), *(pEffector + 14), roll * 180 / M_PI, pitch * 180 / M_PI, yaw * 180 / M_PI  );

    m_vao.release();
}

void Scene::drawNode(const Node *node, QMatrix4x4 objectMatrix)
{
    // Prepare matrices
    objectMatrix *= node->transformation;
    QMatrix4x4 modelMatrix = m_model * objectMatrix;
    QMatrix4x4 modelViewMatrix = m_view * modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_projection * modelViewMatrix;

    m_shaderProgram.setUniformValue( "MV", modelViewMatrix );// Transforming to eye space
    m_shaderProgram.setUniformValue( "N", normalMatrix );    // Transform normal to Eye space
    m_shaderProgram.setUniformValue( "MVP", mvp );           // Matrix for transforming to Clip space

    // Draw each mesh in this node
    for(int imm = 0; imm<node->meshes.size(); ++imm)
    {
        if(node->meshes[imm]->material->Name == QString("DefaultMaterial"))
            setMaterialUniforms(m_materialInfo);
        else
            setMaterialUniforms(*node->meshes[imm]->material);

        glDrawElements( GL_TRIANGLES, node->meshes[imm]->indexCount, GL_UNSIGNED_INT
                            , (const void*)(node->meshes[imm]->indexOffset * sizeof(unsigned int)) );
    }

    // Recursively draw this nodes children nodes
    for(int inn = 0; inn<node->nodes.size(); ++inn)
        drawNode(&node->nodes[inn], objectMatrix);
}

void Scene::setMaterialUniforms(MaterialInfo &mater)
{
    m_shaderProgram.setUniformValue( "Ka", mater.Ambient );
    m_shaderProgram.setUniformValue( "Kd", mater.Diffuse );
    m_shaderProgram.setUniformValue( "Ks", mater.Specular );
    m_shaderProgram.setUniformValue( "shininess", mater.Shininess );
}

void Scene::cleanup()
{
}
