#ifndef DOOM_QUAKE_LIGHTBOX_H
#define DOOM_QUAKE_LIGHTBOX_H

#include "Model/BaseModel.h"

class LightBox : public BaseModel {
public:
    // mesh data
    LightBox(glm::vec3 dimensions,Texture * texture_1, Texture * texture_2, glm::vec3 position, ShaderType type);
    LightBox(Texture * texture_1, Texture * texture_2, glm::vec3, ShaderType type);
    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~LightBox();
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

#endif //DOOM_QUAKE_LIGHTBOX
