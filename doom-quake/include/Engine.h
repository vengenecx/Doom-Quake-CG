//
// Created by Lennert Steyaert on 14/03/2022.
//

#ifndef DOOM_QUAKE_ENGINE_H
#define DOOM_QUAKE_ENGINE_H

#include <glad.h>
#include <GLFW/glfw3.h>
#include <Shaders/basicShader.h>
#include <iostream>
#include <memory>
#include "Shaders/Shader.h"
#include <Shaders/EShader.h>


class Engine {
public:
    Engine();

    void loop(GLFWwindow *window);

private:
    void keyHandler(GLFWwindow *window);
    void initBuffer();
    void setupVBO();
    void initShader();
    void setupVAO();
    void setupEBO();

    // Buffers
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    // Shader variables
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;

    std::unique_ptr<Shader> ourShader;

    // Const input
    float vertices[12];
    unsigned int indices[6];
};
#endif //DOOM_QUAKE_ENGINE_H
