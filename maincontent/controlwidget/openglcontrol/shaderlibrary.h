/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：着色器的封装，配合GLSL使用
 * 将着色器语言进行编译和绑定
 * ***************************************/

#ifndef SHADERLIBRARY_H
#define SHADERLIBRARY_H

#include <QObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>

class ShaderLibrary : public QOpenGLShaderProgram
{
    Q_OBJECT
public:
    explicit ShaderLibrary(QObject *parent = nullptr);
    ~ShaderLibrary();
    bool compileAndBindShaderFile(const QString &vertexPath, const QString &fragmentPath);
    void setupAndEnableGlslValue(const QString &attributeName, const int &offset, const int &tupleSize, const int &stride);
};

#endif // SHADERLIBRARY_H
