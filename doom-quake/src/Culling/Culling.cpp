//
// Created by Lennert Steyaert on 07/05/2022.
//

#include "Culling/Culling.h"


Culling::Culling(bool draw) {
//    if(draw)
//        initDraw();
}

Culling::Culling(const glm::vec3  origin, const glm::vec3 direction, bool draw) : origin(origin) {
    calculateVectors(direction);

}

void Culling::setCulling(const glm::vec3  origin, const glm::vec3 direction){
//    glm::vec3 col = glm::vec3(0.0,0.0,1.0);
    this->origin = origin;
    this->direction = direction;

    calculateVectors(direction);

//    glm::vec3 col = glm::vec3(0.0,0.0,1.0);

//    this->vertices.clear();
//
//    this->vertices.push_back(origin.x + (1.0*left.x));
//    this->vertices.push_back(origin.y + (1.0*left.y));
//    this->vertices.push_back(origin.z + (1.0*left.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vertices.push_back(origin.x + (100*left.x));
//    this->vertices.push_back(origin.y + (100*left.y));
//    this->vertices.push_back(origin.z + (100*left.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vertices.push_back(origin.x + + (1.0*right.x));
//    this->vertices.push_back(origin.y + + (1.0*right.y));
//    this->vertices.push_back(origin.z + + (1.0*right.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vertices.push_back(origin.x + (100*right.x));
//    this->vertices.push_back(origin.y + (100*right.y));
//    this->vertices.push_back(origin.z + (100*right.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//    this->vbo->update(vertices,vertices.size());
}


void Culling::calculateVectors(glm::vec3 direction){
    glm::mat4 rotationMat1(1);
    glm::mat4 rotationMat2(1);

//    direction.y = 0;

    rotationMat1 = glm::rotate(rotationMat1, 0.7853981634f, glm::vec3(0.0, 1.0, 0.0));
    rotationMat2 = glm::rotate(rotationMat2, -0.7853981634f, glm::vec3(0.0, 1.0, 0.0));

    left = glm::vec3(rotationMat1 * glm::vec4(direction, 1.0));
    right = glm::vec3(rotationMat2 * glm::vec4(direction, 1.0));

//    left.y = 0;
//    right.y = 0;
//    glm::vec3 point = culling->getOrigin();
//    glm::vec3 left = culling->getRight();
//    glm::vec3 right = culling->getLeft();
//
//    float a1 = (min_z-point.z)/(left.z);
//    float a2 = (min_z-point.z)/(right.z);
//
//    float x1 = point.x + a1*left.x;
//    float x2 = point.x + a2*right.x;
//
//    if(x2 < x1)
//        std::swap(x1,x2);

}

glm::vec3 Culling::getOrigin(){
    return origin;
}

glm::vec3 Culling::getLeft(){
    return left;
}

glm::vec3 Culling::getRight() {
    return right;
}


glm::vec3 Culling::getDirection() {
    return direction;
}


//void Culling::initDraw(){
//    this->vao = std::make_unique<VAO>();
//    this->vao->bind();
//
//    this->vertices = std::vector<float>();
//
//    glm::vec3 col = glm::vec3(0.0,1.0,0.0);
//
//    // Upper left to right front
//    this->vertices.push_back(origin.x);
//    this->vertices.push_back(origin.y);
//    this->vertices.push_back(origin.z);
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vertices.push_back(origin.x + (100*left.x));
//    this->vertices.push_back(origin.y + (100*left.y));
//    this->vertices.push_back(origin.z + (100*left.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vertices.push_back(origin.x);
//    this->vertices.push_back(origin.y);
//    this->vertices.push_back(origin.z);
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vertices.push_back(origin.x + (100*right.x));
//    this->vertices.push_back(origin.y + (100*right.y));
//    this->vertices.push_back(origin.z + (100*right.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->indices = std::vector<GLuint>
//            {
//                    0,1,
//                    2,3
//            };
//
//    this->vbo = std::make_unique<VBO>(vertices,vertices.size());
//    this->ebo = std::make_unique<EBO>(indices,indices.size());
//
//    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
//    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//
//    vao->unbind();
//    vbo->unbind();
//    ebo->unbind();
//}

//void Culling::draw(Shader * shader){
//    shader->use();
//
//    glm::mat4 m = glm::mat4(1.0f);
//    //m = glm::translate(m, position); // translate it down so it's at the center of the scene
//
//    m = glm::translate(m, glm::vec3(0.0,0.0,0.0));
//    shader->setMat4("model", m);
//
//
//    this->vao->bind();
//    this->ebo->bind();
//
//    glDrawElements(GL_LINES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
//
//    this->vao->unbind();
//    this->ebo->unbind();
//}