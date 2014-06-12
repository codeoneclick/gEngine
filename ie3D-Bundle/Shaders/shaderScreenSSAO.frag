varying highp vec2 OUT_TexCoord;

uniform sampler2D  SAMPLER_01;
uniform sampler2D  SAMPLER_02;

uniform highp vec3 rndTable[8];

void main()
{
	const highp float zFar = 1024.0;
    const highp float zNear = 0.01;
    const highp float radius = 0.2;
    const highp float attBias = 0.3;
    const highp float attScale = 1.0;
    
    lowp float   zb    = pow(texture2D ( SAMPLER_01, OUT_TexCoord).x, 512.0);
    highp float   z     = zFar*zNear/(zb * (zFar - zNear) - zFar);
    highp float   att   = 0.0;
    highp vec3    plane = 2.0 * texture2D (SAMPLER_02, OUT_TexCoord * 512.0 / 4.0).xyz - vec3 ( 1.0 );
    
    for ( int i = 0; i < 8; i++ )
    {
        highp vec3    sample  = reflect   ( rndTable[i], plane );
        highp float   zSample = texture2D ( SAMPLER_01, OUT_TexCoord + radius*sample.xy / z ).x;
        
        zSample = zFar * zNear / (zSample * (zFar - zNear) - zFar );
        
        if ( zSample - z > 0.1 )
            continue;
        
        highp float   dz = max ( zSample - z, 0.0 ) * 30.0;
        
        att += 1.0 / ( 1.0 + dz*dz );
    }
    
    att = clamp ( (att / 8.0 + attBias) * attScale, 0.0, 1.0 );
    
    gl_FragColor = vec4 ( abs(rndTable[7].x), abs(rndTable[7].x), abs(rndTable[7].x), 1.0 );
}

