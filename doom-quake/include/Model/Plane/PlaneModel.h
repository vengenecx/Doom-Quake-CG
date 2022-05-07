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
    PlaneModel(std::vector<float> vertices, Texture * texture_1, glm::vec3, ShaderType type); // deprecated
    PlaneModel(std::vector<float> vertices, BoundingBox&bx, Texture * texture_1, glm::vec3, ShaderType type); // deprecated
    PlaneModel(glm::vec3 dimensions, bool wall,  Texture * texture, glm::vec3 pos, ShaderType type);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~PlaneModel();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    Texture* texture;

    std::vector<GLuint> indices;

    std::vector<float> vertices;

    glm::vec3 position;

    void setTextures(Shader* shader);

    void generateBoundingbox();
};

#endif //DOOM_QUAKE_PLANEMODEL_H
