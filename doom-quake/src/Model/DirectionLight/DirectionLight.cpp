//
// Created by Lennert Steyaert on 11/05/2022.
//

#include "Model/DirectionLight/DirectionLight.h"



DirectionLight::DirectionLight(glm::vec3 dimensions, glm::vec3 position, ShaderType type, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) :
        BaseModel(type), ambient(ambient), diffuse(diffuse), specular(specular){

    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->position =  position;

    fillVertices(dimensions);


    this->indices = std::vector<GLuint>
            {
                    // First surface
                    0, 1, 3, // first triangle
                    1, 2, 3, // second triangle
                    // Second surface
                    4, 5, 7, // first triangle
                    5, 6, 7, // second triangle
                    // Third surface
                    8, 9, 11,  // first triangle
                    9, 10, 11, // second triangle
                    // Fourth surface
                    12, 13, 15,  // first triangle
                    13, 14, 15,  // second triangle
                    // Fifth surface
                    16, 17, 19,  // first triangle
                    17, 18, 19,  // second triangle
                    // Sixt surface
                    20, 21, 23,  // first triangle
                    21, 22, 23  // second triangle
            };

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());
    this->ebo = std::make_unique<EBO>(indices,indices.size());


    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    vao->unbind();
    vbo->unbind();
    ebo->unbind();


    this->bb = BoundingBox();
    this->bb.centre = position;
    this->bb.dimensions  =  glm::vec3(dimensions.x,dimensions.y,dimensions.z);

    this->vertices.clear();
    this->indices.clear();
}


void DirectionLight::fillVertices(glm::vec3 dimensions){

    glm::vec3 color = glm::vec3(1,1,1);
    glm::vec3 colorBlack = glm::vec3(0,0,0);


    // Surface 1
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);


    // Surface 2
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);

    // Surface 3
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);


    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);


    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);


    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);


    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);


    // Surface 4
    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);


    // Surface 5
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);


    // Surface 6
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);


    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(colorBlack.x);
    this->vertices.push_back(colorBlack.y);
    this->vertices.push_back(colorBlack.z);

}


DirectionLight::~DirectionLight()  {
    std::cout << "deleted cubemodel" << std::endl;
    vao.release();
    vbo.release();
    ebo.release();
}


void DirectionLight::updatePosition(glm::vec3 pos){
    this->position = pos;
}

void DirectionLight::setupShader(Shader * shader,uint &pos){
    shader->setBool("directionLightState", true);
    shader->setVec3("dirLight.position", position);
    shader->setVec3("dirLight.ambient", ambient);
    shader->setVec3("dirLight.diffuse", diffuse);
    shader->setVec3("dirLight.specular", specular);
}

void DirectionLight::draw(Shader *shader) {
    shader->use();

    glm::mat4 m = glm::mat4(1.0f);
    m = glm::translate(m, position); // translate it down so it's at the center of the scene
    shader->setMat4("model", m);

    this->vao->bind();
    this->ebo->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);

    this->vao->unbind();
    this->ebo->unbind();
}

void DirectionLight::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}
