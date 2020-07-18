/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：3D模型父类，封装了模型的公共方法
 * 包括模型位移，旋转
 * VAO，VBO，EBO的创建，绑定，释放，销毁等
 * 模型矩阵，观察矩阵，投影矩阵的设置和获取
 * ***************************************/

#ifndef OBJECTPARENT_H
#define OBJECTPARENT_H
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <QOpenGLWidget>
#include "../texturelibrary.h"
#include "../shaderlibrary.h"
#include "../cameralibrary.h"

typedef struct VertexData
{
    QVector3D vertexPosition;
    QVector2D textureCoord;
} VertexData;

class ObjectParent : public QObject
{
    Q_OBJECT
public:
    ObjectParent();
    virtual ~ObjectParent();
    void bind();
    void release();
    void destory();
    virtual void makeObject();
    virtual void drawObject();
    virtual void setupObjectShaderMat();
    void setupShader(const QString &vertexPath, const QString &fragmentPath);
    void setupTexture(const QImage &image);
    void setupTexture(const QString &imagePath);
    void setupTexture(const QList<QString> &imagePathList);
    void setWindowWidth(const int &windowWidth);
    void setWindowHeight(const int &windowHeight);
    void setWindowSize(const int &windowWidth, const int &windowHeight);
    void translateByX(const GLfloat &valueData);
    void translateByY(const GLfloat &valueData);
    void translateByZ(const GLfloat &valueData);
    void rotateByX(const GLfloat &angleData);
    void rotateByY(const GLfloat &angleData);
    void rotateByZ(const GLfloat &angleData);
    void setupPerspective(const GLfloat &angleData);
    void setOpenGLFunctions(QOpenGLFunctions *openGLFunctions);
    void setOpenGLWidget(QOpenGLWidget *openGLWidget);
    void setCameraLibrary(CameraLibrary *cameraLibrary);
    int getVertexCount();


signals:
    void sendUpdate();
protected:
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLBuffer m_ebo;
    ShaderLibrary m_shaderLibrary;
    TextureLibrary m_textureLibrary;
    CameraLibrary *m_cameraLibrary;
    QMatrix4x4 m_modelMat;
    QMatrix4x4 m_viewMat;
    QMatrix4x4 m_projMat;
    QOpenGLFunctions *m_openGLFunctions = nullptr;
    QOpenGLWidget *m_openGLWidget = nullptr;
    int m_windowWidth;
    int m_windowHeight;
};

#endif // OBJECTPARENT_H
