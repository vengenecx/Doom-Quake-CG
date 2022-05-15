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
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderType.h"

class Shader {
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath, ShaderType type);

    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath,
           const char* tessControlPath, const char* tessEvalPath, ShaderType type);
    // use/activate the shader
    void use();

    // Deletes the Shader Program
    void remove();

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w);
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    ShaderType getShaderType();
private:
    // utility function for checking shader compilation/linking errors
    void checkCompileErrors(unsigned int shader, std::string type);

    ShaderType type;
};


#endif //DOOM_QUAKE_SHADER_H
