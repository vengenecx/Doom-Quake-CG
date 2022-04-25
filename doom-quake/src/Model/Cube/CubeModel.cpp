//
// Created by Lennert Steyaert on 24/04/2022.
//

#include "Model/Cube/CubeModel.h"


CubeModel::CubeModel(Shader* shader) {
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = std::vector<float> {
            // positions          // colors           // texture coords
            0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
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


    const char *img_1 = "model-files/cube/container.jpg";
    const char *img_2 = "model-files/cube/awesomeface.png";
    this->texture_1 = std::make_unique<Texture>(img_1,GL_TEXTURE_2D,0,GL_RGB,GL_UNSIGNED_BYTE);
    this->texture_2 = std::make_unique<Texture>(img_2,GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE);

    this->texture_1->texUnit(shader,"texture1",0);
    this->texture_2->texUnit(shader,"texture2",1);
}


void CubeModel::draw(Shader *shader) {
    shader->use();

    this->texture_1->bind();
    this->texture_2->bind();

    this->vao->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
}

void CubeModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}
