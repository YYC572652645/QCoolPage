/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：3D模型父类，封装了模型的公共方法
 * 包括模型位移，旋转
 * VAO，VBO，EBO的创建，绑定，释放，销毁等
 * 模型矩阵，观察矩阵，投影矩阵的设置和获取
 * ***************************************/

#include "objectparent.h"


ObjectParent::ObjectParent() : m_vbo(QOpenGLBuffer::VertexBuffer), m_ebo(QOpenGLBuffer::IndexBuffer)
{
}

ObjectParent::~ObjectParent()
{
}

void ObjectParent::bind()
{
    m_shaderLibrary.bind();
    m_textureLibrary.bindAll();
    m_vao.bind();
}

void ObjectParent::release()
{
    m_textureLibrary.releaseAll();
    m_shaderLibrary.release();
    if (m_vao.isCreated())
    {
        m_vao.release();
    }
}

void ObjectParent::destory()
{
    if (m_vbo.isCreated())
    {
        m_vbo.destroy();
    }
    if (m_ebo.isCreated())
    {
        m_ebo.destroy();
    }
    if (m_vao.isCreated())
    {
        m_vao.destroy();
    }
    m_textureLibrary.destoryAll();
}

void ObjectParent::setupShader(const QString &vertexPath, const QString &fragmentPath)
{
    bool successFlage = m_shaderLibrary.compileAndBindShaderFile(vertexPath, fragmentPath);
    if(!successFlage)
    {
        qDebug() << "Compile shader error!";
    }
}

void ObjectParent::setupTexture(const QImage &image)
{
    if (nullptr != m_openGLWidget)
    {
        m_openGLWidget->makeCurrent();
    }
    m_textureLibrary.clearTexture();
    m_textureLibrary.appendGlTexture(image);
    if (nullptr != m_openGLWidget)
    {
        m_openGLWidget->doneCurrent();
    }
}

void ObjectParent::setupTexture(const QString &imagePath)
{
    m_textureLibrary.clearTexture();
    m_textureLibrary.appendGlTexture(imagePath);
}

void ObjectParent::setupTexture(const QList<QString> &imagePathList)
{
    m_textureLibrary.generateTexture(imagePathList);
}

void ObjectParent::setWindowWidth(const int &windowWidth)
{
    m_windowWidth = windowWidth;
}

void ObjectParent::setWindowHeight(const int &windowHeight)
{
    m_windowHeight = windowHeight;
}

void ObjectParent::setWindowSize(const int &windowWidth, const int &windowHeight)
{
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
}

void ObjectParent::translateByX(const GLfloat &valueData)
{
    m_modelMat.translate(valueData, 0.0f, 0.0f);
}

void ObjectParent::translateByY(const GLfloat &valueData)
{
    m_modelMat.translate(0.0f, valueData, 0.0f);
}

void ObjectParent::translateByZ(const GLfloat &valueData)
{
    m_modelMat.translate(0.0f, 0.0f, valueData);
}

void ObjectParent::rotateByX(const GLfloat &angleData)
{
    m_modelMat.rotate(angleData, 1.0f, 0.0f, 0.0f);
}

void ObjectParent::rotateByY(const GLfloat &angleData)
{
    m_modelMat.rotate(angleData, 0.0f, 1.0f, 0.0f);
}

void ObjectParent::rotateByZ(const GLfloat &angleData)
{
    m_modelMat.rotate(angleData, 0.0f, 0.0f, 1.0f);
}

void ObjectParent::setupPerspective(const GLfloat &angleData)
{
    if (m_windowWidth != 0 && m_windowHeight != 0)
    {
        m_projMat.perspective(angleData, 1.0 * m_windowWidth / m_windowHeight, 0.1f, 100.0f);
    }
}

int ObjectParent::getVertexCount()
{
    return m_ebo.size() / sizeof(GLfloat);
}

void ObjectParent::setCameraLibrary(CameraLibrary *cameraLibrary)
{
    m_cameraLibrary = cameraLibrary;
}

void ObjectParent::setOpenGLFunctions(QOpenGLFunctions *openGLFunctions)
{
    m_openGLFunctions = openGLFunctions;
}

void ObjectParent::setOpenGLWidget(QOpenGLWidget *openGLWidget)
{
    m_openGLWidget = openGLWidget;
    m_textureLibrary.setOpenGLWidget(m_openGLWidget);
}

void ObjectParent::setupObjectShaderMat()
{
    if (nullptr != m_cameraLibrary)
    {
        m_viewMat = m_cameraLibrary->getViewMat4x4();
    }
    m_shaderLibrary.setUniformValue("modelMat", m_modelMat);
    m_shaderLibrary.setUniformValue("viewMat", m_viewMat);
    m_shaderLibrary.setUniformValue("projMat", m_projMat);
}

void ObjectParent::makeObject()
{

}

void ObjectParent::drawObject()
{
    if (nullptr != m_openGLFunctions)
    {
        this->bind();
        this->setupObjectShaderMat();
        m_openGLFunctions->glDrawElements(GL_TRIANGLES, this->getVertexCount(), GL_UNSIGNED_INT, nullptr);
        this->release();
    }
}
