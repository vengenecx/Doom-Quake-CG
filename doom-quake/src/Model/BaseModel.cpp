//
// Created by Lennert Steyaert on 25/04/2022.
//

#include "Model/BaseModel.h"

BaseModel::BaseModel(ShaderType type) : type(type) {}

//BaseModel::BaseModel(ShaderType type, std::unique_ptr<BoundingBox> bb) : type(type),  bb(std::move(bb)) {}

BaseModel::BaseModel(ShaderType type, BoundingBox bb) : type(type),  bb(bb) {}


ShaderType BaseModel::getShaderType(){
    return type;
}

void BaseModel::shoot() {}

void BaseModel::resetShoot() {}

void BaseModel::resetDraw(){
    show = false;
}

bool BaseModel::shown(){
    return show;
}


//BoundingBox* BaseModel::getBoundingBox() {
//    return bb.get();
//}

BoundingBox BaseModel::getBoundingBox() {
    return bb;
}