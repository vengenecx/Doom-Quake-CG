//
// Created by Lennert Steyaert on 01/04/2022.
//

#include "Octree/Octree.h"

Octree::Octree(BoundingBox& boundingBox, int depth) {
    this->root = std::make_unique<Node>(boundingBox,depth);
}

void Octree::addModel(BaseModel * model) {
    //TODO
//    Node * node = this->root.get();
//    int child= 0;
//
//    while(node){
//        if(!node->isLeaf()){ // Node has no children
//            if(!node->models.empty()){ // Node contains models
//
//                // Create children
//                generateChildren(node);
//
//                // Push current models to node
//                assignModelsToChildren(node,node->models);
//                node->models.clear();  // Clear models
//
//                // Push new model to all children
//                assignModelToChildren(node, model);
//
//                child = 0;
//
//            } else{
//                node->model = model;
//            }
//
//        } else{ // Node has children
//
//
//
//        }
//    }
    Node * node = this->root.get();
    this->addModelRecursive(node,model);
}

void Octree::addModelRecursive(Node* node, BaseModel * model){
    if(node->depthEnd()){
        node->models.push_back(model); // Add model
    } else{

        if(!node->models.empty()) {

            if (!node->hasChildren()) {
                generateChildren(node); // generate children

                std::vector<BaseModel *> remainingModels = std::vector<BaseModel*>();

                for (auto m: node->models) {
                    std::vector<Octants> octants = node->matchChild(m->getBoundingBox());

                    if (octants.size() < 8) {
                        for (Octants &oc: octants) {
                            node->children[static_cast<int>(oc)]->models.push_back(m);
                        }
                    } else {
                        remainingModels.push_back(m);
                    }
                }
                node->models = remainingModels;
            }

            std::vector<Octants> overlap = node->matchChild(model->getBoundingBox());

            if (overlap.size() != 8) { // No full overlap new model

                for (Octants &oc: overlap) {
                    addModelRecursive(node->children[static_cast<int>(oc)].get(), model);
                }

            } else { // Full overlap
                node->models.push_back(model);
            }
        } else{
            node->models.push_back(model);
        }
    }
}

void Octree::generateChildren(Node *node) {
    // TODO
    int depth = node->getDepth();

    float xDimension = node->boundingBox.dimensions.x/2;
    float yDimension = node->boundingBox.dimensions.y/2;
    float zDimension = node->boundingBox.dimensions.z/2;

    float xDimensionHalve = node->boundingBox.dimensions.x/4;
    float yDimensionHalve = node->boundingBox.dimensions.y/4;
    float zDimensionHalve = node->boundingBox.dimensions.z/4;


    // FRONT

    BoundingBox frontUpperLeft = BoundingBox();
    frontUpperLeft.centre = glm::vec3(node->boundingBox.centre.x-xDimensionHalve,
                                      node->boundingBox.centre.y+yDimensionHalve,
                                      node->boundingBox.centre.z-zDimensionHalve);
    frontUpperLeft.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::FRONTUPLEFT)] = std::make_unique<Node>(frontUpperLeft,depth);

    BoundingBox frontUpperRight = BoundingBox();
    frontUpperRight.centre = glm::vec3(node->boundingBox.centre.x+xDimensionHalve,
                                      node->boundingBox.centre.y+yDimensionHalve,
                                      node->boundingBox.centre.z-zDimensionHalve);
    frontUpperRight.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::FRONTUPRIGHT)] = std::make_unique<Node>(frontUpperRight,depth);

    BoundingBox frontBottomRight = BoundingBox();
    frontBottomRight.centre = glm::vec3(node->boundingBox.centre.x+xDimensionHalve,
                                       node->boundingBox.centre.y-yDimensionHalve,
                                       node->boundingBox.centre.z-zDimensionHalve);
    frontBottomRight.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::FRONTBOTTOMRIGHT)] = std::make_unique<Node>(frontBottomRight,depth);

    BoundingBox frontBottomLeft = BoundingBox();
    frontBottomLeft.centre = glm::vec3(node->boundingBox.centre.x-xDimensionHalve,
                                        node->boundingBox.centre.y-yDimensionHalve,
                                        node->boundingBox.centre.z-zDimensionHalve);
    frontBottomLeft.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::FRONTBOTTOMLEFT)] = std::make_unique<Node>(frontBottomLeft,depth);



    // BACK


    BoundingBox backUpperLeft = BoundingBox();
    backUpperLeft.centre = glm::vec3(node->boundingBox.centre.x-xDimensionHalve,
                                      node->boundingBox.centre.y+yDimensionHalve,
                                      node->boundingBox.centre.z+zDimensionHalve);
    backUpperLeft.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::BACKUPLEFT)] = std::make_unique<Node>(backUpperLeft,depth);

    BoundingBox backUpperRight = BoundingBox();
    backUpperRight.centre = glm::vec3(node->boundingBox.centre.x+xDimensionHalve,
                                       node->boundingBox.centre.y+yDimensionHalve,
                                       node->boundingBox.centre.z+zDimensionHalve);
    backUpperRight.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::BACKUPRIGHT)] = std::make_unique<Node>(backUpperRight,depth);

    BoundingBox backBottomRight = BoundingBox();
    backBottomRight.centre = glm::vec3(node->boundingBox.centre.x+xDimensionHalve,
                                        node->boundingBox.centre.y-yDimensionHalve,
                                        node->boundingBox.centre.z+zDimensionHalve);
    backBottomRight.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::BACKBOTTOMRIGHT)] = std::make_unique<Node>(backBottomRight,depth);

    BoundingBox backBottomLeft = BoundingBox();
    backBottomLeft.centre = glm::vec3(node->boundingBox.centre.x-xDimensionHalve,
                                       node->boundingBox.centre.y-yDimensionHalve,
                                       node->boundingBox.centre.z+zDimensionHalve);
    backBottomLeft.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::BACKBOTTOMLEFT)] = std::make_unique<Node>(backBottomLeft,depth);
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

void Octree::draw(Shader* shader) {
    //TODO
    root->draw(shader);
}