#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct DirLight {
    //vec3 direction;

    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
//     vec3 position;
//     vec3 direction;
    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

#define NR_POINT_LIGHTS 4


in vec3 FragPos;
in vec2 TexCoords;
in mat3 TBN;
in vec3 N;

uniform vec3 viewPos;
uniform vec3 direction;

uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLight;
uniform Material material;

uniform bool directionLightState;
uniform bool pointLightState;
uniform bool spotLightState;

uniform int numberOfPointLights;

// function prototypes
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir,vec3 tangentFragPos);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir,vec3 tangentFragPos);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewDir,vec3 tangentFragPos, vec3 viewPos, vec3 direction, vec3 FragPos);

void main()
{

   // vec3 TangentLightPos = TBN * pointLights[0].position;
    vec3 tangentViewPos  = TBN * viewPos;
    vec3 tangentFragPos  = TBN * FragPos;
    vec3 viewDir = normalize(tangentViewPos - tangentFragPos);

    // properties
    //vec3 norm = normalize(Normal);
         // obtain normal from normal map in range [0,1]
    vec3 normal = texture(material.specular, TexCoords).rgb;
    // transform normal vector to range [-1,1]
    normal = normalize(normal * 2.0 - 1.0);  // this normal is in tangent space



    //vec3 viewDir = normalize(viewPos - FragPos);

    // == =====================================================
    // Our lighting is set up in 3 phases: directional, point lights and an optional flashlight
    // For each phase, a calculate function is defined that calculates the corresponding color
    // per lamp. In the main() function we take all the calculated colors and sum them up for
    // this fragment's final color.
    // == =====================================================
    // phase 1: directional lighting
    //vec3 result = CalcPointLight(pointLights[0], norm, FragPos, viewDir);
    // phase 2: point lights
//     for(int i = 1; i < NR_POINT_LIGHTS; i++)
//         result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);
    // phase 3: spot light
//     result += CalcSpotLight(spotLight, norm, FragPos, viewDir);

    //FragColor = vec4(result, 1.0);
//     FragColor = texture(material.diffuse, TexCoords);



    // // get diffuse color
    // vec3 color = texture(material.diffuse, TexCoords).rgb;
    // // ambient
    // vec3 ambient = 0.1 * color;
    // // diffuse
    // vec3 lightDir = normalize(TangentLightPos - TangentFragPos);
    // float diff = max(dot(lightDir, normal), 0.0);
    // vec3 diffuse = diff * color;
    // // specular
    // vec3 viewDir = normalize(TangentViewPos - TangentFragPos);
    // vec3 reflectDir = reflect(-lightDir, normal);
    // vec3 halfwayDir = normalize(lightDir + viewDir);
    // float spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);

    // vec3 specular = vec3(0.2) * spec;
    // FragColor = vec4(ambient + diffuse + specular, 1.0);
    vec3 result  = vec3(0.0);

    if(directionLightState){
        result = CalcDirLight(dirLight, normal, viewDir, tangentFragPos);
    }

    if(pointLightState && numberOfPointLights<=NR_POINT_LIGHTS){
      for(int i = 0; i < numberOfPointLights; i++){
        result += CalcPointLight(pointLights[i], normal, viewDir, tangentFragPos);
        //result = direction;
      }
    }

    if(spotLightState){
        //result  = vec3(1.0);
        //result = direction;
        result += CalcSpotLight(spotLight, N, viewDir, tangentFragPos, viewPos, direction,FragPos);
    }

    FragColor = vec4(result, 1.0);
}

// calculates the color when using a directional light.
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir,vec3 tangentFragPos)
{
    vec3 tangentLightPos = TBN * light.position;

    vec3 color = texture(material.diffuse, TexCoords).rgb;
    // ambient
    vec3 ambient = light.ambient * color;
    
    // diffuse
    vec3 lightDir = normalize(tangentLightPos - tangentFragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = light.diffuse * diff * color;
    
    // specular
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec;

    return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir,vec3 tangentFragPos)
{
        vec3 tangentLightPos = TBN * light.position;

        vec3 color = texture(material.diffuse, TexCoords).rgb;
        // ambient
        vec3 ambient = light.ambient * color;

        // diffuse
        vec3 lightDir = normalize(tangentLightPos - tangentFragPos);
        float diff = max(dot(lightDir, normal), 0.0);
        vec3 diffuse = light.diffuse * diff * color;

        // specular
        vec3 reflectDir = reflect(-lightDir, normal);
        vec3 halfwayDir = normalize(lightDir + viewDir);
        float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
        vec3 specular = light.specular * spec;

        // attenuation
        float distance = length(tangentLightPos - tangentFragPos);
        float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

        ambient *= attenuation;
        diffuse *= attenuation;
        specular *= attenuation;

        return (ambient + diffuse + specular);
}

// calculates the color when using a spot light.
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewDir,vec3 tangentFragPos,vec3 viewPos, vec3 direction, vec3 FragPos)
{
//     vec3 lightDir = normalize(light.position - fragPos);
//     // diffuse shading
//     float diff = max(dot(normal, lightDir), 0.0);
//     // specular shading
//     vec3 reflectDir = reflect(-lightDir, normal);
//     float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//     // attenuation
//     float distance = length(light.position - fragPos);
//     float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
//     // spotlight intensity
//     float theta = dot(lightDir, normalize(-light.direction));
//     float epsilon = light.cutOff - light.outerCutOff;
//     float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
//     // combine results
//     vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
//     vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
//     vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
//     ambient *= attenuation * intensity;
//     diffuse *= attenuation * intensity;
//     specular *= attenuation * intensity;
//     return (ambient + diffuse + specular);

        //vec3 tangentLightPos = TBN * viewPos;

        vec3 color = texture(material.diffuse, TexCoords).rgb;
        // ambient
        vec3 ambient = light.ambient * color;

        vec3 norm = normalize(normal);

        // diffuse
        vec3 lightDir = normalize(viewPos - FragPos);
        float diff = max(dot(lightDir, norm), 0.0);
        vec3 diffuse = light.diffuse * diff * color;

        vec3 viewDirA = normalize(viewPos - FragPos);

        // specular
        vec3 reflectDir = reflect(-lightDir, norm);
        //vec3 halfwayDir = normalize(lightDir + viewDir);
        //float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);

        float spec = pow(max(dot(viewDirA, reflectDir), 0.0), material.shininess);
        vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;;

        // attenuation
        float distance = length(viewPos - FragPos);
        float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

        // spotlight intensity
        float theta = dot(lightDir, normalize(-direction));
        float epsilon = light.cutOff - light.outerCutOff;
        float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);


        ambient *= attenuation * intensity;
        diffuse *= attenuation * intensity;
        specular *= attenuation * intensity;

        return (ambient + diffuse + specular);


}