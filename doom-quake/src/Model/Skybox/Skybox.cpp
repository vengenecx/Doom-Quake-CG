//
// Created by Lennert Steyaert on 25/04/2022.
//

#include "Model/Skybox/Skybox.h"

Skybox::Skybox(std::vector<std::string>& faces, std::string directory, bool rgba) {
    this->vao = std::make_unique<VAO>();
    this->vao->bind();

    this->vertices = std::vector<float> {
            // positions
            -20.0f,  20.0f, -20.0f,
            -20.0f, -20.0f, -20.0f,
            20.0f, -20.0f, -20.0f,
            20.0f, -20.0f, -20.0f,
            20.0f,  20.0f, -20.0f,
            -20.0f,  20.0f, -20.0f,

            -20.0f, -20.0f,  20.0f,
            -20.0f, -20.0f, -20.0f,
            -20.0f,  20.0f, -20.0f,
            -20.0f,  20.0f, -20.0f,
            -20.0f,  20.0f,  20.0f,
            -20.0f, -20.0f,  20.0f,

            20.0f, -20.0f, -20.0f,
            20.0f, -20.0f,  20.0f,
            20.0f,  20.0f,  20.0f,
            20.0f,  20.0f,  20.0f,
            20.0f,  20.0f, -20.0f,
            20.0f, -20.0f, -20.0f,

            -20.0f, -20.0f,  20.0f,
            -20.0f,  20.0f,  20.0f,
            20.0f,  20.0f,  20.0f,
            20.0f,  20.0f,  20.0f,
            20.0f, -20.0f,  20.0f,
            -20.0f, -20.0f,  20.0f,

            -20.0f,  20.0f, -20.0f,
            20.0f,  20.0f, -20.0f,
            20.0f,  20.0f,  20.0f,
            20.0f,  20.0f,  20.0f,
            -20.0f,  20.0f,  20.0f,
            -20.0f,  20.0f, -20.0f,

            -20.0f, -20.0f, -20.0f,
            -20.0f, -20.0f,  20.0f,
            20.0f, -20.0f, -20.0f,
            20.0f, -20.0f, -20.0f,
            -20.0f, -20.0f,  20.0f,
            20.0f, -20.0f,  20.0f
    };

    this->vbo = std::make_unique<VBO>(vertices,vertices.size());

    vao->linkAttrib(vbo.get(), 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);


    this->loadCubemap(faces, directory, rgba);
}

void Skybox::draw(Shader *shader) {
    glDepthFunc(GL_LEQUAL);
    shader->use();

    this->vao->bind();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    this->vao->unbind();
    glDepthFunc(GL_LESS);
}

unsigned int Skybox::loadCubemap(std::vector<std::string> faces, std::string directory, bool rgba)
{
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    stbi_set_flip_vertically_on_load(false);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load((directory + faces[i]).c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            if(rgba)
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            else
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}