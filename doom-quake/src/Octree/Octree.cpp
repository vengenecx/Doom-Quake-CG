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
    return false;
}

std::unique_ptr<NodeCluster> Octree::query(BoundingBox& b){
    //TODO
    std::unique_ptr<NodeCluster> n = std::make_unique<NodeCluster>();
    return move(n);
}

void Octree::draw(BoundingBox &b) {
    //TODO
}