//
// Created by Lennert Steyaert on 04/05/2022.
//

#ifndef DOOM_QUAKE_SCENE_H
#define DOOM_QUAKE_SCENE_H

#include <vector>
#include <memory>
#include "Shaders/Shader.h"

class Scene {
public:
    virtual void draw(std::vector <std::unique_ptr<Shader>> &shaders) = 0;
    virtual void remove() = 0;
};

#endif //DOOM_QUAKE_SCENE_H
