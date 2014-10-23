
#if defined(__OPENGL_30__)

in  vec2 OUT_TexCoord;
in  vec4 OUT_Color;

#else

varying  vec2 OUT_TexCoord;
varying  vec4 OUT_Color;

#endif

uniform sampler2D SAMPLER_01;

void main(void)
{
    gl_FragColor = texture2D(SAMPLER_01, OUT_TexCoord) * OUT_Color;
}

