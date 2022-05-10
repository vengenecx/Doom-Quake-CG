//
// Created by Lennert Steyaert on 25/04/2022.
//

#include "Model/Plane/PlaneModel.h"



PlaneModel::PlaneModel(Texture * texture, glm::vec3 pos, ShaderType type) : BaseModel(type){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();


     this->vertices = std::vector<float> {
 //            // positions          // colors           // texture coords
             10.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
             10.0f, 0.0f, -10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
             -10.0f, 0.0f, -10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
             -10.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
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

    this->bb = BoundingBox();
    this->bb.centre = pos;
    this->bb.dimensions  =  glm::vec3(20,0.1,20);
}



PlaneModel::PlaneModel(glm::vec3 dimensions, bool wall,  Texture * texture, glm::vec3 pos, ShaderType type) : BaseModel(type){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = std::vector<float>();


    glm::vec3 color  = glm::vec3(1,1,1);

    if(wall){
        this->vertices.push_back(-dimensions.x/2);
        this->vertices.push_back(dimensions.y/2);
        this->vertices.push_back(dimensions.z/2);

        this->vertices.push_back(color.x);
        this->vertices.push_back(color.y);
        this->vertices.push_back(color.z);

        this->vertices.push_back(1);
        this->vertices.push_back(1);

        this->vertices.push_back(-dimensions.x/2);
        this->vertices.push_back(-dimensions.y/2);
        this->vertices.push_back(dimensions.z/2);

        this->vertices.push_back(color.x);
        this->vertices.push_back(color.y);
        this->vertices.push_back(color.z);

        this->vertices.push_back(1);
        this->vertices.push_back(0);

        this->vertices.push_back(dimensions.x/2);
        this->vertices.push_back(-dimensions.y/2);
        this->vertices.push_back(-dimensions.z/2);

        this->vertices.push_back(color.x);
        this->vertices.push_back(color.y);
        this->vertices.push_back(color.z);

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

    } else{
        this->vertices.push_back(dimensions.x/2);
        this->vertices.push_back(dimensions.y/2);
        this->vertices.push_back(dimensions.z/2);

        this->vertices.push_back(color.x);
        this->vertices.push_back(color.y);
        this->vertices.push_back(color.z);

        this->vertices.push_back(1);
        this->vertices.push_back(1);

        this->vertices.push_back(dimensions.x/2);
        this->vertices.push_back(dimensions.y/2);
        this->vertices.push_back(-dimensions.z/2);

        this->vertices.push_back(color.x);
        this->vertices.push_back(color.y);
        this->vertices.push_back(color.z);

        this->vertices.push_back(1);
        this->vertices.push_back(0);

        this->vertices.push_back(-dimensions.x/2);
        this->vertices.push_back(dimensions.y/2);
        this->vertices.push_back(-dimensions.z/2);

        this->vertices.push_back(color.x);
        this->vertices.push_back(color.y);
        this->vertices.push_back(color.z);

        this->vertices.push_back(0);
        this->vertices.push_back(0);

        this->vertices.push_back(-dimensions.x/2);
        this->vertices.push_back(dimensions.y/2);
        this->vertices.push_back(dimensions.z/2);

        this->vertices.push_back(color.x);
        this->vertices.push_back(color.y);
        this->vertices.push_back(color.z);

        this->vertices.push_back(0);
        this->vertices.push_back(1);
    }





//     this->vertices = std::vector<float> {
// //            // positions          // colors           // texture coords
//             10.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//             10.0f, 0.0f, -10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//             -10.0f, 0.0f, -10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//             -10.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//     };

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

    this->bb = BoundingBox();
    this->bb.centre = pos;
    this->bb.dimensions  =  glm::vec3(dimensions.x,dimensions.y,dimensions.z);

//    generateBoundingbox();
}


PlaneModel::PlaneModel(std::vector<float> vertices,  Texture * texture, glm::vec3 pos, ShaderType type) : BaseModel(type){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = vertices;
//     this->vertices = std::vector<float> {
// //            // positions          // colors           // texture coords
//             10.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//             10.0f, 0.0f, -10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//             -10.0f, 0.0f, -10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//             -10.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//     };

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

//    this->bb = BoundingBox();
//    this->bb.centre = pos;
//    this->bb.dimensions  =  glm::vec3(20,0.1,20);

    generateBoundingbox();
}



PlaneModel::PlaneModel(std::vector<float> vertices, BoundingBox& bx,  Texture * texture, glm::vec3 pos, ShaderType type) : BaseModel(type){
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = vertices;

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
    this->bb = bx;
}


PlaneModel::~PlaneModel() {
    std::cout << "deleted cubemodel" << std::endl;
    vao.release();
    vbo.release();
    ebo.release();
}

void PlaneModel::generateBoundingbox() {
    float x_min = this->vertices[0];
    float x_max = this->vertices[0];
    float y_min = this->vertices[1];
    float y_max = this->vertices[1];
    float z_min = this->vertices[2];
    float z_max = this->vertices[2];

    for(int i=0; i<this->vertices.size()-8; i+=8){
        if(x_min > this->vertices[i])
            x_min = this->vertices[i];
        if(x_max < this->vertices[i])
            x_max = this->vertices[i];

        if(y_min > this->vertices[i+1])
            y_min = this->vertices[i+1];
        if(y_max < this->vertices[i+1])
            y_max = this->vertices[i+1];

        if(z_min > this->vertices[i+2])
            z_min = this->vertices[i+2];
        if(z_max < this->vertices[i+2])
            z_max = this->vertices[i+2];
    }

//    if(y_min ==  y_max){
//        this->bb  = BoundingBox{position,glm::vec3(x_max-x_min,0.1,z_max-z_min)};
//    } else if(x_min == x_max){
//        this->bb  = BoundingBox{position,glm::vec3(0.1,y_max-y_min,z_max-z_min)};
//    } else{
//        this->bb  = BoundingBox{position,glm::vec3(x_max-x_min,y_max-y_min,0.1)};
//    }

    this->bb  = BoundingBox{position,glm::vec3(x_max-x_min,y_max-y_min,z_max-z_min)};
}

void PlaneModel::updatePosition(glm::vec3 pos){
    this->position = pos;
}

void PlaneModel::setTextures(Shader* shader) {
    this->texture->texUnit(shader,"texture1");
}

void PlaneModel::draw(Shader *shader) {
    if(!show){
        shader->use();

        glm::mat4 m = glm::mat4(1.0f);
        m = glm::translate(m, position); // translate it down so it's at the center of the scene
        shader->setMat4("model", m);

        setTextures(shader);

        this->texture->bind();

        this->vao->bind();
        this->ebo->bind();

        glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
        std::cout <<  ".";
        show = true;
    }
}

void PlaneModel::remove() {
    this->vao->remove();
    this->vbo->remove();
    this->ebo->remove();
}
