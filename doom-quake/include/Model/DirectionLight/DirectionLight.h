//
// Created by Lennert Steyaert on 11/05/2022.
//

#ifndef DOOM_QUAKE_DIRECTIONLIGHT_H
#define DOOM_QUAKE_DIRECTIONLIGHT_H
#include "Model/BaseModel.h"

class DirectionLight : public BaseModel {
public:
    DirectionLight(glm::vec3 dimensions, glm::vec3 position, ShaderType type, glm::vec3 ambient = glm::vec3(0.05,0.05,0.05),glm::vec3 diffuse = glm::vec3(0.8,0.8,0.8), glm::vec3 specular = glm::vec3(0.2,0.2,0.2));

    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    void setupShader(Shader * shader,uint &pos);

    ~DirectionLight();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    std::vector<GLuint> indices;
    std::vector<float> vertices;

    glm::vec3 position;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    void setTextures(Shader* shader);
    void fillVertices(glm::vec3 dimensions);
};


#endif //DOOM_QUAKE_DIRECTIONLIGHT_H
