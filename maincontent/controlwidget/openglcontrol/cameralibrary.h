/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：相机封装，设置相机在世界中的位置，
 * 以及对相机进行移动，两种设置相机方法
 * 1.设置相机位置，看向目标位置，以及世界的向上向量
 * 2.设置相机位置，通过欧拉角进行计算
 * 主要目的是能够获取到相机的观察矩阵
 * ***************************************/

#ifndef CAMERALIBRARY_H
#define CAMERALIBRARY_H

#include <QObject>
#include <QVector3D>
#include <QMatrix4x4>

class CameraLibrary : public QObject
{
    Q_OBJECT
public:
    explicit CameraLibrary(QObject *parent = nullptr);
    ~CameraLibrary();
    QMatrix4x4 getViewMat4x4();
    void setPitch(float pitch);
    void setYaw(float yaw);
    void moveToForward();
    void moveToBackward();
    void moveToLeft();
    void moveToRight();
    void moveToUp();
    void moveToDown();
    void setupCamera(QVector3D position, QVector3D target, QVector3D worldUp);
    void setupCamera(QVector3D position, float pitch, float yaw, QVector3D worldUp);
    void processMouseEvent(float deltaX, float deltaY);
    QVector3D getPosition() const;

private:

    float m_yaw;
    float m_pitch;
    QVector3D m_position;
    QVector3D m_forward;
    QVector3D m_right;
    QVector3D m_up;
    QVector3D m_worldup;

    void updateVector();
};

#endif // CAMERALIBRARY_H
