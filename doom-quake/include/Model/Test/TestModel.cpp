//
// Created by Lennert Steyaert on 02/05/2022.
//

#ifndef DOOM_QUAKE_TESTMODEL_H
#define DOOM_QUAKE_TESTMODEL_H

#include "Octree/Node.h"

class TestModel : public BaseModel
{
public:
//    TestModel(ShaderType type, std::unique_ptr<BoundingBox> bx)  : BaseModel(type, std::move(bx)){
    TestModel(ShaderType type, BoundingBox bx)  : BaseModel(type, bx){
        this->vao = std::make_unique<VAO>();
        this->vao->bind();

        this->vertices = std::vector<float>();

//        // Upper left to right front
//        this->vertices.push_back(bx->centre.x-bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y+bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);
//
//        this->vertices.push_back(bx->centre.x+bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y+bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);
//
//        // Uper right to bottom front
//        this->vertices.push_back(bx->centre.x+bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y+bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);
//
//        this->vertices.push_back(bx->centre.x+bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y-bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);
//
//        // Bottom right front to left
//        this->vertices.push_back(bx->centre.x+bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y-bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);
//
//        this->vertices.push_back(bx->centre.x-bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y-bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);
//
//        // Bottom left front to up left
//
//        this->vertices.push_back(bx->centre.x-bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y-bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);
//
//        this->vertices.push_back(bx->centre.x-bx->dimensions.x/2);
//        this->vertices.push_back(bx->centre.y+bx->dimensions.y/2);
//        this->vertices.push_back(bx->centre.z-bx->dimensions.z/2);
//
//        this->vertices.push_back(1.0);
//        this->vertices.push_back(0.0);
//        this->vertices.push_back(0.0);


        // Upper left to right front
        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        // Uper right to bottom front
        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);
//
//        // Bottom right front to left
        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        // Bottom left front to up left

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);


    // Added
        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);


        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);


        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);


        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z-bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);


        // Back

        // Upper left to right front
        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        // Uper right to bottom front
        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2); // +y
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);
//
//        // Bottom right front to left
        this->vertices.push_back(bx.centre.x+bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        // Bottom left front to up left

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y-bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);

        this->vertices.push_back(bx.centre.x-bx.dimensions.x/2);
        this->vertices.push_back(bx.centre.y+bx.dimensions.y/2);
        this->vertices.push_back(bx.centre.z+bx.dimensions.z/2);

        this->vertices.push_back(1.0);
        this->vertices.push_back(0.0);
        this->vertices.push_back(0.0);



        this->indices = std::vector<GLuint>
                {
//                    0, 1, 3, // first triangle
//                    1, 2, 3  // second triangle
//                        0,1,2
                        0,1,2,3,4,5,6,7,
                        8,9,10,11,12,13,14,15,
                        16,17,18,19,20,21,22,23
                };



        this->vbo = std::make_unique<VBO>(vertices,vertices.size());
        this->ebo = std::make_unique<EBO>(indices,indices.size());



        vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
        vao->linkAttrib(vbo.get(), 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

        //vao.linkAttrib(vbo, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

        // Unbind all to prevent accidentally modifying them
        vao->unbind();
        vbo->unbind();
        ebo->unbind();

        this->position = bx.centre;
    }

    void draw(Shader * shader){
        shader->use();

        glm::mat4 m = glm::mat4(1.0f);
        //m = glm::translate(m, position); // translate it down so it's at the center of the scene

        m = glm::translate(m, glm::vec3(0.0,0.0,0.0));
        shader->setMat4("model", m);


        this->vao->bind();
        this->ebo->bind();

       glDrawElements(GL_LINES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
 //         glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(3), GL_UNSIGNED_INT, 0);
//       glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);

        this->vao->unbind();
        this->ebo->unbind();
    }

    void updatePosition(glm::vec3 pos){
//        this->position = pos;
    }

    void remove(){
        this->vao->remove();
        this->vbo->remove();
    }
    ~TestModel() {}


private:
    std::unique_ptr<VAO> vao;
    std::unique_ptr<VBO> vbo;
    std::unique_ptr<EBO> ebo;

//    std::unique_ptr<Texture> texture_1;
//    std::unique_ptr<Texture> texture_2;

    std::vector<float>  vertices;
    std::vector<GLuint> indices;

    glm::vec3 position;

};

#endif //DOOM_QUAKE_OCTREE_H