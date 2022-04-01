//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_OCTREE_H
#define DOOM_QUAKE_OCTREE_H

#include "Node.h"
#include "Ray/Ray.h"

class Octree
{
public:
    Octree(std::unique_ptr<BoundingBox> boundingBox);

    void addModel(Model& model);


    bool query(Ray & ray);

    bool query(Ray & ray);

private:
    std::unique_ptr<Node> root;
};

#endif //DOOM_QUAKE_OCTREE_H
