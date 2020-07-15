/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：四边形模型，指定角度和纹理创建模型
 * ***************************************/
#include "objectcube.h"
#include "../opengldef.h"
#include <QDebug>

ObjectCube::ObjectCube()
{

}

ObjectCube::~ObjectCube()
{
}

void ObjectCube::makeObject()
{
    m_vao.create();
    m_vao.bind();

    float xPos = 2;
    float yPos = 2;
    float zPos = 2;

    VertexData vertices[] =
    {
        // Vertex data for face 0
        {QVector3D(-xPos, -yPos,  zPos), QVector2D(0.0f, 0.0f)}, // v0
        {QVector3D( xPos, -yPos,  zPos), QVector2D(1.0f, 0.0f)}, // v1
        {QVector3D(-xPos,  yPos,  zPos), QVector2D(0.0f, 1.0f)}, // v2
        {QVector3D( xPos,  yPos,  zPos), QVector2D(1.0f, 1.0f)}, // v3

        // Vertex data for face 1
        {QVector3D( xPos, -yPos,  zPos), QVector2D(0.0f, 0.0f)}, // v4
        {QVector3D( xPos, -yPos, -zPos), QVector2D(1.0f, 0.0f)}, // v5
        {QVector3D( xPos,  yPos,  zPos), QVector2D(0.0f, 1.0f)}, // v6
        {QVector3D( xPos,  yPos, -zPos), QVector2D(1.0f, 1.0f)}, // v7

        // Vertex data for face 2
        {QVector3D( xPos, -yPos, -zPos), QVector2D(0.0f, 0.0f)},  // v8
        {QVector3D(-xPos, -yPos, -zPos), QVector2D(1.0f, 0.0f)},  // v9
        {QVector3D( xPos,  yPos, -zPos), QVector2D(0.0f, 1.0f)},  // v10
        {QVector3D(-xPos,  yPos, -zPos), QVector2D(1.0f, 1.0f)},  // v11

        // Vertex data for face 3
        {QVector3D(-xPos, -yPos, -zPos), QVector2D(0.0f, 0.0f)},  // v12
        {QVector3D(-xPos, -yPos,  zPos), QVector2D(1.0f, 0.0f)},  // v13
        {QVector3D(-xPos,  yPos, -zPos), QVector2D(0.0f, 1.0f)},  // v14
        {QVector3D(-xPos,  yPos,  zPos), QVector2D(1.0f, 1.0f)},  // v15

        // Vertex data for face 4
        {QVector3D(-xPos, -yPos, -zPos), QVector2D(0.0f, 0.0f)}, // v16
        {QVector3D( xPos, -yPos, -zPos), QVector2D(1.0f, 0.0f)}, // v17
        {QVector3D(-xPos, -yPos,  zPos), QVector2D(0.0f, 1.0f)}, // v18
        {QVector3D( xPos, -yPos,  zPos), QVector2D(1.0f, 1.0f)}, // v19

        // Vertex data for face 5
        {QVector3D(-xPos,  yPos,  zPos), QVector2D(0.0f, 0.0f)}, // v20
        {QVector3D( xPos,  yPos,  zPos), QVector2D(1.0f, 0.0f)}, // v21
        {QVector3D(-xPos,  yPos, -zPos), QVector2D(0.0f, 1.0f)}, // v22
        {QVector3D( xPos,  yPos, -zPos), QVector2D(1.0f, 1.0f)}  // v23
    };

    GLushort indices[] =
    {
        0,  1,  2,  1,  2,  3,   // Face 0
        4,  5,  6,  5,  6,  7,   // Face 1
        8,  9,  10, 9,  10, 11,  // Face 2
        12, 13, 14, 13, 14, 15,  // Face 3
        16, 17, 18, 17, 18, 19,  // Face 4
        20, 21, 22, 21, 22, 23   // Face 5
    };

    QVector<int> eboData;
    QVector<VertexData> vboData;
    for (int i = 0; i < 24; i++)
    {
        vboData.append(vertices[i]);
    }

    for (int i = 0; i < 36; i++)
    {
        eboData.append(indices[i]);
    }

    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(vboData.constData(), vboData.count() * sizeof(VertexData));

    m_ebo.create();
    m_ebo.bind();
    m_ebo.allocate(eboData.constData(), eboData.count() * sizeof(int));

    m_shaderLibrary.setupAndEnableGlslValue("aPosition", 0, 3, 5 * sizeof(GLfloat));
    m_shaderLibrary.setupAndEnableGlslValue("aTextCoord", sizeof(QVector3D), 2, 5 * sizeof(GLfloat));
    m_shaderLibrary.setUniformValue("textureImage", 0);
    m_vbo.release();
}
