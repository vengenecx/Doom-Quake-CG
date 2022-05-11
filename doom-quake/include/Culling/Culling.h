//
// Created by Lennert Steyaert on 07/05/2022.
//

#ifndef DOOM_QUAKE_CULLING_H
#define DOOM_QUAKE_CULLING_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>


#include "glm/gtx/fast_square_root.hpp"

#include <vector>
#include "Register/VAO.h"
#include "Register/EBO.h"
#include "Shaders/Shader.h"
#include "Octree/BoundingBox.h"
#include <memory>

class Culling {
public:

    Culling(bool draw=true);
    Culling(const glm::vec3  origin, const glm::vec3 direction,bool draw=true);

    glm::vec3 getLeft();
    glm::vec3 getRight();
    glm::vec3 getDirection();

    glm::vec2 getDirectioPlaneY();

    glm::vec3 getOrigin();

    BoundingBox getBounding();

    void initDraw();

//
    void draw(Shader* shader);

    void setCulling(const glm::vec3  origin, const glm::vec3 direction);

//    point3 at(double t) const {
//        return orig + t*dir;
//    }
private:
    glm::vec3 direction;
    glm::vec2 dir;
    glm::vec3 left;
    glm::vec3 right;
    glm::vec3 origin;

    glm::vec3 dimensions;

    BoundingBox bounding;

    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    std::vector<GLuint> indices;
    std::vector<float> vertices;


    void calculateVectors(glm::vec3 direction);
};


#endif //DOOM_QUAKE_CULLING_H
