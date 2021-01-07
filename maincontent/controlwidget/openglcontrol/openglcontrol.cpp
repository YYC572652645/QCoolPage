/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：3D场景，用于3D模型的显示
 * ***************************************/

#include "openglcontrol.h"
#include <QMouseEvent>
#include <QVector3D>
#include <QDebug>
#include "opengldef.h"
#include <QtGlobal>

OpenglControl::OpenglControl(QWidget *parent) :
    QOpenGLWidget(parent)
{
}

OpenglControl::~OpenglControl()
{
    this->makeCurrent();
    for (ObjectParent* objectModel : m_objectList)
    {
        objectModel->deleteLater();
    }
    this->doneCurrent();
}

void OpenglControl::initializeGL()
{
    this->initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    const int OBJECT_NUMBER = 35;
    for (int i = 0; i < OBJECT_NUMBER; i++)
    {
        m_objectList.append(OBJECT_FACTORY->makeObject(ObjectFactory::OBJECT_CUBE));
    }

    m_cameraLibrary.setupCamera(OpenglSpace::CAMERA_POS, OpenglSpace::TARGET_POS, OpenglSpace::WORLD_UP);
    for (int i = 0; i < m_objectList.size(); i++)
    {
        m_objectList.at(i)->setWindowSize(width(), height());
        m_objectList.at(i)->setCameraLibrary(&m_cameraLibrary);
#ifdef Q_OS_WIN
        m_objectList.at(i)->setupShader(OpenglSpace::VERTEX_WIN_PATH, OpenglSpace::FRAMENT_WIN_PATH);
#else
        m_objectList.at(i)->setupShader(OpenglSpace::VERTEX_UNIX_PATH, OpenglSpace::FRAMENT_UNIX_PATH);
#endif
        m_objectList.at(i)->setupPerspective(45.0f);
        m_objectList.at(i)->makeObject();
        m_objectList.at(i)->setOpenGLFunctions(this);
        m_objectList.at(i)->setOpenGLWidget(this);
        m_objectList.at(i)->setupTexture(OpenglSpace::CONTAINER_PATH);
        m_objectList.at(i)->translateByX(rand() % 50 - 25.0f);
        m_objectList.at(i)->translateByY(rand() % 50 - 25.0f);
        m_objectList.at(i)->translateByZ(rand() % 100);
        m_objectList.at(i)->rotateByY(rand() % 100 - 100.0f);
    }
}

void OpenglControl::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenglControl::paintGL()
{
    glClearColor(static_cast<GLclampf>(OpenglSpace::CLEAR_COLOR.redF())
                 , static_cast<GLclampf>(OpenglSpace::CLEAR_COLOR.greenF())
                 , static_cast<GLclampf>(OpenglSpace::CLEAR_COLOR.blueF())
                 , static_cast<GLclampf>(OpenglSpace::CLEAR_COLOR.alphaF()));


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto objectModel : m_objectList)
    {
        objectModel->drawObject();
    }
    glFlush();
}

void OpenglControl::wheelEvent(QWheelEvent *wheelEvent)
{
    if(wheelEvent->delta() > 0)
    {
        m_cameraLibrary.moveToForward();
    }
    else
    {
        m_cameraLibrary.moveToBackward();
    }
    this->update();
}
