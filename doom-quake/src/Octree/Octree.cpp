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

//void Octree::addModelRecursive(Node* node, BaseModel * model){
//    if(node->depthEnd()){
//        node->models.push_back(model); // Add model
//    } else{
//
//        if(!node->models.empty()) {
//
//            if (!node->hasChildren()) {
//                generateChildren(node); // generate children
//
//                std::vector<BaseModel *> remainingModels = std::vector<BaseModel*>();
//
//                for (auto m: node->models) {
//                    std::vector<Octants> octants = node->matchChild(m->getBoundingBox());
//
////                    for (Octants &oc: octants) {
////                        node->children[static_cast<int>(oc)]->models.push_back(m);
////                    }
//
//                    if (octants.size() < 8) {
//                        for (Octants &oc: octants) {
//                            node->children[static_cast<int>(oc)]->models.push_back(m);
//                        }
//                    } else {
//                        remainingModels.push_back(m);
//                    }
//                }
//                node->models = remainingModels;
//            }
//
//            std::vector<Octants> overlap = node->matchChild(model->getBoundingBox());
//
//            if (overlap.size() != 8) { // No full overlap new model
//
//                for (Octants &oc: overlap) {
//                    addModelRecursive(node->children[static_cast<int>(oc)].get(), model);
//                }
//
//            } else { // Full overlap
//                node->models.push_back(model);
////                for (Octants &oc: overlap) {
////                    addModelRecursive(node->children[static_cast<int>(oc)].get(), model);
////                }
//            }
//        } else{
////            if (node->hasChildren()) {
////                std::vector<Octants> overlap = node->matchChild(model->getBoundingBox());
////
////                for (Octants &oc: overlap) {
////                    addModelRecursive(node->children[static_cast<int>(oc)].get(), model);
////                }
////
////            } else{
////                node->models.push_back(model);
////            }
//           node->models.push_back(model);
//        }
//    }
//}

//void Octree::addModelRecursive(Node* node, BaseModel * model){
//    if(node->depthEnd()){
//        std::cout<< "end" << std::endl;
//        node->models.push_back(model); // Add model
//    } else{
//
//        if(!node->models.empty()) {
//            if (!node->hasChildren()) {
//                generateChildren(node); // generate children
//            }
//
//            // Copy models down
//            for(auto m : node->models){
//                std::vector<Octants> octants = node->matchChild(m->getBoundingBox());
//                for (Octants &oc: octants) {
//                    addModelRecursive(node->children[static_cast<int>(oc)].get(), m);
//                }
//            }
//            node->models.clear();
//
//
//            //  Add new model
//
//            std::vector<Octants> octants = node->matchChild(model->getBoundingBox());
//            for (Octants &oc: octants) {
//                addModelRecursive(node->children[static_cast<int>(oc)].get(), model);
//            }
//
//        } else{
//            node->models.push_back(model);
//        }
//    }
//}

void Octree::addModelRecursive(Node* node, BaseModel * model){
    if(node->depthEnd()){
        std::cout<< "end" << std::endl;
        node->models.push_back(model); // Add model
    } else{

        if(!node->models.empty()) {
            if (!node->hasChildren()) {
                generateChildren(node); // generate children
            }

            // Copy models down
            for(auto m : node->models){
                std::vector<Octants> octants = node->matchChild(m->getBoundingBox());
                for (Octants &oc: octants) {
                    addModelRecursive(node->children[static_cast<int>(oc)].get(), m);
                }
            }
            node->models.clear();


            //  Add new model

            std::vector<Octants> octants = node->matchChild(model->getBoundingBox());
            for (Octants &oc: octants) {
                addModelRecursive(node->children[static_cast<int>(oc)].get(), model);
            }

        } else{
            if(!node->hasChildren()){
                node->models.push_back(model);
            } else{
                std::vector<Octants> octants = node->matchChild(model->getBoundingBox());
                for (Octants &oc: octants) {
                    addModelRecursive(node->children[static_cast<int>(oc)].get(), model);
                }
            }
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

    node->children[static_cast<int>(Octants::FRONTUPLEFT)] = std::make_unique<Node>(frontUpperLeft,depth-1);

    BoundingBox frontUpperRight = BoundingBox();
    frontUpperRight.centre = glm::vec3(node->boundingBox.centre.x+xDimensionHalve,
                                      node->boundingBox.centre.y+yDimensionHalve,
                                      node->boundingBox.centre.z-zDimensionHalve);
    frontUpperRight.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::FRONTUPRIGHT)] = std::make_unique<Node>(frontUpperRight,depth-1);

    BoundingBox frontBottomRight = BoundingBox();
    frontBottomRight.centre = glm::vec3(node->boundingBox.centre.x+xDimensionHalve,
                                       node->boundingBox.centre.y-yDimensionHalve,
                                       node->boundingBox.centre.z-zDimensionHalve);
    frontBottomRight.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::FRONTBOTTOMRIGHT)] = std::make_unique<Node>(frontBottomRight,depth-1);

    BoundingBox frontBottomLeft = BoundingBox();
    frontBottomLeft.centre = glm::vec3(node->boundingBox.centre.x-xDimensionHalve,
                                        node->boundingBox.centre.y-yDimensionHalve,
                                        node->boundingBox.centre.z-zDimensionHalve);
    frontBottomLeft.dimensions = glm::vec3(xDimension,yDimension,zDimension);

    node->children[static_cast<int>(Octants::FRONTBOTTOMLEFT)] = std::make_unique<Node>(frontBottomLeft,depth-1);


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

Node* Octree::shoot(Ray& ray){

    Node * node = root.get();

//    while(node->hasChildren()){
//        bool found = false;
//        uint index = 0;
//
//        while(index < 8 && intersect( node->children[index]->boundingBox,ray) == false){
//            index++;
//        }
//        if(index >= 8)
//            std::cout << "ERROR CALC" << std::endl;
//        else
//            node = node->children[index].get();
//    }
//    return node;
    bool res = searchRecursive(node,ray);
    return nullptr;
}

bool Octree::searchRecursive(Node* node, Ray& ray){
    if(node->hasChildren()){

        bool res = false;

        for(int i=0 ; i<8;i++){
            if(intersect(node->children[i]->boundingBox, ray)) {
                res = searchRecursive(node->children[i].get(), ray);
            }
        }
        return res;
    }
    if(!node->models.empty()){
        std::cout << "NOT EMPTY" << std::endl;
        for(auto m :node->models){
            BoundingBox bx = m->getBoundingBox();
            bool hit = intersect(bx,ray);
            if(hit)
                std::cout << "HIT" << std::endl;
            else
                std::cout << "MISSED" << std::endl;
        }
    }
    return !node->models.empty();
}



// https://github.com/BSVino/MathForGameDevelopers/blob/line-box-intersection/math/collision.cpp

bool Octree::intersect(BoundingBox& bb1, Ray& ray){
    float f_low = 0;
    float f_high = 1;

    glm::vec3 v0 = ray.getOrigin();
    glm::vec3 direction = ray.getDirection();

    glm::vec3 v1= glm::vec3(v0.x + 200*direction.x,v0.y + 200*direction.y,v0.z + 200*direction.z);

    if (!clipLine(0, bb1, v0, v1, f_low, f_high))
        return false;

    if (!clipLine(1, bb1, v0, v1, f_low, f_high))
        return false;

    if (!clipLine(2, bb1, v0, v1, f_low, f_high))
        return false;

//    // The formula for I: http://youtu.be/USjbg5QXk3g?t=6m24s
//    Vector b = v1 - v0;
//    vecIntersection = v0 + b * f_low;
//
//    flFraction = f_low;

    return true;

}


bool Octree::clipLine(int d, BoundingBox& bb,const glm::vec3& v0, const glm::vec3& v1, float& f_low, float& f_high){
    // f_low and f_high are the results from all clipping so far. We'll write our results back out to those parameters.

    // f_dim_low and f_dim_high are the results we're calculating for this current dimension.
    float f_dim_low, f_dim_high;

    // Find the point of intersection in this dimension only as a fraction of the total vector http://youtu.be/USjbg5QXk3g?t=3m12s
//    f_dim_low = (aabbBox.vecMin.v[d] - v0.v[d])/(v1.v[d] - v0.v[d]);
//    f_dim_high = (aabbBox.vecMax.v[d] - v0.v[d])/(v1.v[d] - v0.v[d]);

      f_dim_low = ((bb.centre[d]-bb.dimensions[d]/2) - v0[d]) / (v1[d] - v0[d]);
      f_dim_high = ((bb.centre[d]+bb.dimensions[d]/2) - v0[d]) / (v1[d] - v0[d]);

//    f_dim_low = (bb.vecMin.v[d] - v0.v[d])/(v1.v[d] - v0.v[d]);
//    f_dim_high = (aabbBox.vecMax.v[d] - v0.v[d])/(v1.v[d] - v0.v[d]);

    // Make sure low is less than high
    if (f_dim_high < f_dim_low)
        std::swap(f_dim_high, f_dim_low);

    // If this dimension's high is less than the low we got then we definitely missed. http://youtu.be/USjbg5QXk3g?t=7m16s
    if (f_dim_high < f_low)
        return false;

    // Likewise if the low is less than the high.
    if (f_dim_low > f_high)
        return false;

    // Add the clip from this dimension to the previous results http://youtu.be/USjbg5QXk3g?t=5m32s
    f_low = std::max(f_dim_low, f_low);
    f_high = std::min(f_dim_high, f_high);

    if (f_low > f_high)
        return false;

    return true;
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