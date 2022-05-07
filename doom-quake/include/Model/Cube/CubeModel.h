//
// Created by Lennert Steyaert on 29/03/2022.
//

#ifndef DOOM_QUAKE_CUBEMODEL_H
#define DOOM_QUAKE_CUBEMODEL_H

#include "Model/BaseModel.h"

class CubeModel : public BaseModel {
public:
    // mesh data
    CubeModel(glm::vec3 dimensions,Texture * texture_1, Texture * texture_2, glm::vec3 position, ShaderType type);
    CubeModel(Texture * texture_1, Texture * texture_2, glm::vec3, ShaderType type);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~CubeModel();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

//    std::unique_ptr<Texture> texture_1;
//    std::unique_ptr<Texture> texture_2;
    Texture* texture_1;
    Texture*  texture_2;

    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    glm::vec3 position;

    void setTextures(Shader* shader);

    void fillVertices(glm::vec3 dimensions);
};

#endif //DOOM_QUAKE_CUBEMODEL_H
