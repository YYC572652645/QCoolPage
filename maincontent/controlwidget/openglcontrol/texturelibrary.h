/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：纹理库的封装，配合GLSL使用
 * 可以创建多个纹理进行绑定
 * ***************************************/

#ifndef TEXTURELIBRARY_H
#define TEXTURELIBRARY_H
#include <QOpenGLTexture>
#include <QOpenGLWidget>

class TextureLibrary : public QObject
{
public:
    explicit TextureLibrary(QObject *parent = nullptr);
    ~TextureLibrary();

    void setOpenGLWidget(QOpenGLWidget *openGLWidget);
    void generateTexture(const QList<QString> &imagePathList);
    void appendGlTexture(const QList<QString> &imagePathList);
    void appendGlTexture(const QString &imagePath);
    void appendGlTexture(const QImage &image);
    void bind(const int &index);
    void release(const int &index);
    void destory(const int &index);
    void bindAll();
    void releaseAll();
    void destoryAll();
    void clearTexture();

private:
    QOpenGLTexture *createGlTexture(const QImage &image);
    QOpenGLTexture *createGlTexture(const QString &imagePath);
private:
    QList<QOpenGLTexture*> m_glTextureList;
    QOpenGLWidget *m_openGLWidget = nullptr;
};

#endif // TEXTURELIBRARY_H
