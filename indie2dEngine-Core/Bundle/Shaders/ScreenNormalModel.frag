varying lowp  vec3   OUT_LightPosition;
varying lowp  vec3   OUT_Normal;
varying highp vec2   OUT_TexCoord;
varying lowp  float  OUT_ClipPlane;
varying highp vec4   OUT_Position;
varying highp float  OUT_Depth;

uniform sampler2D SAMPLER_01;

void main(void)
{
    if(OUT_ClipPlane < 0.0)
        discard;
    highp float depth = (OUT_Depth + 1.0) * 0.5;
    gl_FragColor = vec4( depth, depth, depth, 1.0); //vec4(0.5 * OUT_Normal + vec3(0.5), 1.0);
}