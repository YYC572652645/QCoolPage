#ifdef GL_ES
precision mediump int;
precision mediump float;
#endif

varying vec2 outTextCoord;
uniform sampler2D textureImage;

void main()
{
    gl_FragColor = texture2D(textureImage, outTextCoord);
}
