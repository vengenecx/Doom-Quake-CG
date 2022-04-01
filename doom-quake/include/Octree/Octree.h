//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_OCTREE_H
#define DOOM_QUAKE_OCTREE_H

#include "Node.h"
#include "Ray/Ray.h"
#include "NodeCluster.h"

class Octree
{
public:
    Octree(std::unique_ptr<BoundingBox> boundingBox);

    void addModel(Model& model);


    bool query(Ray & ray);

    std::unique_ptr<NodeCluster> query(BoundingBox& b);


    void draw(BoundingBox& b);

private:
    std::unique_ptr<Node> root;
};

#endif //DOOM_QUAKE_OCTREE_H
