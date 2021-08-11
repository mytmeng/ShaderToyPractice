
float CircleSDF(vec2 p, vec2 center, float radius) 
{
    return length(p-center)-radius;
}

float Scene(vec2 p)
{
    return CircleSDF(p, vec2(0.3f, 0.3f), 0.2f);
}
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;

    float d = Scene(uv);
    float smoot = smoothstep(-0.004f, 0.004f, d);
    vec4 color = vec4(1.0,1.0,1.0,1.0);
    color.xyz = color.xyz*(1.0-smoot);

    fragColor = color;
}
