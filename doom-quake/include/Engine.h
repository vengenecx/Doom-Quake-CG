//
// Created by Lennert Steyaert on 14/03/2022.
//

#ifndef DOOM_QUAKE_ENGINE_H
#define DOOM_QUAKE_ENGINE_H

#include <glad.h>
#include <GLFW/glfw3.h>
#include <Shaders/basicShader.h>
#include <iostream>


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

    unsigned int VBO;
    unsigned int VAO;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    float vertices[9];
};
#endif //DOOM_QUAKE_ENGINE_H
