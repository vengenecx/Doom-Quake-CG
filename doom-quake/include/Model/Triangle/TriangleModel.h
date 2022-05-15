#ifndef DOOM_QUAKE_TRIANGLEMODEL_H
#define DOOM_QUAKE_TRIANGLEMODEL_H

#include "Model/BaseModel.h"

// NOT USED

class TriangleModel : public BaseModel {
public:
    // mesh data

    TriangleModel(Texture * texture_1, glm::vec3, ShaderType type);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~TriangleModel();
private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

//    std::unique_ptr<Texture> texture_1;
//    std::unique_ptr<Texture> texture_2;
    Texture* texture_1;
    // Texture*  texture_2;

    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    glm::vec3 position;

    void setTextures(Shader* shader);
};

#endif // DOOM_QUAKE_TRIANGLEMODEL_H
