#ifdef GL_ES
precision mediump int;
precision mediump float;
#endif

attribute vec4 aPosition;
attribute vec2 aTextCoord;
varying vec2 outTextCoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
   gl_Position = projMat * viewMat * modelMat * aPosition;
   outTextCoord = aTextCoord;
}
