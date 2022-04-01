//
// Created by Lennert Steyaert on 01/04/2022.
//

#include "Octree/Octree.h"

Octree::Octree(std::unique_ptr<BoundingBox> boundingBox) {
    //TODO
}

void Octree::addModel(Model &model) {
    //TODO
}

bool Octree::query(Ray &ray) {
    //TODO
    return false;// temporarly 
}

NodeCluster& Octree::query(BoundingBox& b){
    //TODO
    NodeCluster test; // temporarly 
    return test; // temporarly 
}

void Octree::draw(BoundingBox &b) {
    //TODO
}