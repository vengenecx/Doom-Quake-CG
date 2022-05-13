#version 330 core
//layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 acolor;
//layout (location = 2) in vec3 aNormal;
//layout (location = 3) in vec2 aTexCoords;
//layout (location = 1) in vec3 aNormal;
//layout (location = 2) in vec2 aTexCoords;


layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

//out vec3 FragPos;
//out vec3 Normal;
//out vec2 TexCoords;


out vec3 FragPos;
out vec2 TexCoords;
//out vec3 TangentLightPos;
//out vec3 TangentViewPos;
//out vec3 TangentFragPos;
out mat3 TBN;

out vec3 N;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;



void main()
{
    //FragPos = vec3(model * vec4(aPos, 1.0));
    //Normal = mat3(transpose(inverse(model))) * aNormal;
    //TexCoords = aTexCoords;

    //gl_Position = projection * view * vec4(FragPos, 1.0);

    FragPos = vec3(model * vec4(aPos, 1.0));
    TexCoords = aTexCoords;

    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 T = normalize(normalMatrix * aTangent);
    N = normalize(normalMatrix * aNormal);
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);

    TBN = transpose(mat3(T, B, N));
    //vs_out.TangentLightPos = TBN * lightPos;
    //vs_out.TangentViewPos  = TBN * viewPos;
    //vs_out.TangentFragPos  = TBN * vs_out.FragPos;

    gl_Position = projection * view * model * vec4(aPos, 1.0);
}