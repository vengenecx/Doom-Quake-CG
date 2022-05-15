//
// Created by Lennert Steyaert on 01/04/2022.
//

#ifndef DOOM_QUAKE_BOUNDINGBOX_H
#define DOOM_QUAKE_BOUNDINGBOX_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct BoundingBox {
    glm::vec3 centre;
    glm::vec3 dimensions;
};


#endif //DOOM_QUAKE_BOUNDINGBOX_H
