//
// Created by Lennert Steyaert on 19/03/2022.
//

#ifndef DOOM_QUAKE_ESHADER_H
#define DOOM_QUAKE_ESHADER_H
static enum EShader {
    modelLoadingVertex = 0,
    modelLoadingFragment = 1,
    doubleTextureColorVertex = 2,
    doubleTextureColorFragment = 3,
    defaultVertex = 4,
    defaultFragment = 5,
    tesselationVertex = 6,
    tesselationFragment = 7,
    tesselationTCS  = 8,
    tesselationTES = 9,
    textVertex = 10,
    textFragment = 11,
    skyboxVertex = 12,
    skyboxFragment = 13
} eShader;
#endif //DOOM_QUAKE_ESHADER_H
