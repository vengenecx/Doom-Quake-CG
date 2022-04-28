#version 410 core

in float Height;
in vec2 TextCoordFrag;
out vec4 FragColor;

uniform sampler2D texture1;

void main()
{
    float h = (Height + 16)/64.0f;
//     FragColor = vec4(h, h, h, 1.0);
    FragColor = texture(texture1, TextCoordFrag);
}