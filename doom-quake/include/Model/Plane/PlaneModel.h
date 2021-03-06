//
// Created by Lennert Steyaert on 25/04/2022.
//

#ifndef DOOM_QUAKE_PLANEMODEL_H
#define DOOM_QUAKE_PLANEMODEL_H


#include "Model/BaseModel.h"

class PlaneModel : public BaseModel {
public:
    PlaneModel(glm::vec3 dimensions, bool wall,  Texture * texture, glm::vec3 pos, ShaderType type);

    PlaneModel(glm::vec3 dimensions, bool wall, bool inside, Texture * texture_1, Texture* texture_2, glm::vec3 pos, ShaderType type, std::vector<BaseModel*> &light, bool reflect=false);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~PlaneModel();

    void setLights(Shader* shader);
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;

    Texture* texture_1;
    Texture* texture_2;

    std::vector<float> vertices;

    glm::vec3 position;

    void fillVertices(glm::vec3 dimensions, bool wall, bool inside);
    void setTextures(Shader* shader);

    bool reflect;
};

#endif //DOOM_QUAKE_PLANEMODEL_H
