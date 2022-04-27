//
// Created by Lennert Steyaert on 14/03/2022.
//

#include <Engine.h>
#include "Model/Plane/PlaneModel.h"


Engine::Engine()
{

    std::string currentDir = (fs::current_path()).string();

    shaders = std::vector<std::unique_ptr<Shader>>(3);
//    shaders[0] = std::make_unique<Shader>("shader-files/doubletexturecolor.vs", "shader-files/doubletexturecolor.fs");
    shaders[0] = std::make_unique<Shader>((currentDir + shaderPaths[doubleTextureColorVertex]).c_str(),(currentDir + shaderPaths[doubleTextureColorFragment]).c_str());
    shaders[1] = std::make_unique<Shader>((currentDir + shaderPaths[modelLoadingVertex]).c_str(),(currentDir + shaderPaths[modelLoadingFragment]).c_str());
    shaders[2] = std::make_unique<Shader>((currentDir + shaderPaths[defaultVertex]).c_str(),(currentDir + shaderPaths[defaultFragment]).c_str());

    //  Model shader (assimp)
    //meshModelShader = std::make_unique<Shader>(shaderPaths[defaultVertex],shaderPaths[defaultFragment]);

    //ourShader = std::make_unique<Shader>(shaderPaths[modelLoadingVertex],shaderPaths[modelLoadingFragment]);


    //model = std::make_unique<Model>("model-files/body/FinalBaseMesh.obj");
    //model = std::make_unique<Model>("model-files/Humvee_models/Humvee.obj");


    camera = std::make_unique<Camera>(false,glm::vec3(0.0f, 10.0f, 3.0f));

//    // Cube test
    //doubleTextureColShader = std::make_unique<Shader>("shader-files/doubletexturecolor.vs", "shader-files/doubletexturecolor.fs");

    std::string img_1 = (currentDir + "/model-files/cube/container.jpg");
    std::string img_2 = (currentDir + "/model-files/cube/awesomeface.png");

    this->containerTexture = std::make_unique<Texture>(img_1.c_str(),GL_TEXTURE_2D,0,GL_RGB,GL_UNSIGNED_BYTE);
    this->awesomeTexture = std::make_unique<Texture>(img_2.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE);


    models = std::vector<std::unique_ptr<BaseModel>>();

    models.push_back(std::make_unique<Model>("model-files/backpack/backpack.obj",glm::vec3(0.0f, 2.0f, -8.0f),MODEL_LOADER_SHADER));
    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 0.0f,  0.0f, 0.0f),DOUBLE_TEXTURE_COLOR_SHADER));
    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 0.0f,  0.0f, -5.0f),DOUBLE_TEXTURE_COLOR_SHADER));
    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 5.0f,  5.0f, 0.0f),DOUBLE_TEXTURE_COLOR_SHADER));

    models.push_back(std::make_unique<PlaneModel>(containerTexture.get(), glm::vec3( 0.0f,  0.0f, 0.0f),DEFAULT));




    skyboxShader = std::make_unique<Shader>((currentDir + "/shader-files/skybox.vs").c_str(), (currentDir  + "/shader-files/skybox.fs").c_str());
    skybox = std::make_unique<Skybox>(skybox_b,currentDir,true);


    tessHeightMapShader = std::make_unique<Shader>("shader-files/gpuheight.vs","shader-files/gpuheight.fs", nullptr,            // if wishing to render as is
                                                   "shader-files/gpuheight.tcs", "shader-files/gpuheight.tes");

    terrain = std::make_unique<Terrain>(tessHeightMapShader.get());
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

//    for(auto &s  : shaders){
//        s->use();
//        camera->updateCamera(s.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
//    }
//
//    for(std::unique_ptr<BaseModel>& c : this->models){
//        shaders[c->getShaderType()]->use();
//        c->draw(shaders[c->getShaderType()].get());
//    }

    tessHeightMapShader->use();
    camera->updateCamera(tessHeightMapShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);

    terrain->draw(tessHeightMapShader.get());

//    skyboxShader->use();
//    camera->updateCamera(skyboxShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
//    skybox->draw(skyboxShader.get());
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
    for(std::unique_ptr<BaseModel>& c : this->models){
        c->remove();
    }
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