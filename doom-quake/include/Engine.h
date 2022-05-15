//
// Created by Lennert Steyaert on 14/03/2022.
//

#ifndef DOOM_QUAKE_ENGINE_H
#define DOOM_QUAKE_ENGINE_H

#include <glad.h>
#include <GLFW/glfw3.h>
// #include <Shaders/basicShader.h>
#include <iostream>
#include <memory>
#include "Shaders/Shader.h"
#include "Model/LearnOpenglModel/Model.h"
#include "Model/Cube/CubeModel.h"
#include "Model/Triangle/TriangleModel.h"
#include "Model/Skybox/Skybox.h"
#include "Model/Cross/CrossModel.h"
#include "Model/Test/TestModel.h"

#include "Map/Terrain/Terrain.h"
#include "Text/TextRenderer.h"
// #include <Shaders/EShader.h>
#include <Camera/Camera.h>

#include "Scenes/SceneTwo/SceneTwo.h"
#include "Scenes/SceneOne/SceneOne.h"

#include "Octree/Octree.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Game/Game.h"
#include "Culling/Culling.h"

#include<filesystem>
namespace fs = std::filesystem;

// lighting

class Engine {
public:
    Engine();
    ~Engine();

    void loop(GLFWwindow *window, int width, int height);
    void mouseHandler(GLFWwindow* window, double xposIn, double yposIn);
    void scrollHandler(GLFWwindow* window, double xoffset, double yoffset);

    static void mouseHandler_static(GLFWwindow* window, double xposIn, double yposIn);
    static void scrollHandler_static(GLFWwindow* window, double xoffset, double yoffset);
    virtual void remove();


private:
    void keyHandler(GLFWwindow *window);
    void drawControls(GLFWwindow *window);

    Game game;
    std::unique_ptr<Camera> camera;
    std::unique_ptr<CrossModel> crosshair;
    std::vector<std::unique_ptr<Shader>> shaders;
    std::unique_ptr<Ray> ray;
    std::unique_ptr<Culling> culling;
    std::vector<std::unique_ptr<Hit>> hitPoints;
    std::unique_ptr<Scene> currentScene;

    ImVec4 clear_color;

    bool executeShoot= false;
    bool activeShoot = false;
    bool realeaseShoot = false;
    bool mouse_visible = false;
    bool m_pressed = false;
    bool showOctree= false;
    bool fpsCamera = true;
    bool spotLight = false;
    bool spaceActive = false;

    unsigned int SCR_WIDTH = 800;
    unsigned int SCR_HEIGHT = 800;

    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
    bool firstMouse = true;

    // timing
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    float fpsTime = 0.0f;
    int frames = 0;

    int frameSetPoint = 0;


    float speed =  2.5;
    float zoom =  45.0;



//    std::unique_ptr<Octree> octree;
//    std::unique_ptr<Shader> skyboxShader;
//    std::unique_ptr<Shader> tessHeightMapShader;
//    std::unique_ptr<Skybox> skybox;
//    std::unique_ptr<Shader> textShader;
//    std::unique_ptr<TextRenderer> textRenderer;
//    std::unique_ptr<Terrain> terrain;
//    bool lennert = false;

};
#endif //DOOM_QUAKE_ENGINE_H
