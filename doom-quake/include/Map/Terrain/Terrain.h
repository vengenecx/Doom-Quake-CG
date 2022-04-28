//
// Created by Lennert Steyaert on 26/04/2022.
//

#ifndef DOOM_QUAKE_TERRAIN_H
#define DOOM_QUAKE_TERRAIN_H

#include <vector>
#include "Shaders/Shader.h"
#include "Texture/Texture.h"
#include "Register/VAO.h"

class Terrain {
public:
    Terrain(Texture * mapTexture);
    ~Terrain();


    void draw(Shader * shader);
    void remove();



private:
    std::vector<float> vertices;

    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;

    std::unique_ptr<Texture> heightTexture;

    Texture* mapTexture;

    int width, height;
//    unsigned int terrainVAO, terrainVBO;
    const unsigned int NUM_PATCH_PTS = 4;
    unsigned rez = 20;


    void setTextures(Shader* shader);
};

#endif //DOOM_QUAKE_TERRAIN_H
