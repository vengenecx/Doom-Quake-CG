//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_NODE_H
#define DOOM_QUAKE_NODE_H

#include <iostream>
#include "Octree/BoundingBox.h"
#include "Octants.h"
#include "Model/BaseModel.h"

#define OCTREE_CHILDREN 8
class Node
{
    public:
        //Node* parent;

        Node(BoundingBox bb, int depth);

        // Octant children
        std::unique_ptr<Node> children[OCTREE_CHILDREN];
//        // Only leafs contain a model
//        BaseModel* model;

        std::vector<BaseModel*> models;

        unsigned char activeOctants;

        std::vector<Octants> matchChild(BoundingBox bb);
//        Node* getChild(Octants oc);

        BoundingBox boundingBox;

        bool hasChildren();

        bool depthEnd();

        int getDepth();

private:
    int depth;

    bool overlap(BoundingBox bb1, BoundingBox bb2);


};
#endif //DOOM_QUAKE_NODE_H
