//
// Created by Lennert Steyaert on 09/05/2022.
//

#ifndef DOOM_QUAKE_POINTLIGHT_H
#define DOOM_QUAKE_POINTLIGHT_H


#include "Model/BaseModel.h"

class PointLight : public BaseModel {
public:
    PointLight(glm::vec3 dimensions, glm::vec3 position, ShaderType type);

    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~PointLight();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    std::vector<GLuint> indices;
    std::vector<float> vertices;


    glm::vec3 position;

    void setTextures(Shader* shader);

    void generateBoundingbox();

    void fillVertices(glm::vec3 dimensions);
};



#endif //DOOM_QUAKE_POINTLIGHT_H
