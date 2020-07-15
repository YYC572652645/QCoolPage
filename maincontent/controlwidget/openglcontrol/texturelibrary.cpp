/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：纹理库的封装，配合GLSL使用
 * 可以创建多个纹理进行绑定
 * ***************************************/

#include "texturelibrary.h"

TextureLibrary::TextureLibrary(QObject *parent) : QObject(parent)
{

}

TextureLibrary::~TextureLibrary()
{
}

void TextureLibrary::generateTexture(const QList<QString> &imagePathList)
{
    if (!m_glTextureList.isEmpty())
    {
        this->clearTexture();
    }

    for (QString imagePath : imagePathList)
    {
        this->appendGlTexture(imagePath);
    }
}

void TextureLibrary::clearTexture()
{
    for (QOpenGLTexture* glTexture : m_glTextureList)
    {
        if (nullptr != glTexture)
        {
            if (glTexture->isCreated())
            {
                glTexture->destroy();
            }
            delete glTexture;
            glTexture = nullptr;
        }
    }
    m_glTextureList.clear();
}

void TextureLibrary::appendGlTexture(const QList<QString> &imagePathList)
{
    for (auto imagePath : imagePathList)
    {
        this->createGlTexture(imagePath);
    }
}

void TextureLibrary::appendGlTexture(const QString &imagePath)
{
    m_glTextureList.append(this->createGlTexture(imagePath));
}

void TextureLibrary::appendGlTexture(const QImage &image)
{
    if (!image.isNull())
    {
        m_glTextureList.append(this->createGlTexture(image.mirrored()));
    }
}

void TextureLibrary::destory(const int &index)
{
    if (index >= 0 && index < m_glTextureList.size())
    {
        if (nullptr != m_openGLWidget)
        {
            m_openGLWidget->makeCurrent();
        }
        if (m_glTextureList[index]->isCreated())
        {
            m_glTextureList[index]->destroy();
        }
        delete m_glTextureList[index];
        m_glTextureList[index] = nullptr;
        m_glTextureList.removeAt(index);
        if (nullptr != m_openGLWidget)
        {
            m_openGLWidget->doneCurrent();
        }
    }
}

void TextureLibrary::bind(const int &index)
{
    if (index >= 0 && index < m_glTextureList.size())
    {
        m_glTextureList[index]->bind();
    }
}

void TextureLibrary::bindAll()
{
    for(QOpenGLTexture* glTexture : m_glTextureList)
    {
        glTexture->bind();
    }
}

void TextureLibrary::release(const int &index)
{
    if (index >= 0 && index < m_glTextureList.size())
    {
        if (m_glTextureList[index]->isCreated())
        {
            m_glTextureList[index]->release();
        }
    }
}

void TextureLibrary::releaseAll()
{
    for(QOpenGLTexture* glTexture : m_glTextureList)
    {
        if (glTexture->isCreated())
        {
            glTexture->release();
        }
    }
}

void TextureLibrary::destoryAll()
{
    for (int i = m_glTextureList.size() - 1; i >= 0; i--)
    {
        this->destory(i);
    }
}

QOpenGLTexture *TextureLibrary::createGlTexture(const QImage &image)
{
    QOpenGLTexture *glTexture = new QOpenGLTexture(image);

    glTexture->allocateStorage(QOpenGLTexture::RGB, QOpenGLTexture::UInt8);

    glTexture->setMagnificationFilter(QOpenGLTexture::Linear);

    glTexture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);

    return glTexture;
}

QOpenGLTexture *TextureLibrary::createGlTexture(const QString &imagePath)
{
    QOpenGLTexture *glTexture = new QOpenGLTexture(QImage(imagePath).mirrored());

    glTexture->setMinificationFilter(QOpenGLTexture::Nearest);

    glTexture->setMagnificationFilter(QOpenGLTexture::Linear);

    glTexture->setWrapMode(QOpenGLTexture::Repeat);

    return glTexture;
}

void TextureLibrary::setOpenGLWidget(QOpenGLWidget *openGLWidget)
{
    m_openGLWidget = openGLWidget;
}

