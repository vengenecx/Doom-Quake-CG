//
// Created by Lennert Steyaert on 01/04/2022.
//

#ifndef DOOM_QUAKE_BOUNDINGBOX_H
#define DOOM_QUAKE_BOUNDINGBOX_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct BoundingBox {
    glm::vec3 q1;
    glm::vec3 q2;
    glm::vec3 q3;
    glm::vec3 q4;
    glm::vec3 q5;
    glm::vec3 q6;
    glm::vec3 q7;
    glm::vec3 q8;
};


#endif //DOOM_QUAKE_BOUNDINGBOX_H
