//
// Created by Lennert Steyaert on 29/03/2022.
//

#ifndef DOOM_QUAKE_CUBEMODEL_H
#define DOOM_QUAKE_CUBEMODEL_H

#include "Model/BaseModel.h"

class CubeModel : public BaseModel {
public:
    // mesh data

    CubeModel(Shader * shader, Texture * texture_1, Texture * texture_2, glm::vec3);
    void draw(Shader * shader);

    void remove();
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


};
#endif //DOOM_QUAKE_CUBEMODEL_H
