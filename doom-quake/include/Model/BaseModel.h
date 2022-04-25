//
// Created by Lennert Steyaert on 25/04/2022.
//

#ifndef DOOM_QUAKE_BASEMODEL_H
#define DOOM_QUAKE_BASEMODEL_H

#endif //DOOM_QUAKE_BASEMODEL_H

#include "Register/VAO.h"
#include "Register/EBO.h"
#include "Shaders/Shader.h"
#include "Texture/Texture.h"


class BaseModel {
public:
    virtual void draw(Shader * shader) = 0;
    virtual void remove() = 0;
};