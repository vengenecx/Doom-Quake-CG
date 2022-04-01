//
// Created by Lennert Steyaert on 01/04/2022.
//

#ifndef DOOM_QUAKE_NODECLUSTER_H
#define DOOM_QUAKE_NODECLUSTER_H

#include "Model.h"

class NodeCluster {
public:
    NodeCluster();

private:
    std::vector<Model*> models;
};


#endif //DOOM_QUAKE_NODECLUSTER_H
