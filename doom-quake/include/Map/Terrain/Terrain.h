//
// Created by Lennert Steyaert on 26/04/2022.
//

#ifndef DOOM_QUAKE_TERRAIN_H
#define DOOM_QUAKE_TERRAIN_H

#include <vector>
#include "Shaders/Shader.h"

class Terrain {
public:
    Terrain(Shader* shader);
    void draw(Shader * shader);
    void updatePosition(glm::vec3 pos);
    void remove();


    void loadTexture(Shader* shader);

    ~Terrain() {}

private:
    std::vector<float> vertices;
    unsigned int texture;
    int width, height, nrChannels;
    unsigned int terrainVAO, terrainVBO;
    const unsigned int NUM_PATCH_PTS = 4;
    unsigned rez = 20;
};

#endif //DOOM_QUAKE_TERRAIN_H
