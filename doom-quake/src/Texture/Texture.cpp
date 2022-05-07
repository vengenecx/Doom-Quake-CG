//
// Created by Lennert Steyaert on 24/04/2022.
//

#include "Texture/Texture.h"


Texture::Texture(){}

Texture::Texture(const char* image, GLenum texType, GLuint slot, GLenum format, GLenum pixelType)
{
    // Assigns the type of the texture ot the texture object
    target = texType;

    // Stores the width, height, and the number of color channels of the image
    int numColCh;
    // Flips the image so it appears right side up
    stbi_set_flip_vertically_on_load(true);
    // Reads the image from a file and stores it in bytes
    unsigned char* bytes = stbi_load(image, &width, &height, &numColCh, 0);

    std::cout << "Loaded heightmap of size " << height << " x " << width << std::endl;
    // Generates an OpenGL texture object
    glGenTextures(1, &ID);
    // Assigns the texture to a Texture Unit
    glActiveTexture(GL_TEXTURE0 + slot);
    unit = slot;
    glBindTexture(texType, ID);

    // Configures the type of algorithm that is used to make the image smaller or bigger
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Configures the way the texture repeats (if it does at all)
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Extra lines in case you choose to use GL_CLAMP_TO_BORDER
    // float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

    // Assigns the image to the OpenGL Texture object
    //glTexImage2D(texType, 0, INTERNAL_FORMAT, width, height, 0, format, pixelType, bytes);
    glTexImage2D(texType, 0, GL_RGBA, width, height, 0, format, pixelType, bytes);
    
    
    // Generates MipMaps
    glGenerateMipmap(texType);

    // Deletes the image data as it is already in the OpenGL Texture object
    stbi_image_free(bytes);

    // Unbinds the OpenGL Texture object so that it can't accidentally be modified
    glBindTexture(texType, 0);
}

void Texture::texUnit(Shader* shader, const char* uniform)
{
    shader->use();
    shader->setInt(uniform,unit);
//    shader->setInt(uniform,0);
}

void Texture::bind()
{
    glActiveTexture(GL_TEXTURE0 + unit);
//    glActiveTexture(GL_TEXTURE0);
    glBindTexture(target, ID);
}

void Texture::unbind()
{
    glBindTexture(target, 0);
}

void Texture::remove()
{
    glDeleteTextures(1, &ID);
}

int Texture::getHeight() {
    return height;
}

int Texture::getWidth() {
    return width;
}