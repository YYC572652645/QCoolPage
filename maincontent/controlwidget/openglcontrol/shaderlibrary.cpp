/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：着色器的封装，配合GLSL使用
 * 将着色器语言进行编译和绑定
 * ***************************************/

#include "shaderlibrary.h"

ShaderLibrary::ShaderLibrary(QObject *parent) : QOpenGLShaderProgram(parent)
{
}

ShaderLibrary::~ShaderLibrary()
{
}

bool ShaderLibrary::compileAndBindShaderFile(const QString &vertexPath, const QString &fragmentPath)
{
    if (vertexPath.isEmpty() || fragmentPath.isEmpty())
    {
        return false;
    }

    if (!this->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexPath))
    {
        return false;
    }

    if (!this->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentPath))
    {
        return false;
    }

    if (!this->link())
    {
        return false;
    }

    if (!this->bind())
    {
        return false;
    }

    return true;
}

void ShaderLibrary::setupAndEnableGlslValue(const QString &attributeName, const int &offset, const int &tupleSize, const int &stride)
{
    int vPosition = this->attributeLocation(attributeName);
    this->setAttributeBuffer(vPosition, GL_FLOAT, offset, tupleSize, stride);
    this->enableAttributeArray(vPosition);
}

