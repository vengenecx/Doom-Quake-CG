//
// Created by Lennert Steyaert on 14/03/2022.
//

#include <Engine.h>
// not nessecary anymore
// #include "Model/Plane/PlaneModel.h" 

// default constructor
Engine::Engine(){

    std::string currentDir = (fs::current_path()).string();

    std::cout << currentDir << std::endl;

    sceneone = std::make_unique<SceneOne>();

    shaders = std::vector<std::unique_ptr<Shader>>(3);

    shaders[0] = std::make_unique<Shader>((currentDir + shaderPaths[doubleTextureColorVertex]).c_str(),(currentDir + shaderPaths[doubleTextureColorFragment]).c_str());
    shaders[1] = std::make_unique<Shader>((currentDir + shaderPaths[modelLoadingVertex]).c_str(),(currentDir + shaderPaths[modelLoadingFragment]).c_str());
    shaders[2] = std::make_unique<Shader>((currentDir + shaderPaths[defaultVertex]).c_str(),(currentDir + shaderPaths[defaultFragment]).c_str());

    //  Model shader (assimp)
    //meshModelShader = std::make_unique<Shader>(shaderPaths[defaultVertex],shaderPaths[defaultFragment]);

    //ourShader = std::make_unique<Shader>(shaderPaths[modelLoadingVertex],shaderPaths[modelLoadingFragment]);


    //model = std::make_unique<Model>("model-files/body/FinalBaseMesh.obj");
    //model = std::make_unique<Model>("model-files/Humvee_models/Humvee.obj");


    camera = std::make_unique<Camera>(true,glm::vec3(2.0f, 0.0f, 6.0f));



    // skyboxShader = std::make_unique<Shader>((currentDir + shaderPaths[skyboxVertex]).c_str(), (currentDir  + shaderPaths[skyboxFragment]).c_str());

    // skybox = std::make_unique<Skybox>(skybox_b,currentDir,true);


//    tessHeightMapShader = std::make_unique<Shader>("shader-files/gpuheight.vs","shader-files/gpuheight.fs", nullptr,            // if wishing to render as is
//                                                   "shader-files/gpuheight.tcs", "shader-files/gpuheight.tes");


//     tessHeightMapShader = std::make_unique<Shader>((currentDir + shaderPaths[tesselationVertex]).c_str(),(currentDir + shaderPaths[tesselationFragment]).c_str(), nullptr, // if wishing to render as is
//                                                    (currentDir + shaderPaths[tesselationTCS]).c_str(), (currentDir + shaderPaths[tesselationTES]).c_str());


//     terrain = std::make_unique<Terrain>(containerTexture.get());


//    textShader = std::make_unique<Shader>("shader-files/text.vs","shader-files/text.fs");
    textShader = std::make_unique<Shader>((currentDir + shaderPaths[textVertex]).c_str(),(currentDir + shaderPaths[textFragment]).c_str());
    textRenderer = std::make_unique<TextRenderer>(SCR_WIDTH,SCR_HEIGHT);
}

Engine::~Engine(){
    // for(auto shader : shaders){
    //     delete shader;
    // }
}

void Engine::loop(GLFWwindow *window) {
    // per-frame time logic
    // --------------------
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    this->keyHandler(window);

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(auto &s : shaders){
        s->use();
        camera->updateCamera(s.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);

        //camera->updateCamera(s,(float )SCR_WIDTH,(float ) SCR_HEIGHT);
    }

    sceneone->drawing(shaders);


    // tessHeightMapShader->use();
    // camera->updateCamera(tessHeightMapShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);

    // terrain->draw(tessHeightMapShader.get());

    fpsTime += deltaTime;
    if(fpsTime >= 1){
        fpsTime = fpsTime - 1;
        frameSetPoint = frames;
        frames = 0;
    } else{
        frames ++;
    }

    textShader->use();
    std::string fps = std::to_string(frameSetPoint) + std::string(" FPS");
    textRenderer->RenderText(textShader.get(),fps, ((float )SCR_WIDTH)-100, 25.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));


    // skyboxShader->use();
    // camera->updateCamera(skyboxShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
    // skybox->draw(skyboxShader.get());
}

void Engine::keyHandler(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        std::cout << "W pressed" << std::endl;
        camera->ProcessKeyboard(FORWARD, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        std::cout << "S pressed" << std::endl;
        camera->ProcessKeyboard(BACKWARD, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        std::cout << "A pressed" << std::endl;
       camera->ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        std::cout << "D pressed" << std::endl;
        camera->ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        std::cout << "Q pressed" << std::endl;
        camera->ProcessKeyboard(LEFTSTRAFE, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        std::cout << "E pressed" << std::endl;
        camera->ProcessKeyboard(RIGHTSTRAFE, deltaTime);
    }
}
// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void Engine::mouseHandler(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera->ProcessMouseMovement(xoffset, yoffset);
    std::cout << "mouse movement" << std::endl;
}

void Engine::remove() {
    sceneone->remove();
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void Engine::scrollHandler(GLFWwindow* window, double xoffset, double yoffset)
{
    std::cout << "mouse scroll" <<  std::endl;
    camera->ProcessMouseScroll(static_cast<float>(yoffset));
}

void Engine::mouseHandler_static(GLFWwindow *window, double xposIn, double yposIn)
{
    Engine *engine = static_cast<Engine *>(glfwGetWindowUserPointer(window));
    engine->mouseHandler(window,xposIn,yposIn);
}

void Engine::scrollHandler_static(GLFWwindow* window, double xoffset, double yoffset)
{
    Engine *engine = static_cast<Engine *>(glfwGetWindowUserPointer(window));
    engine->scrollHandler(window,xoffset,yoffset);
}