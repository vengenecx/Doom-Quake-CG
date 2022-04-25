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
#include "Model.h"
#include "Map/VAO.h"
#include "Map/EBO.h"
#include "Map/VBO.h"
#include "Model/Cube/CubeModel.h"
//#include "Map/Texture.h"
#include <Shaders/EShader.h>
#include <Camera/Camera.h>


#include<filesystem>
namespace fs = std::filesystem;



class Engine {
public:
    Engine();

    void loop(GLFWwindow *window);
    void mouseHandler(GLFWwindow* window, double xposIn, double yposIn);
    void scrollHandler(GLFWwindow* window, double xoffset, double yoffset);

    static void mouseHandler_static(GLFWwindow* window, double xposIn, double yposIn);
    static void scrollHandler_static(GLFWwindow* window, double xoffset, double yoffset);

private:
    void keyHandler(GLFWwindow *window);

    void initBuffer();
    void setupVBO();
//    void initShader();
    void setupVAO();
    void setupEBO();

    // Buffers
    //unsigned int VBO;
    //unsigned int VAO;
    //unsigned int EBO;

    std::unique_ptr<VAO> VAO1;
    std::unique_ptr<VBO> VBO1;
    std::unique_ptr<EBO> EBO1;

    std::unique_ptr<Texture> planksTex;
    std::unique_ptr<Texture> planksSpec;

    // Shader variables
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;

    std::unique_ptr<Shader> ourShader;
    std::unique_ptr<Model> model;

    std::unique_ptr<CubeModel> cube;

    // Const input
    float vertices[44];
    unsigned int indices[6];

    // settings
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    // camera
    //Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
    std::unique_ptr<Camera> camera;
    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
    bool firstMouse = true;

    // timing
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
};
#endif //DOOM_QUAKE_ENGINE_H
