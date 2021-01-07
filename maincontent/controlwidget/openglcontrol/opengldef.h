#ifndef OPENGLDEF_H
#define OPENGLDEF_H
#include <QColor>
#include <QString>
#include <QVector3D>

namespace OpenglSpace
{
const QColor CLEAR_COLOR = QColor(26, 26, 26);
const QString VERTEX_WIN_PATH = ":/shader/vertex_windows.glsl";
const QString FRAMENT_WIN_PATH = ":/shader/frament_windows.glsl";
const QString VERTEX_UNIX_PATH = ":/shader/vertex_linux.glsl";
const QString FRAMENT_UNIX_PATH = ":/shader/frament_linux.glsl";
const QString CONTAINER_PATH = ":/texture/container.jpg";

// 方向向量
const QVector3D CAMERA_POS = QVector3D(0.0f, 0.0f, 99.0f);
const QVector3D TARGET_POS = QVector3D(0.0f, 0.0f, 0.0f);
const QVector3D WORLD_UP = QVector3D(0.0f, 1.0f, 0.0f);
}

#endif // OPENGLDEF_H
