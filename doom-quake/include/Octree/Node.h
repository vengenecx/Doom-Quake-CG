//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_NODE_H
#define DOOM_QUAKE_NODE_H

#include <iostream>
#include "Model.h"
#include "Octree/BoundingBox.h"

#define OCTREE_CHILDREN 8
class Node
{
    public:
        //Node* parent;

        Node(std::unique_ptr<BoundingBox> bb);

        // Octant children
        std::unique_ptr<Node> children[OCTREE_CHILDREN];
        // Only leafs contain a model
        std::unique_ptr<Model> model;
        // Bounding box of leafnodes present in model
        std::unique_ptr<BoundingBox> boundingBox;

        unsigned char activeOctants;
};
#endif //DOOM_QUAKE_NODE_H
