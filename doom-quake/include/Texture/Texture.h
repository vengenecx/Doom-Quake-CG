//
// Created by Lennert Steyaert on 24/04/2022.
//

#ifndef DOOM_QUAKE_TEXTURE_H
#define DOOM_QUAKE_TEXTURE_H

#include <memory>
#include <vector>
#include <string>
#include <glad.h>
#include <stb_image.h>
#include "Shaders/Shader.h"

class Texture {
public:
    GLuint ID;
    std::string type; // string type
    std::string path; // path

    GLenum target;
    GLuint unit;


    Texture();
    Texture(const char* image, GLenum texType, GLuint slot, GLenum format, GLenum pixelType);

    // Assigns a texture unit to a texture
    void texUnit(Shader* shader, const char* uniform, GLuint unit);
    // Binds a texture
    void bind();
    // Unbinds a texture
    void unbind();
    // Deletes a texture
    void remove();
};

#endif //DOOM_QUAKE_TEXTURE_H
