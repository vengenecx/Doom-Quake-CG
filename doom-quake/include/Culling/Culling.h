//
// Created by Lennert Steyaert on 07/05/2022.
//

#ifndef DOOM_QUAKE_CULLING_H
#define DOOM_QUAKE_CULLING_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include <vector>
#include "Register/VAO.h"
#include "Register/EBO.h"
#include "Shaders/Shader.h"

class Culling {
public:

    Culling(bool draw=true);
    Culling(const glm::vec3  origin, const glm::vec3 direction,bool draw=true);

    glm::vec3 getLeft();
    glm::vec3 getRight();
    glm::vec3 getOrigin();

//
    void draw(Shader* shader);

    void setCulling(const glm::vec3  origin, const glm::vec3 direction);

//    point3 at(double t) const {
//        return orig + t*dir;
//    }
private:
    glm::vec3 left;
    glm::vec3 right;
    glm::vec3 origin;

    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    void initDraw();

    void calculateVectors(glm::vec3 direction);
};


#endif //DOOM_QUAKE_CULLING_H
