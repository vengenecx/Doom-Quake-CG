//
// Created by Lennert Steyaert on 26/04/2022.
//


#include "Map/Terrain/Terrain.h"
#include <stb_image.h>

Terrain::Terrain(Shader  * shader){


    loadTexture(shader);

    std::vector<float> vertices;


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

    std::cout << "Loaded " << rez*rez << " patches of 4 control points each" << std::endl;
    std::cout << "Processing " << rez*rez*4 << " vertices in vertex shader" << std::endl;

    // first, configure the cube's VAO (and terrainVBO)

    glGenVertexArrays(1, &terrainVAO);
    glBindVertexArray(terrainVAO);

    glGenBuffers(1, &terrainVBO);
    glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texCoord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);

    glPatchParameteri(GL_PATCH_VERTICES, NUM_PATCH_PTS);

}


void Terrain::loadTexture(Shader* shader) {
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps

    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load("model-files/heightmaps/iceland_heightmap.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        shader->setInt("heightMap", 0);
        std::cout << "Loaded heightmap of size " << height << " x " << width << std::endl;
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void Terrain::draw(Shader * shader){
    // world transformation
    glm::mat4 model = glm::mat4(1.0f);
    shader->setMat4("model", model);

    // render the terrain
    glBindVertexArray(terrainVAO);
    glDrawArrays(GL_PATCHES, 0, NUM_PATCH_PTS*rez*rez);
}


void Terrain::updatePosition(glm::vec3 pos){

}

void Terrain::remove(){

}
