//
// Created by Lennert Steyaert on 01/04/2022.
//

#include "Octree/Octree.h"

Octree::Octree(BoundingBox& boundingBox) {
    //TODO
    this->root = std::make_unique<Node>(boundingBox);
}

void Octree::addModel(Model * model) {
    //TODO
    Node * node = this->root.get();

    while(node){
        if(!node->children){ // Node has no children

            if(node->model){ // Node contains a model

                // Check if current shape fits into smaller boundaries

                // Create children
                generateChildren(node);
                // Push current


                // Search child current boundingbox
                Octants o = node->matchChild(model->getBoundingbox());


                // Replace child
                node = node->getChild(o);
                //containsBoundaries(node, model->getBoundingbox());
            } else{

            }

        } else{ // Node has children



        }
    }
}

void Octree::generateChildren(Node *node) {
    // TODO

}


bool Octree::query(Ray &ray) {
    //TODO


    return false;
}


bool Octree::containsBoundaries(Node * node, BoundingBox* boundingBox){
    return true;
}


std::unique_ptr<NodeCluster> Octree::query(BoundingBox& b){
    //TODO
    std::unique_ptr<NodeCluster> n = std::make_unique<NodeCluster>();
    return move(n);
}

void Octree::draw(BoundingBox &b) {
    //TODO
}