//
// Created by Lennert Steyaert on 19/03/2022.
//
// Reference: https://learnopengl.com/Getting-started/Shaders

#ifndef DOOM_QUAKE_SHADER_H
#define DOOM_QUAKE_SHADER_H

#include <glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

private:
    // utility function for checking shader compilation/linking errors
    void checkCompileErrors(unsigned int shader, std::string type);
};


#endif //DOOM_QUAKE_SHADER_H
