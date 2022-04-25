//
// Created by Lennert Steyaert on 29/03/2022.
//

#ifndef DOOM_QUAKE_CUBEMODEL_H
#define DOOM_QUAKE_CUBEMODEL_H

#include "Map/VAO.h"
#include "Map/EBO.h"
#include "Shaders/Shader.h"
#include "Texture/Texture.h"

class CubeModel {
public:
    // mesh data

    CubeModel(Shader * shader);
    void draw(Shader * shader);

    void remove();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    std::unique_ptr<Texture> texture_1;
    std::unique_ptr<Texture> texture_2;

    std::vector<float>  vertices;
    std::vector<GLuint> indices;
};
#endif //DOOM_QUAKE_CUBEMODEL_H
