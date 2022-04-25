//
// Created by Lennert Steyaert on 25/04/2022.
//

#ifndef DOOM_QUAKE_SKYBOX_H
#define DOOM_QUAKE_SKYBOX_H

#include "Shaders/ShaderType.h"
#include "Shaders/Shader.h"
#include "Register/VAO.h"
#include "Texture/Texture.h"

class Skybox {
public:
    Skybox();
    void draw(Shader * shader);
    void remove();
    ~Skybox() {}

    ShaderType getShaderType();

private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;

    GLuint textureID;
    std::vector<float> vertices;

    unsigned int loadCubemap(std::vector<std::string> faces);
};

#endif //DOOM_QUAKE_SKYBOX_H
