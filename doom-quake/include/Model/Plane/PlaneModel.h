//
// Created by Lennert Steyaert on 25/04/2022.
//

#ifndef DOOM_QUAKE_PLANEMODEL_H
#define DOOM_QUAKE_PLANEMODEL_H


#include "Model/BaseModel.h"

class PlaneModel : public BaseModel {
public:
    // mesh data

    PlaneModel(Texture * texture_1, glm::vec3, ShaderType type);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~PlaneModel();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    Texture* texture;

    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    glm::vec3 position;

    void setTextures(Shader* shader);
};

#endif //DOOM_QUAKE_PLANEMODEL_H
