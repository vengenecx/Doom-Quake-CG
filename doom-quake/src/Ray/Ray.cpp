//
// Created by Lennert Steyaert on 01/04/2022.
//

// with the help of following URL we will understand lighting and rays better: https://learnopengl.com/Lighting

#include "Ray/Ray.h"


Ray::Ray(bool draw) {
//    if(draw)
//        initDraw();
}

Ray::Ray(const glm::vec3  origin, const glm::vec3 direction, bool draw) : origin(origin), direction(direction) {
//    if(draw)
//        initDraw();
}

void Ray::setRay(const glm::vec3  origin, const glm::vec3 direction){
//    glm::vec3 col = glm::vec3(0.0,0.0,1.0);
    this->origin = origin;
    this->direction = direction;

//    this->vertices.clear();
//
//    this->vertices.push_back(origin.x);
//    this->vertices.push_back(origin.y);
//    this->vertices.push_back(origin.z);
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vertices.push_back(origin.x + (100*direction.x));
//    this->vertices.push_back(origin.y + (100*direction.y));
//    this->vertices.push_back(origin.z + (100*direction.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->vbo->update(vertices,vertices.size());
}

glm::vec3 Ray::getOrigin(){
    return origin;
}

glm::vec3 Ray::getDirection(){
    return direction;
}

//void Ray::initDraw(){
//    this->vao = std::make_unique<VAO>();
//    this->vao->bind();
//
//    this->vertices = std::vector<float>();
//
//    glm::vec3 col = glm::vec3(0.0,0.0,1.0);
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
//    this->vertices.push_back(origin.x + (100*direction.x));
//    this->vertices.push_back(origin.y + (100*direction.y));
//    this->vertices.push_back(origin.z + (100*direction.z));
//
//    this->vertices.push_back(col.x);
//    this->vertices.push_back(col.y);
//    this->vertices.push_back(col.z);
//
//    this->indices = std::vector<GLuint>
//            {
//                    0,1
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
//
//void Ray::draw(Shader * shader){
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