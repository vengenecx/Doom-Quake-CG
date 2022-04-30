#version 410 core

in float Height;
in vec2 TextCoordFrag;
out vec4 FragColor;

uniform sampler2D texture1;

void main()
{
    float h = (Height + 16)/64.0f;
//     FragColor = vec4(h, h, h, 1.0);
//     FragColor = texture(texture1, TextCoordFrag);

    if(h >  0.6){
        FragColor = vec4(0.8, 0.8, 0.8, 1.0);
    } else{
        FragColor = texture(texture1, TextCoordFrag);
    }
}