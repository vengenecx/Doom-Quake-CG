#version 330 core
out vec4 FragColor;

in vec2 TexCoords;


struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

uniform Material material;

void main()
{
    FragColor = vec4(1.0,1.0,1.0,0.8);
}