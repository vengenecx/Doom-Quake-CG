//
// Created by Lennert Steyaert on 19/03/2022.
//

#ifndef DOOM_QUAKE_MESH_H
#define DOOM_QUAKE_MESH_H

#include <glm/vec3.hpp>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};
struct Texture {
    unsigned int id;
    string type;
};


#endif //DOOM_QUAKE_MESH_H
