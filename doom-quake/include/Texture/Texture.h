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

// Based on: https://github.com/VictorGordan/opengl-tutorials

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
//    void texUnit(Shader* shader, const char* uniform, GLuint unit);
    void texUnit(Shader* shader, const char* uniform);


    // Binds a texture
    void bind();
    // Unbinds a texture
    void unbind();
    // Deletes a texture
    void remove();


    int getWidth();
    int getHeight();

private:
    int width;
    int height;
};

#endif //DOOM_QUAKE_TEXTURE_H
