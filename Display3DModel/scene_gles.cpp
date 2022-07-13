#include "scene_gles.h"
#include <limits>

Scene_GLES::Scene_GLES(QString filepath, ModelLoader::PathType pathType, QString texturePath) :
    m_indexBuffer(QOpenGLBuffer::IndexBuffer)
  , m_filepath(filepath)
  , m_pathType(pathType)
  , m_texturePath(texturePath)
  , m_error(false)
{

}

void Scene_GLES::initialize()
{
    this->initializeOpenGLFunctions();

    // OpenGL 2.1/OpenGL ES -- Shaders languages is different
    createShaderProgram(":/es_ads_fragment.vert", ":/es_ads_fragment.frag");

    createBuffers();
    // OpenGL 2.1/OpenGL ES -- There are no VAO's in OpenGL 2.1/OpenGL ES, so we don't set up the attributes here
    setupLightingAndMatrices();

    glEnable(GL_DEPTH_TEST);
    if (QOpenGLContext::currentContext()->format().renderableType() == QSurfaceFormat::OpenGLES)
        glClearColor(.5f, .5f, .5f ,1.0f);
    else
        glClearColor(.9f, .9f, .93f ,1.0f);

}

void Scene_GLES::createShaderProgram(QString vShader, QString fShader)
{
    // Compile vertex shader
    if ( !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, vShader.toUtf8() ) )
        qCritical() << "Unable to compile vertex shader. Log:" << m_shaderProgram.log();

    // Compile fragment shader
    if ( !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, fShader.toUtf8() ) )
        qCritical() << "Unable to compile fragment shader. Log:" << m_shaderProgram.log();

    // OpenGL 2.1/OpenGL ES -- Vertex shader attributes need to be mapped to location before shader is linked
    m_shaderProgram.bindAttributeLocation("vertexPosition", 0);
    m_shaderProgram.bindAttributeLocation("vertexNormal", 1);

    // Link the shaders together into a program
    if ( !m_shaderProgram.link() )
        qCritical() << "Unable to link shader program. Log:" << m_shaderProgram.log();
}

void Scene_GLES::createBuffers()
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

    if (QOpenGLContext::currentContext()->format().renderableType() == QSurfaceFormat::OpenGLES &&
            vertices->size() > std::numeric_limits<unsigned short>::max())
        qDebug() << "WARNING: OpenGL ES 2.0 index buffer types do not support 32-bit integers, "
                    "so vertex buffers cannot have more than std::numeric_limits<unsigned short>::max() vertices, "
                    "this model has more than than std::numeric_limits<unsigned short>::max() vertices so will likely not render correctly";

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

    if (QOpenGLContext::currentContext()->format().renderableType() == QSurfaceFormat::OpenGLES) {
        // OpenGL ES -- unsigned long int type indexes are not supported, use unsigned short instead
        // This means the number of vertices in a single vertex buffer is limited to std::numeric_limits<unsigned short>::max()

        QVector<unsigned short> shortindices;
        shortindices.resize(indices->size());
        std::copy(indices->begin(), indices->end(), shortindices.begin());
        m_indexBuffer.allocate( &(shortindices)[0], shortindices.size() * sizeof( unsigned short ) );
    }
    else
        m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model.getNodeData();

    m_vertexBuffer.release();
    m_normalBuffer.release();
    m_indexBuffer.release();
}

void Scene_GLES::createAttributes()
{
    if(m_error)
        return;

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

void Scene_GLES::setupLightingAndMatrices()
{
    m_view.setToIdentity();
    m_view.lookAt(
                QVector3D(0.0f, 0.0f, 1.2f),    // Camera Position
                QVector3D(0.0f, 0.0f, 0.0f),    // Point camera looks towards
                QVector3D(0.0f, 1.0f, 0.0f));   // Up vector

    float aspect = 4.0f/3.0f;
    m_projection.setToIdentity();
    m_projection.perspective(
                60.0f,          // field of vision
                aspect,         // aspect ratio
                0.3f,           // near clipping plane
                1000.0f);       // far clipping plane


    if (QOpenGLContext::currentContext()->format().renderableType() == QSurfaceFormat::OpenGLES)
        m_lightInfo.Position = QVector4D( 1.0f, 1.0f, 1.0f, 1.0f );
    else
        m_lightInfo.Position = QVector4D( -1.0f, 1.0f, 1.0f, 1.0f );
    //m_lightInfo.Intensity = QVector3D( .5, .5, .5);
    m_lightInfo.Intensity = QVector3D( 1.0f, 1.0f, 1.0f);

    m_materialInfo.Ambient = QVector3D( 0.1f, 0.05f, 0.0f );
    m_materialInfo.Diffuse = QVector3D( .9f, .6f, .2f );
    m_materialInfo.Specular = QVector3D( .2f, .2f, .2f );
    m_materialInfo.Shininess = 50.0f;
}

void Scene_GLES::resize(int w, int h)
{
    glViewport( 0, 0, w, h );

    m_projection.setToIdentity();
    m_projection.perspective(60.0f, (float)w/h, .3f, 1000);
}

void Scene_GLES::update()
{
    if(m_error)
        return;

    // Clear color and depth buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind shader program
    m_shaderProgram.bind();

    // Set the model matrix
    // Translate and rotate it a bit to get a better view
    m_model.setToIdentity();
    if (QOpenGLContext::currentContext()->format().renderableType() != QSurfaceFormat::OpenGLES) {
        m_model.translate(-0.2f, 0.0f, .5f);
        m_model.rotate(55.0f, 0.0f, 1.0f, 0.0f);
    }

    // Set shader uniforms for light information
    m_shaderProgram.setUniformValue( "lightPosition", m_lightInfo.Position );
    m_shaderProgram.setUniformValue( "lightIntensity", m_lightInfo.Intensity );

    // OpenGL 2.1/OpenGL ES -- set attributes (with GL 3.3 we would just need to bind the VAO)
    createAttributes();

    m_indexBuffer.bind();
    // Bind VAO and draw everything
    drawNode(m_rootNode.data(), QMatrix4x4());

    m_indexBuffer.release();
}

void Scene_GLES::drawNode(const Node *node, QMatrix4x4 objectMatrix)
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

        if (QOpenGLContext::currentContext()->format().renderableType() == QSurfaceFormat::OpenGLES) {
            // OpenGL ES -- unsigned long int type indexes are not supported, use unsigned short instead
            glDrawElements( GL_TRIANGLES, node->meshes[imm]->indexCount, GL_UNSIGNED_SHORT
                                , (const void*)(node->meshes[imm]->indexOffset * sizeof(unsigned short)) );
        }
        else {
            glDrawElements( GL_TRIANGLES, node->meshes[imm]->indexCount, GL_UNSIGNED_INT
                                , (const void*)(node->meshes[imm]->indexOffset * sizeof(unsigned int)) );
        }
    }

    // Recursively draw this nodes children nodes
    for(int inn = 0; inn<node->nodes.size(); ++inn)
        drawNode(&node->nodes[inn], objectMatrix);
}

void Scene_GLES::setMaterialUniforms(MaterialInfo &mater)
{
    m_shaderProgram.setUniformValue( "Ka", mater.Ambient );
    m_shaderProgram.setUniformValue( "Kd", mater.Diffuse );
    m_shaderProgram.setUniformValue( "Ks", mater.Specular );
    m_shaderProgram.setUniformValue( "shininess", mater.Shininess );
}

void Scene_GLES::cleanup()
{
}
