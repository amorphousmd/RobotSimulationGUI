#version 120

// Light information
uniform highp vec4 lightPosition;
uniform highp vec3 lightIntensity;

// Material information
uniform lowp vec3 Ka;
uniform lowp vec3 Kd;
uniform lowp vec3 Ks;
uniform lowp float shininess;

varying highp vec3 normal;
varying highp vec3 position;

highp vec3 adsModel(vec3 norm)
{
    // Calculate light direction
    highp vec3 s = normalize( lightPosition.xyz - position);

    // Calculate the vector from the fragment to eye position
    highp vec3 v = normalize( -position.xyz );

    // Reflect the light using the normal
    highp vec3 r = reflect( -s, norm);

    // Calculate the diffuse contribution
    highp vec3 diffuseIntensity = vec3( max( dot( s, norm), 0.0) );

    // Calculate specular contribution
    highp vec3 specularIntensity = vec3(0.0);
    if( dot( s, norm) > 0.0 )
        specularIntensity = highp vec3( pow( max( dot(r, v), 0.0), shininess));

    // Calculate final color
    return lightIntensity * (Ka +
                                           Kd * diffuseIntensity +
                                           Ks * specularIntensity);
}

void main(void)
{
    gl_FragColor = highp vec4(adsModel(normalize(normal)), 1.0);
}
