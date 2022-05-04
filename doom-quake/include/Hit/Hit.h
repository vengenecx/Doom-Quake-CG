//
// Created by Lennert Steyaert on 04/05/2022.
//

#ifndef DOOM_QUAKE_HIT_H
#define DOOM_QUAKE_HIT_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Model/BaseModel.h"

static enum EAligment {
    X = 0,
    Y = 1,
    Z = 2
} eAligment;

class Hit {
public:

    Hit(glm::vec3 pos, BoundingBox& bb);
    ~Hit();

    glm::vec3 getPoint();
    EAligment getAlignment();


    void draw(Shader * shader, Texture* texture);

    void remove();

private:
    glm::vec3 point;
    EAligment alignment;


    void calculateAlignment(BoundingBox& bx);
    void initDraw();

    void setTextures(Shader* shader, Texture* texture);



    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;


    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    glm::vec3 position;


};

#endif //DOOM_QUAKE_HIT_H
