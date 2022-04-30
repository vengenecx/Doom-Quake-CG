#include "Model/Triangle/TriangleModel.h"


TriangleModel::TriangleModel(Texture * texture_1, glm::vec3 pos, ShaderType type) : BaseModel(type){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = std::vector<float> {
//            // positions          // colors           // texture coords
            -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 1.0f,   0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 0.0f,   1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 1.0f,   1.0f, 1.0f,
    };
    this->indices = std::vector<GLuint>
            {
//                    0, 1, 3, // first triangle
//                    1, 2, 3  // second triangle
                    0,1,2,
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
    // this->texture_2 = texture_2;

    this->position = pos;
}


TriangleModel::~TriangleModel() {
    std::cout << "deleted TriangleModel" << std::endl;
    vao.release();
    vbo.release();
    ebo.release();
}


void TriangleModel::updatePosition(glm::vec3 pos){
    this->position = pos;
}

void TriangleModel::setTextures(Shader* shader) {
    this->texture_1->texUnit(shader,"texture1");
    // this->texture_2->texUnit(shader,"texture2");
}

void TriangleModel::draw(Shader *shader) {
    shader->use();

    glm::mat4 m = glm::mat4(1.0f);
    m = glm::translate(m, position); // translate it down so it's at the center of the scene
    shader->setMat4("model", m);

    setTextures(shader);

    this->texture_1->bind();
    // this->texture_2->bind();

    this->vao->bind();
    this->ebo->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
}

void TriangleModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}
