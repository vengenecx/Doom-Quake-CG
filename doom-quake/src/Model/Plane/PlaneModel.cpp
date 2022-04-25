//
// Created by Lennert Steyaert on 25/04/2022.
//

#include "Model/Plane/PlaneModel.h"


PlaneModel::PlaneModel(Texture * texture, glm::vec3 pos, ShaderType type) : BaseModel(type){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = std::vector<float> {
//            // positions          // colors           // texture coords
            0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
    };
    this->indices = std::vector<GLuint>
            {
                    0, 1, 3, // first triangle
                    1, 2, 3  // second triangle
            };

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());
    this->ebo = std::make_unique<EBO>(indices,indices.size());

    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    //vao.linkAttrib(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    vao->unbind();
    vbo->unbind();
    ebo->unbind();


    this->texture = texture;

    this->position = pos;
}


PlaneModel::~PlaneModel() {
    std::cout << "deleted cubemodel" << std::endl;
    vao.release();
    vbo.release();
    ebo.release();
}


void PlaneModel::updatePosition(glm::vec3 pos){
    this->position = pos;
}

void PlaneModel::setTextures(Shader* shader) {
    this->texture->texUnit(shader,"texture1");
}

void PlaneModel::draw(Shader *shader) {
    shader->use();

    glm::mat4 m = glm::mat4(1.0f);
    m = glm::translate(m, position); // translate it down so it's at the center of the scene
    shader->setMat4("model", m);

    setTextures(shader);

    this->texture->bind();

    this->vao->bind();
    this->ebo->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
}

void PlaneModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}
