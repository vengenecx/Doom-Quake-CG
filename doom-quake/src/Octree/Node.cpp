//
// Created by Lennert Steyaert on 01/04/2022.
//

#include "Octree/Node.h"

Node::Node(BoundingBox bb, int depth) : depth(depth), boundingBox(bb){
    //TODO
    for(int i=0; i<8;i++){
        children[i] = NULL;
    }
}


std::vector<Octants> Node::matchChild(BoundingBox bb)  {
    // TODO
    std::vector<Octants> result = std::vector<Octants>();

    if(overlap(this->children[static_cast<int>(Octants::FRONTUPLEFT)]->boundingBox,bb))
        result.push_back(Octants::FRONTUPLEFT);

    if(overlap(this->children[static_cast<int>(Octants::FRONTUPRIGHT)]->boundingBox,bb))
        result.push_back(Octants::FRONTUPRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::FRONTBOTTOMRIGHT)]->boundingBox,bb))
        result.push_back(Octants::FRONTBOTTOMRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::FRONTBOTTOMLEFT)]->boundingBox,bb))
        result.push_back(Octants::FRONTBOTTOMLEFT);

    if(overlap(this->children[static_cast<int>(Octants::BACKUPLEFT)]->boundingBox,bb))
        result.push_back(Octants::BACKUPLEFT);

    if(overlap(this->children[static_cast<int>(Octants::BACKUPRIGHT)]->boundingBox,bb))
        result.push_back(Octants::BACKUPRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::BACKBOTTOMRIGHT)]->boundingBox,bb))
        result.push_back(Octants::BACKBOTTOMRIGHT);

    if(overlap(this->children[static_cast<int>(Octants::BACKBOTTOMLEFT)]->boundingBox,bb))
        result.push_back(Octants::BACKBOTTOMLEFT);

    return result;
}

bool Node::overlap(BoundingBox bb1, BoundingBox bb2) {
    float min_x = bb1.centre.x - bb1.dimensions.x/2.0;
    float max_x = bb1.centre.x + bb1.dimensions.x/2.0;

    float min_y = bb1.centre.y - bb1.dimensions.y/2.0;
    float max_y = bb1.centre.y + bb1.dimensions.y/2.0;

    float min_z = bb1.centre.z - bb1.dimensions.z/2.0;
    float max_z = bb1.centre.z + bb1.dimensions.z/2.0;

    float min_x_bb2 = bb2.centre.x - bb2.dimensions.x/2.0;
    float max_x_bb2 = bb2.centre.x + bb2.dimensions.x/2.0;

    float min_y_bb2 = bb2.centre.y - bb2.dimensions.y/2.0;
    float max_y_bb2 = bb2.centre.y + bb2.dimensions.y/2.0;

    float min_z_bb2 = bb2.centre.z - bb2.dimensions.z/2.0;
    float max_z_bb2 = bb2.centre.z + bb2.dimensions.z/2.0;


    if(!(min_x_bb2 >= min_x && max_x > min_x_bb2 || min_x_bb2 <= min_x && max_x_bb2 > min_x))
        return false;
    if(!(min_y_bb2 >= min_y && max_y > min_y_bb2 || min_y_bb2 <= min_y && max_y_bb2 > min_y))
        return false;
    if(!(min_z_bb2 >= min_z && max_z > min_z_bb2 || min_z_bb2 <= min_z && max_z_bb2 > min_z))
        return false;

    return true;
}

bool Node::hasChildren() {
    return  children[0] != NULL ||
            children[1] != NULL ||
            children[2] != NULL ||
            children[3] != NULL ||
            children[4] != NULL ||
            children[5] != NULL ||
            children[6] != NULL ||
            children[7] != NULL;
}

bool Node::depthEnd() {
    return depth == 0;
}

int Node::getDepth() {
    return depth;
}


//Node* Node::getChild(Octants oc){
//    // TODO
//    return nullptr;
//}

