//
// Created by Lennert Steyaert on 24/04/2022.
//

#include "Model/Cube/CubeModel.h"


CubeModel::CubeModel(Shader* shader, Texture * texture_1, Texture * texture_2, glm::vec3 pos) {
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = std::vector<float> {
//            // positions          // colors           // texture coords
//            0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//            0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//            -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left


            -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,   0.0f, 1.0f

    };
    this->indices = std::vector<GLuint>
            {
//                    0, 1, 3, // first triangle
//                    1, 2, 3  // second triangle
                    0,1,2,
                    3,4,5,

                    6,7,8,
                    9,10,11,

                    12,13,14,
                    15,16,17,

                    18,19,20,
                    21,22,23,

                    24,25,26,
                    27,28,29,

                    30,31,32,
                    33,34,35
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


    this->texture_1 = texture_1;
    this->texture_2 = texture_2;

    this->position = pos;
}


void CubeModel::setTextures(Shader* shader) {
    this->texture_1->texUnit(shader,"texture1");
    this->texture_2->texUnit(shader,"texture2");
}

void CubeModel::draw(Shader *shader) {
    shader->use();

    glm::mat4 m = glm::mat4(1.0f);
    m = glm::translate(m, position); // translate it down so it's at the center of the scene
    shader->setMat4("model", m);

    setTextures(shader);

    this->texture_1->bind();
    this->texture_2->bind();

    this->vao->bind();
    this->ebo->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
}

void CubeModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}
