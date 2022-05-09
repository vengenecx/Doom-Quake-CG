//
// Created by Lennert Steyaert on 09/05/2022.
//

#include "Model/Test/TestModel.h"

TestModel::TestModel(glm::vec3 dimensions,Texture * texture_1, glm::vec3 position, ShaderType type) : BaseModel(type){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->position =  position;

    fillVertices(dimensions);


    this->indices = std::vector<GLuint>
                    {
       // 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35
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




    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 2, 3, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 3, 2, GL_FLOAT, 11 * sizeof(float), (void*)(9 * sizeof(float)));

    //vao.linkAttrib(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    vao->unbind();
    vbo->unbind();
    ebo->unbind();


    this->texture_1 = texture_1;


    this->bb = BoundingBox();
    this->bb.centre = position;
    this->bb.dimensions  =  glm::vec3(dimensions.x,dimensions.y,dimensions.z);

    std::cout << "testmodel initiated" << std::endl;
}



void TestModel::fillVertices(glm::vec3 dimensions){

    glm::vec3 color = glm::vec3(1,1,1);

//    float v[] = {
//            // positions          // normals           // texture coords
//            -0.5f, -0.5f, -0.5f,  1.0f,1.0f,1.0f, 0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//            0.5f, -0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//            0.5f,  0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//            0.5f,  0.5f, -0.5f, 1.0f,1.0f,1.0f, 0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//            -0.5f,  0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//            -0.5f, -0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//            -0.5f, -0.5f,  0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//            0.5f, -0.5f,  0.5f, 1.0f,1.0f,1.0f, 0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//            0.5f,  0.5f,  0.5f, 1.0f,1.0f,1.0f, 0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//            0.5f,  0.5f,  0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//            -0.5f,  0.5f,  0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//            -0.5f, -0.5f,  0.5f,  1.0f,1.0f,1.0f,0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//            -0.5f,  0.5f,  0.5f, 1.0f,1.0f,1.0f,-1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//            -0.5f,  0.5f, -0.5f,1.0f,1.0f,1.0f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//            -0.5f, -0.5f, -0.5f, 1.0f,1.0f,1.0f,-1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//            -0.5f, -0.5f, -0.5f, 1.0f,1.0f,1.0f,-1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//            -0.5f, -0.5f,  0.5f, 1.0f,1.0f,1.0f,-1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//            -0.5f,  0.5f,  0.5f, 1.0f,1.0f,1.0f,-1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//            0.5f,  0.5f,  0.5f, 1.0f,1.0f,1.0f, 1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//            0.5f,  0.5f, -0.5f, 1.0f,1.0f,1.0f, 1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//            0.5f, -0.5f, -0.5f, 1.0f,1.0f,1.0f, 1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//            0.5f, -0.5f, -0.5f,  1.0f,1.0f,1.0f,1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//            0.5f, -0.5f,  0.5f, 1.0f,1.0f,1.0f, 1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//            0.5f,  0.5f,  0.5f, 1.0f,1.0f,1.0f, 1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//            -0.5f, -0.5f, -0.5f, 1.0f,1.0f,1.0f, 0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//            0.5f, -0.5f, -0.5f, 1.0f,1.0f,1.0f, 0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//            0.5f, -0.5f,  0.5f, 1.0f,1.0f,1.0f, 0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//            0.5f, -0.5f,  0.5f, 1.0f,1.0f,1.0f, 0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//            -0.5f, -0.5f,  0.5f, 1.0f,1.0f,1.0f, 0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//            -0.5f, -0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//            -0.5f,  0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//            0.5f,  0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//            0.5f,  0.5f,  0.5f, 1.0f,1.0f,1.0f, 0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f,1.0f,1.0f,0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//            -0.5f,  0.5f,  0.5f,  1.0f,1.0f,1.0f,0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//            -0.5f,  0.5f, -0.5f,  1.0f,1.0f,1.0f,0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//    };
//
//    for(float f:v){
//        this->vertices.push_back(f);
//    }


     //Surface 1
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(-1);

    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(-1);

    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(-1);

    this->vertices.push_back(1);
    this->vertices.push_back(1);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(-1);

    this->vertices.push_back(0);
    this->vertices.push_back(1);


    // Surface 2
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(1);

    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(1);

    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(1);

    this->vertices.push_back(1);
    this->vertices.push_back(1);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(0);
    this->vertices.push_back(1);


    this->vertices.push_back(0);
    this->vertices.push_back(1);

    // Surface 3
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(-1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(-1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(1);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(-1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(0);
    this->vertices.push_back(1);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(-1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(0);
    this->vertices.push_back(0);

    // Surface 4
    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(1);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(0);
    this->vertices.push_back(1);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(1);
    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(0);
    this->vertices.push_back(0);

    // Surface 5
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(-1);
    this->vertices.push_back(0);

    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(-1);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(-1);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(1);

    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(-dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(-1);
    this->vertices.push_back(0);

    this->vertices.push_back(0);
    this->vertices.push_back(1);

    // Surface 6
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(0);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(-dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    this->vertices.push_back(0);
    this->vertices.push_back(1);
    this->vertices.push_back(0);

    this->vertices.push_back(1);
    this->vertices.push_back(1);


    // Vertex
    // Pos
    this->vertices.push_back(-dimensions.x/2);
    this->vertices.push_back(dimensions.y/2);
    this->vertices.push_back(dimensions.z/2);

    // Color
    this->vertices.push_back(color.x);
    this->vertices.push_back(color.y);
    this->vertices.push_back(color.z);

    // Normal
    this->vertices.push_back(0);
    this->vertices.push_back(1);
    this->vertices.push_back(0);

    // Texture coordinate
    this->vertices.push_back(0);
    this->vertices.push_back(1);
}


TestModel::~TestModel() {
    std::cout << "deleted cubemodel" << std::endl;
    vao.release();
    vbo.release();
    ebo.release();
}


void TestModel::updatePosition(glm::vec3 pos){
    this->position = pos;
}

void TestModel::setTextures(Shader* shader) {
    this->texture_1->texUnit(shader,"material.diffuse");
    //this->texture_2->texUnit(shader,"texture2");
}

void TestModel::setPositionLight(glm::vec3 positionLight){
    this->positionLight = positionLight;
}

void TestModel::draw(Shader *shader) {
    shader->use();

    glm::mat4 m = glm::mat4(1.0f);
    m = glm::translate(m, position); // translate it down so it's at the center of the scene
    shader->setMat4("model", m);

    std::cout << "pos: " << position.x << std::endl;
//
//    std::cout << "pos light: " << positionLight.z << std::endl;

    setTextures(shader);

    shader->setFloat("material.shininess", 32.0f);

    shader->setVec3("pointLights[0].position", positionLight);
    shader->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
    shader->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
    shader->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
    shader->setFloat("pointLights[0].constant", 1.0f);
    shader->setFloat("pointLights[0].linear", 0.09f);
    shader->setFloat("pointLights[0].quadratic", 0.032f);




    this->texture_1->bind();

    this->vao->bind();
    this->ebo->bind();

   glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, static_cast<unsigned int>(indices.size()));

    show = true;
}

void TestModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}

