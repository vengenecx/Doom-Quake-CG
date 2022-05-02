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
    Octree(BoundingBox& boundingBox, int depth);

    void addModel(BaseModel* model);


    bool query(Ray & ray);

    std::unique_ptr<NodeCluster> query(BoundingBox& b);

    Node* shoot(Ray& ray);


    void draw(BoundingBox& b);



private:
    std::unique_ptr<Node> root;

    bool containsBoundaries(Node * node, BoundingBox* boundingBox);
    void generateChildren(Node* node);
    void assignCurrentModelToChildren(Node* node);


    void addModelRecursive(Node* node, BaseModel * model);
};

#endif //DOOM_QUAKE_OCTREE_H
