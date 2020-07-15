/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：相机封装，设置相机在世界中的位置，
 * 以及对相机进行移动，两种设置相机方法
 * 1.设置相机位置，看向目标位置，以及世界的向上向量
 * 2.设置相机位置，通过欧拉角进行计算
 * 主要目的是能够获取到相机的观察矩阵
 * ***************************************/

#include "cameralibrary.h"
#include <QtMath>

CameraLibrary::CameraLibrary(QObject *parent) : QObject(parent)
{

}

void CameraLibrary::setupCamera(QVector3D position, QVector3D target, QVector3D worldUp)
{
    m_position = position;
    m_worldup = worldUp;

    m_forward = target - m_position;
    m_forward.normalize();

    // 先正交，再取单位向量
    m_right = m_right.crossProduct(m_forward, m_worldup);
    m_right.normalize();

    // 先正交，再取单位向量
    m_up = m_up.crossProduct(m_forward, m_right);
    m_up.normalize();
}

void CameraLibrary::setupCamera(QVector3D position, float pitch, float yaw, QVector3D worldUp)
{
    m_pitch = qDegreesToRadians(pitch);
    m_yaw = qDegreesToRadians(yaw);
    m_position = position;
    m_worldup = worldUp;

    // pitch代表俯仰角，x代表俯仰角度
    // yaw代表左右角,y代表左右角度
    // x =  cosx * siny
    // y = sinx
    // z = cosx * cosy
    m_forward.setX(cos(pitch) * sin(yaw));
    m_forward.setY(sin(pitch));
    m_forward.setZ(cos(pitch) * cos(yaw));

    // 先正交，再取单位向量
    m_right = m_right.crossProduct(m_forward, m_worldup);
    m_right.normalize();

    // 先正交，再取单位向量
    m_up = m_up.crossProduct(m_forward, m_right);
    m_up.normalize();
}

QVector3D CameraLibrary::getPosition() const
{
    return m_position;
}

CameraLibrary::~CameraLibrary()
{

}

void CameraLibrary::setPitch(float pitch)
{
    m_pitch = qDegreesToRadians(pitch);
    this->updateVector();
}

void CameraLibrary::setYaw(float yaw)
{
    m_yaw = qDegreesToRadians(yaw);
    this->updateVector();
}

void CameraLibrary::moveToForward()
{
    m_position += m_forward * 1.5f;
}

void CameraLibrary::moveToBackward()
{
    m_position += m_forward * -1.5f;
}

void CameraLibrary::moveToLeft()
{
    m_position += m_right * -0.1f;
}

void CameraLibrary::moveToRight()
{
    m_position += m_right * 0.1f;
}

void CameraLibrary::moveToUp()
{
    m_position += m_up * -0.1f;
}

void CameraLibrary::moveToDown()
{
    m_position += m_up * 0.1f;
}

void CameraLibrary::processMouseEvent(float deltaX, float deltaY)
{
    m_pitch += deltaY * 0.001f;
    m_yaw += deltaX * 0.001f;
    this->updateVector();
}

QMatrix4x4 CameraLibrary::getViewMat4x4()
{
    QMatrix4x4 matrix;

    // 参数1：相机位置
    // 参数2：相机观察的中心点
    // 参数3：相机的法线向量
    matrix.lookAt(m_position, m_forward + m_position, m_worldup);
    return matrix;
}

void CameraLibrary::updateVector()
{
    m_forward.setX(cos(m_pitch) * sin(m_yaw));
    m_forward.setY(sin(m_pitch));
    m_forward.setZ(cos(m_pitch) * cos(m_yaw));

    m_right = m_right.crossProduct(m_forward, m_worldup);
    m_right.normalize();

    m_up = m_up.crossProduct(m_forward, m_right);
    m_up.normalize();
}
