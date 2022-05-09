//
// Created by Lennert Steyaert on 02/05/2022.
//

#ifndef DOOM_QUAKE_TESTMODEL_H
#define DOOM_QUAKE_TESTMODEL_H

#include "Octree/Node.h"



class TestModel : public BaseModel {
public:
    // mesh data
    TestModel(glm::vec3 dimensions,Texture * texture_1, glm::vec3 position, ShaderType type);

    void updatePosition(glm::vec3 pos);
    void draw(Shader * shader);
    void remove();

    ~TestModel();

    void setPositionLight(glm::vec3 positionLight);
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


    glm::vec3 positionLight;

    void setTextures(Shader* shader);

    void fillVertices(glm::vec3 dimensions);
};

#endif //DOOM_QUAKE_OCTREE_H


