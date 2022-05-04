//
// Created by Lennert Steyaert on 02/05/2022.
//

#include "Model/Cross/CrossModel.h"

CrossModel::CrossModel(ShaderType type) : BaseModel(type) {
    color = glm::vec3(0.9,0.9,0.9);

    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = std::vector<float> {
//            // positions          // colors           // texture coords
            0.01f,  0.08f, 0.0f,   0.9f, 0.9f, 0.9f,
            0.01f, 0.03f, 0.0f,   0.9f, 0.9f, 0.9f,
            -0.01f, 0.03f, 0.0f,   0.9f, 0.9f, 0.9f,
            -0.01f,  0.08f, 0.0f,   0.9f, 0.9f, 0.9f,

            0.01f,  -0.03f, 0.0f,   0.9f, 0.9f, 0.9f,
            0.01f, -0.08f, 0.0f,   0.9f, 0.9f, 0.9f,
            -0.01f, -0.08f, 0.0f,   0.9f, 0.9f, 0.9f,
            -0.01f,  -0.03f, 0.0f,   0.9f, 0.9f, 0.9f,

            0.08f,  0.01f, 0.0f,   0.9f, 0.9f, 0.9f,
            0.08f, -0.01f, 0.0f,   0.9f, 0.9f, 0.9f,
            0.03f, -0.01f, 0.0f,   0.9f, 0.9f, 0.9f,
            0.03f,  0.01f, 0.0f,   0.9f, 0.9f, 0.9f,

            -0.03f,  0.01f, 0.0f,   0.9f, 0.9f, 0.9f,
            -0.03f, -0.01f, 0.0f,   0.9f, 0.9f, 0.9f,
            -0.08f, -0.01f, 0.0f,   0.9f, 0.9f, 0.9f,
            -0.08f,  0.01f, 0.0f,   0.9f, 0.9f, 0.9f

    };
    this->indices = std::vector<GLuint>
            {
                    0, 1, 3, // first triangle
                    1, 2, 3,  // second triangle

                    4, 5, 7, // first triangle
                    5, 6, 7,  // second triangle

                    8, 9, 11, // first triangle
                    9, 10, 11,  // second triangle

                    12, 13, 15, // first triangle
                    13, 14, 15,  // second triangle
            };

    this->vbo = std::make_unique<VBO>(vertices,vertices.size(),true);
    this->ebo = std::make_unique<EBO>(indices,indices.size());


    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //vao.linkAttrib(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    vao->unbind();
    vbo->unbind();
    ebo->unbind();

    this->position = glm::vec3(0.0,0.0,0.0);
}


CrossModel::~CrossModel() {

}


void CrossModel::updatePosition(glm::vec3 pos) {
    this->position = pos;
    updateColor(pos);
}


void CrossModel::shoot(){
    updateColor(glm::vec3(1.0,0.0,0.0));
}

void CrossModel::resetShoot() {
    updateColor(color);
}

void CrossModel::updateColor(glm::vec3 color) {
    std::cout << "color update" << std::endl;
    for(int i = 3;  i<94;i += 6){
        vertices[i] = color.x;
        vertices[i+1] = color.y;
        vertices[i+2] = color.z;
    }
    this->vbo->update(vertices,vertices.size());
}

void CrossModel::draw(Shader *shader) {
    shader->use();

    this->vao->bind();
    this->ebo->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);

    this->vao->unbind();
    this->ebo->unbind();
}

void CrossModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}
