//
// Created by Lennert Steyaert on 25/04/2022.
//

#include "Model/BaseModel.h"

BaseModel::BaseModel(ShaderType type) : type(type) {}

ShaderType BaseModel::getShaderType(){
    return type;
}

void BaseModel::shoot() {}

void BaseModel::resetShoot() {}