//
// Created by Lennert Steyaert on 04/05/2022.
//

#ifndef DOOM_QUAKE_SCENE_H
#define DOOM_QUAKE_SCENE_H

#include <vector>
#include <memory>
#include "Shaders/Shader.h"
#include "Octree/Octree.h"

class Scene {
public:
    virtual void draw(std::vector<std::unique_ptr<Shader>> & shaders,std::vector<std::unique_ptr<Hit>>& hitPoints,Culling* culling, bool octreeVisible) = 0;
    virtual void remove() = 0;


    virtual void shoot(Ray* ray, std::vector<std::unique_ptr<Hit>> & hitPoints) = 0;
protected:
    std::unique_ptr<Octree> octree;
};

#endif //DOOM_QUAKE_SCENE_H
