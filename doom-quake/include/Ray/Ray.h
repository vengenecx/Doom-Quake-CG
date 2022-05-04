//
// Created by Lennert Steyaert on 01/04/2022.
//

#ifndef DOOM_QUAKE_RAY_H
#define DOOM_QUAKE_RAY_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include "Register/VAO.h"
#include "Register/EBO.h"
#include "Shaders/Shader.h"

class Ray {
public:

    Ray(bool draw=true);
    Ray(const glm::vec3  origin, const glm::vec3 direction,bool draw=true);

    glm::vec3 getOrigin();
    glm::vec3 getDirection();

//
//    void draw(Shader* shader);

    void setRay(const glm::vec3  origin, const glm::vec3 direction);

//    point3 at(double t) const {
//        return orig + t*dir;
//    }
private:
    glm::vec3 direction;
    glm::vec3 origin;

//    std::unique_ptr<VAO> vao;
//    std::unique_ptr<VBO> vbo;
//    std::unique_ptr<EBO> ebo;
//
//    std::vector<float>  vertices;
//    std::vector<GLuint> indices;
//
//    void initDraw();
};

#endif //DOOM_QUAKE_RAY_H
