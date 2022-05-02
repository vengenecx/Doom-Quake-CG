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
#include "Model/LearnOpenglModel/Model.h"
#include "Model/Cube/CubeModel.h"
#include "Model/Triangle/TriangleModel.h"
#include "Model/Skybox/Skybox.h"
#include "Model/Cross/CrossModel.h"
#include "Map/Terrain/Terrain.h"
#include "Text/TextRenderer.h"
#include <Shaders/EShader.h>
#include <Camera/Camera.h>

//#include "imgui.h"
//#include "imgui_impl_glfw.h"
//#include "imgui_impl_opengl3.h"


#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Game/Game.h"

#include<filesystem>
namespace fs = std::filesystem;



class Engine {
public:
    Engine();

    void loop(GLFWwindow *window, int width, int height);
    void mouseHandler(GLFWwindow* window, double xposIn, double yposIn);
    void scrollHandler(GLFWwindow* window, double xoffset, double yoffset);

    static void mouseHandler_static(GLFWwindow* window, double xposIn, double yposIn);
    static void scrollHandler_static(GLFWwindow* window, double xoffset, double yoffset);

    void remove();

private:
    void keyHandler(GLFWwindow *window);


    void drawControls(GLFWwindow *window);


    Game game;

    std::unique_ptr<Texture> containerTexture;
    std::unique_ptr<Texture> awesomeTexture;


    std::unique_ptr<Shader> doubleTextureColShader;
    std::unique_ptr<Shader> meshModelShader;
    std::unique_ptr<BaseModel> model;

    std::unique_ptr<CubeModel> cube;
    std::unique_ptr<TriangleModel> triangle;

    std::unique_ptr<Terrain> terrain;


    std::vector<std::unique_ptr<BaseModel>> models;
    std::vector<std::unique_ptr<Shader>> shaders;

    std::unique_ptr<Shader> skyboxShader;

    std::unique_ptr<Shader> tessHeightMapShader;

    std::unique_ptr<Skybox> skybox;

    std::unique_ptr<Shader> textShader;

    std::unique_ptr<TextRenderer> textRenderer;

    // settings
    unsigned int SCR_WIDTH = 800;
    unsigned int SCR_HEIGHT = 600;




    // camera
    //Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
    std::unique_ptr<Camera> camera;
    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
    bool firstMouse = true;

    // timing
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    float fpsTime = 0.0f;
    int frames = 0;

    int frameSetPoint = 0;

    ImVec4 clear_color;

    bool executeShoot= false;
    bool activeShoot = false;
    bool realeaseShoot = false;
};
#endif //DOOM_QUAKE_ENGINE_H
