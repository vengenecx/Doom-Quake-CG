//
// Created by Lennert Steyaert on 02/05/2022.
//

#ifndef DOOM_QUAKE_TESTMODEL_H
#define DOOM_QUAKE_TESTMODEL_H

#include "Octree/Node.h"

class TestModel : public BaseModel
{
public:
    TestModel(ShaderType type, BoundingBox bx)  : BaseModel(type, bx){


    }

    void draw(Shader * shader){

    }
    void updatePosition(glm::vec3 pos){

    }
    void remove(){

    }
    ~TestModel() {}
};

#endif //DOOM_QUAKE_OCTREE_H