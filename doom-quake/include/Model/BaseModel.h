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
    BaseModel(ShaderType type, BoundingBox bb,std::vector<BaseModel*> &light);
    BaseModel(ShaderType type, std::vector<BaseModel*> &light);
    virtual void draw(Shader * shader) = 0;
    virtual void drawReflection(Shader * shader);


    virtual void updatePosition(glm::vec3 pos) = 0;
    virtual void remove() = 0;
    virtual ~BaseModel() {}

    virtual void shoot();
    virtual void resetShoot();

    virtual void resetDraw();

    virtual bool shown();

    virtual bool alreadyHit();

    ShaderType getShaderType();

    BoundingBox getBoundingBox();

    virtual void setupShader(Shader * shader,uint &pos);

protected:
    ShaderType type;
    BoundingBox bb;

    bool show = false;
    bool hit = false;

    //std::vector<BaseModel*> light;
    std::vector<BaseModel *> light;
};

#endif //DOOM_QUAKE_BASEMODEL_H