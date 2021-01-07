#version 330 core
in vec4 outTextCoord;
uniform sampler2D textureImage;

void main()
{
  gl_FragColor = texture2D(textureImage, outTextCoord.st);
};
