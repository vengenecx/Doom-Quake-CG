//
// Created by Lennert Steyaert on 01/04/2022.
//

#ifndef DOOM_QUAKE_RAY_H
#define DOOM_QUAKE_RAY_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Ray {
public:
private:
    glm::vec3 direction;
    glm::vec3 origin;
};

#endif //DOOM_QUAKE_RAY_H
