#version 330 core
in vec4 aPosition;
in vec4 aTextCoord;
out vec4 outTextCoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
   gl_Position = projMat * viewMat * modelMat * aPosition;
   outTextCoord = aTextCoord;
};
