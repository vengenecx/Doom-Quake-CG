//
// Created by Lennert Steyaert on 04/05/2022.
//

#include "Hit/Hit.h"

Hit::Hit(glm::vec3 pos, BoundingBox& bb) : point(pos){
    calculateAlignment(bb);
    initDraw();
}

void Hit::calculateAlignment(BoundingBox& bx) {
    float min_x = bx.centre.x - bx.dimensions.x/2.0;
    float max_x = bx.centre.x + bx.dimensions.x/2.0;

    float min_y = bx.centre.y - bx.dimensions.y/2.0;
    float max_y = bx.centre.y + bx.dimensions.y/2.0;

    float min_z = bx.centre.z - bx.dimensions.z/2.0;
    float max_z = bx.centre.z + bx.dimensions.z/2.0;



    if(min_x == point.x || max_x == point.x){
        std::cout << "1,2" << std::endl;
        alignment = X;

        if(min_x == point.x )
            point.x -= 0.01;
        else
            point.x += 0.01;

    } else if(min_y == point.y || max_y == point.y) {
        std::cout << "3,4" << std::endl;
        alignment = EAligment::Y;

        if(min_y == point.y )
            point.y -= 0.01;
        else
            point.y += 0.01;

    } else if(min_z == point.z || max_z == point.z) {
        std::cout << "5,6" << std::endl;
        alignment = Z;

        if(min_z == point.z )
            point.z -= 0.01;
        else
            point.z += 0.01;
    }
}

glm::vec3 Hit::getPoint(){
    return point;
}


EAligment Hit::getAlignment(){
    return alignment;
}


void Hit::initDraw() {


    static float x_pos = 0.1;
    static float x_neg = -0.1;

    static float y_pos = 0.1;
    static float y_neg = -0.1;

    static float z_pos = 0.1;
    static float z_neg = -0.1;


    glm::vec3 col = glm::vec3(1.0,1.0,1.0);

    std:: cout << static_cast<int>(alignment)  << std::endl;

    if(alignment == EAligment::Z){
        std::cout<< "z"  << std::endl;
        this->vertices.push_back(x_pos);
        this->vertices.push_back(y_pos);
        this->vertices.push_back(0);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(1);
        this->vertices.push_back(1);

        this->vertices.push_back(x_pos);
        this->vertices.push_back(y_neg);
        this->vertices.push_back(0);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(1);
        this->vertices.push_back(0);

        this->vertices.push_back(x_neg);
        this->vertices.push_back(y_neg);
        this->vertices.push_back(0);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(0);
        this->vertices.push_back(0);

        this->vertices.push_back(x_neg);
        this->vertices.push_back(y_pos);
        this->vertices.push_back(0);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(0);
        this->vertices.push_back(1);
    } else if(alignment == Y){
        std::cout<< "y"  << std::endl;
        this->vertices.push_back(x_pos);
        this->vertices.push_back(0);
        this->vertices.push_back(z_pos);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(0);
        this->vertices.push_back(0);

        this->vertices.push_back(x_pos);
        this->vertices.push_back(0);
        this->vertices.push_back(z_neg);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(1);
        this->vertices.push_back(0);

        this->vertices.push_back(x_neg);
        this->vertices.push_back(0);
        this->vertices.push_back(z_neg);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(0);
        this->vertices.push_back(0);

        this->vertices.push_back(x_neg);
        this->vertices.push_back(0);
        this->vertices.push_back(z_pos);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(0);
        this->vertices.push_back(1);
    } else{
        std::cout<< "x"  << std::endl;
        this->vertices.push_back(0);
        this->vertices.push_back(y_pos);
        this->vertices.push_back(z_pos);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(1);
        this->vertices.push_back(1);


        this->vertices.push_back(0);
        this->vertices.push_back(y_pos);
        this->vertices.push_back(z_neg);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(1);
        this->vertices.push_back(0);

        this->vertices.push_back(0);
        this->vertices.push_back(y_neg);
        this->vertices.push_back(z_neg);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(0);
        this->vertices.push_back(0);

        this->vertices.push_back(0);
        this->vertices.push_back(y_neg);
        this->vertices.push_back(z_pos);

        this->vertices.push_back(col.x);
        this->vertices.push_back(col.y);
        this->vertices.push_back(col.z);

        this->vertices.push_back(0);
        this->vertices.push_back(1);
    }

    this->indices = std::vector<GLuint>
            {
                    0, 1, 3, // first triangle
                    1, 2, 3  // second triangle
            };


    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());
    this->ebo = std::make_unique<EBO>(indices,indices.size());


    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao->linkAttrib(vbo.get(), 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    vao->unbind();
    vbo->unbind();
    ebo->unbind();

//    this->texture = texture;
}

void Hit::setTextures(Shader* shader, Texture* texture) {
    texture->texUnit(shader,"texture1");
}

void Hit::draw(Shader* shader,Texture* texture){
    shader->use();

    glm::mat4 m = glm::mat4(1.0f);

    m = glm::translate(m, point);
    shader->setMat4("model", m);

    setTextures(shader, texture);

    texture->bind();

    this->vao->bind();
    this->ebo->bind();

    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);

    this->vao->unbind();
    this->ebo->unbind();
}