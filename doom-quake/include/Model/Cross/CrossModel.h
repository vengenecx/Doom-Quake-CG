//
// Created by Lennert Steyaert on 02/05/2022.
//

#ifndef DOOM_QUAKE_CROSSMODEL_H
#define DOOM_QUAKE_CROSSMODEL_H

#include "Model/BaseModel.h"

class CrossModel : public BaseModel {
public:
    // mesh data

    CrossModel(ShaderType type);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    void shoot();
    void resetShoot();

    ~CrossModel();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

    glm::vec3 color;

//    std::unique_ptr<Texture> texture_1;
//    std::unique_ptr<Texture> texture_2;

    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    glm::vec3 position;


    void updateColor(glm::vec3 color);
};

#endif //DOOM_QUAKE_CROSSMODEL_H
