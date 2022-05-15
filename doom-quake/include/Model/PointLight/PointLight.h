//
// Created by Lennert Steyaert on 09/05/2022.
//

#ifndef DOOM_QUAKE_POINTLIGHT_H
#define DOOM_QUAKE_POINTLIGHT_H


#include "Model/BaseModel.h"

class PointLight : public BaseModel {
public:
    PointLight(glm::vec3 dimensions, glm::vec3 position, ShaderType type, glm::vec3 ambient = glm::vec3(0.0,0.0,0.0),glm::vec3 diffuse = glm::vec3(0.8,0.8,0.8), glm::vec3 specular = glm::vec3(0.2,0.2,0.2), float constant = 1.0f, float linear = 0.014f,  float quadratic = 0.0007f);

    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    void setupShader(Shader * shader,uint &pos);

    ~PointLight();
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
    float constant;
    float linear;
    float quadratic;

    void setTextures(Shader* shader);
//    void generateBoundingbox();
    void fillVertices(glm::vec3 dimensions);
};



#endif //DOOM_QUAKE_POINTLIGHT_H
