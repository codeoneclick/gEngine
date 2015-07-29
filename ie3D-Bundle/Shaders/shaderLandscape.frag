#if defined(__OPENGL_30__)

in vec2   OUT_TexCoord;
in float  OUT_ClipPlane;
in vec4   OUT_ShadowParameters;

#if defined PP_PARALLAX_MAPPING

in vec3 v_positionWS;
in mat3 v_tangentMatrix;

#else

in vec3 v_eyeDirTS;
in vec3 v_lightDirTS;

#endif

#else

varying vec2   OUT_TexCoord;
varying float  OUT_ClipPlane;
varying vec4   OUT_ShadowParameters;

#if defined PP_PARALLAX_MAPPING

varying vec3 v_positionWS;
varying mat3 v_tangentMatrix;

#else

varying vec3 v_eyeDirTS;
varying vec3 v_lightDirTS;

#endif

#endif

uniform sampler2D SAMPLER_01;
uniform sampler2D SAMPLER_02;
uniform sampler2D SAMPLER_03;
uniform sampler2D SAMPLER_04;
uniform sampler2D SAMPLER_05;

#if defined PP_PARALLAX_MAPPING

uniform vec3 VECTOR_CameraPosition;
uniform vec3 VECTOR_GlobalLightPosition;

#endif

const vec2 vCameraRange = vec2(0.01, 1024.0);
const float k_fTexCoordScale = 8.0;

float getShadowMapPassDepth(in vec2 vTexCoord)
{
    float fNearZ = vCameraRange.x;
    float fFarZ = vCameraRange.y;
    float fDepth = texture2D(SAMPLER_05, vTexCoord).x;
    return (2.0 * fNearZ) / (fNearZ + fFarZ - fDepth * (fFarZ - fNearZ));
}

float getCurrentDepth(in  float fZ)
{
    float fDepth = fZ;
    float fNearZ = vCameraRange.x;
    float fFarZ = vCameraRange.y;
    fDepth = (2.0 * fNearZ) / (fNearZ + fFarZ - fDepth * (fFarZ - fNearZ));
    return fDepth;
}

void main(void)
{
    vec2 vTexCoord = OUT_ShadowParameters.st / OUT_ShadowParameters.w;
    float fZ = OUT_ShadowParameters.z / OUT_ShadowParameters.w;
    float fShadow = max(step(getCurrentDepth(fZ), getShadowMapPassDepth(vTexCoord)), 0.5);
    
    vec4 color = texture2D(SAMPLER_01, OUT_TexCoord);
    color.rgb *= fShadow;
    color.a = 1.0;
    gl_FragColor = color;
}