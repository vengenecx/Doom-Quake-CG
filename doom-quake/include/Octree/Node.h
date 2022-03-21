//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_NODE_H
#define DOOM_QUAKE_NODE_H

#include <iostream>
#include "Model.h"

#define OCTREE_CHILDREN 8
class Node
{
    public:
        Node* parent;
        std::unique_ptr<Node> children[OCTREE_CHILDREN];

        std::vector<Model> objects;
        unsigned char activeOctants;
};
#endif //DOOM_QUAKE_NODE_H
