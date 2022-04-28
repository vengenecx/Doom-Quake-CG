//
// Created by Lennert Steyaert on 26/04/2022.
//


#include "Map/Terrain/Terrain.h"

Terrain::Terrain(){

    texture = std::make_unique<Texture>("model-files/heightmaps/iceland_heightmap.png",GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE);

    width = texture->getWidth();
    height = texture->getHeight();

    vertices = std::vector<float>();

    for(unsigned i = 0; i <= rez-1; i++)
    {
        for(unsigned j = 0; j <= rez-1; j++)
        {
            vertices.push_back(-width/2.0f + width*i/(float)rez); // v.x
            vertices.push_back(0.0f); // v.y
            vertices.push_back(-height/2.0f + height*j/(float)rez); // v.z
            vertices.push_back(i / (float)rez); // u
            vertices.push_back(j / (float)rez); // v

            vertices.push_back(-width/2.0f + width*(i+1)/(float)rez); // v.x
            vertices.push_back(0.0f); // v.y
            vertices.push_back(-height/2.0f + height*j/(float)rez); // v.z
            vertices.push_back((i+1) / (float)rez); // u
            vertices.push_back(j / (float)rez); // v

            vertices.push_back(-width/2.0f + width*i/(float)rez); // v.x
            vertices.push_back(0.0f); // v.y
            vertices.push_back(-height/2.0f + height*(j+1)/(float)rez); // v.z
            vertices.push_back(i / (float)rez); // u
            vertices.push_back((j+1) / (float)rez); // v

            vertices.push_back(-width/2.0f + width*(i+1)/(float)rez); // v.x
            vertices.push_back(0.0f); // v.y
            vertices.push_back(-height/2.0f + height*(j+1)/(float)rez); // v.z
            vertices.push_back((i+1) / (float)rez); // u
            vertices.push_back((j+1) / (float)rez); // v
        }
    }

//    std::cout << "Loaded " << rez*rez << " patches of 4 control points each" << std::endl;
//    std::cout << "Processing " << rez*rez*4 << " vertices in vertex shader" << std::endl;
//
//
//

    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());

    // position attribute
    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    // texCoord attribute
    vao->linkAttrib(vbo.get(), 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    glPatchParameteri(GL_PATCH_VERTICES, NUM_PATCH_PTS);

}

Terrain::~Terrain() {
    std::cout << "delete terrain" << std::endl;
    vao.release();
    vbo.release();
}


void Terrain::setTextures(Shader* shader) {
    this->texture->texUnit(shader,"heightMap");
}


void Terrain::draw(Shader * shader){


    shader->use();

    // world transformation
    glm::mat4 model = glm::mat4(1.0f);
    shader->setMat4("model", model);


    setTextures(shader);
    this->texture->bind();
   // render the terrain

    this->vao->bind();
    glDrawArrays(GL_PATCHES, 0, NUM_PATCH_PTS*rez*rez);

    this->texture->unbind();
    this->vao->unbind();
}

void Terrain::remove(){
    this->vao->remove();
    this->vbo->remove();
}
