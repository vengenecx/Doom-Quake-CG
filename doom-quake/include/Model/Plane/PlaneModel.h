//
// Created by Lennert Steyaert on 25/04/2022.
//

#ifndef DOOM_QUAKE_PLANEMODEL_H
#define DOOM_QUAKE_PLANEMODEL_H


#include "Model/BaseModel.h"

class PlaneModel : public BaseModel {
public:
    // mesh data
//    PlaneModel(Texture * texture_1, glm::vec3, ShaderType type);
//    PlaneModel(std::vector<float> vertices, Texture * texture_1, glm::vec3, ShaderType type);
//    PlaneModel(std::vector<float> vertices, BoundingBox&bx, Texture * texture_1, glm::vec3, ShaderType type);
//

    PlaneModel(glm::vec3 dimensions, bool wall,  Texture * texture, glm::vec3 pos, ShaderType type);

    PlaneModel(glm::vec3 dimensions, bool wall, bool inside, Texture * texture_1, Texture* texture_2, glm::vec3 pos, ShaderType type, std::vector<BaseModel*> &light);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~PlaneModel();

    void setLights(Shader* shader);
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    Texture* texture_1;
    Texture* texture_2;

    std::vector<float> vertices;
    std::vector<GLuint> indices;


    glm::vec3 position;

    void fillVertices(glm::vec3 dimensions, bool wall, bool inside);
    void setTextures(Shader* shader);

//    void generateBoundingbox();
};

#endif //DOOM_QUAKE_PLANEMODEL_H
