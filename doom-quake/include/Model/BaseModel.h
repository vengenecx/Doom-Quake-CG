//
// Created by Lennert Steyaert on 25/04/2022.
//

#ifndef DOOM_QUAKE_BASEMODEL_H
#define DOOM_QUAKE_BASEMODEL_H



#include "Register/VAO.h"
#include "Register/EBO.h"
#include "Shaders/Shader.h"
#include "Texture/Texture.h"
#include "Shaders/ShaderType.h"
#include "Octree/BoundingBox.h"


class BaseModel {
public:
    BaseModel(ShaderType type);
//    BaseModel(ShaderType type, std::unique_ptr<BoundingBox> bb);
    BaseModel(ShaderType type, BoundingBox bb);
    virtual void draw(Shader * shader) = 0;
    virtual void updatePosition(glm::vec3 pos) = 0;
    virtual void remove() = 0;
    virtual ~BaseModel() {}


    virtual void shoot();
    virtual void resetShoot();

    ShaderType getShaderType();
//    BoundingBox* getBoundingBox();

    BoundingBox getBoundingBox();

protected:
    ShaderType type;
//    std::unique_ptr<BoundingBox> bb;
    BoundingBox bb;
};

#endif //DOOM_QUAKE_BASEMODEL_H