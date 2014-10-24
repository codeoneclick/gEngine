
#if defined(__OPENGL_30__)

out vec2   OUT_TexCoord;
out vec2   OUT_Position;

#else

varying vec2   OUT_TexCoord;
varying vec2   OUT_Position;

#endif

uniform mat4   MATRIX_Projection;
uniform mat4   MATRIX_View;
uniform mat4   MATRIX_World;
uniform vec4   VECTOR_ClipPlane;
uniform vec3   VECTOR_CameraPosition;

void main(void)
{
    vec4 vPosition = vec4(IN_Position, 1.0);
    gl_Position = MATRIX_Projection * MATRIX_View * vPosition;
    OUT_TexCoord = (IN_TexCoord / 32767.0  - 1.0);
    OUT_Position = vPosition.xz;
}