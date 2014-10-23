
#if defined(__OPENGL_30__)

out vec2   OUT_TexCoord;

#else

varying vec2   OUT_TexCoord;

#endif

uniform mat4   MATRIX_Projection;
uniform mat4   MATRIX_View;
uniform mat4   MATRIX_World;

void main(void)
{
    OUT_TexCoord = IN_TexCoord / 32767.0  - 1.0;
    gl_Position = vec4(IN_Position, 1.0);
}
