//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_NODE_H
#define DOOM_QUAKE_NODE_H

#include <iostream>
#include "Model.h"
#include "Octree/BoundingBox.h"
#include "Octants.h"

#define OCTREE_CHILDREN 8
class Node
{
    public:
        //Node* parent;

        Node(BoundingBox& bb);

        // Octant children
        std::unique_ptr<Node> children[OCTREE_CHILDREN];
        // Only leafs contain a model
        std::unique_ptr<Model> model;
        // Bounding box of leafnodes present in model
        BoundingBox boundingBox;

        unsigned char activeOctants;

        Octants matchChild(BoundingBox*  bb);
        Node* getChild(Octants oc);
};
#endif //DOOM_QUAKE_NODE_H
