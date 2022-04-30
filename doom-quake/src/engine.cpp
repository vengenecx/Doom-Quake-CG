//
// Created by Lennert Steyaert on 14/03/2022.
//

#include <Engine.h>
#include "Model/Plane/PlaneModel.h"


Engine::Engine()
{

    std::string currentDir = (fs::current_path()).string();
    std::cout << currentDir << std::endl;


    game = Game();


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

//    std::string img_1 = (currentDir + "/model-files/cube/container.jpg");
//    std::string img_1 = (currentDir + "/model-files/grass/grass.jpeg");

    std::string img_1 = (currentDir + "/model-files/grass/stone.png");
    std::string img_2 = (currentDir + "/model-files/cube/awesomeface.png");

    this->containerTexture = std::make_unique<Texture>(img_1.c_str(),GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE);
    this->awesomeTexture = std::make_unique<Texture>(img_2.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE);


    models = std::vector<std::unique_ptr<BaseModel>>();

    models.push_back(std::make_unique<Model>("model-files/backpack/backpack.obj",glm::vec3(0.0f, 2.0f, -8.0f),MODEL_LOADER_SHADER));
    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 0.0f,  0.0f, 0.0f),DOUBLE_TEXTURE_COLOR_SHADER));
    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 0.0f,  0.0f, -5.0f),DOUBLE_TEXTURE_COLOR_SHADER));
    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 5.0f,  5.0f, 0.0f),DOUBLE_TEXTURE_COLOR_SHADER));

    models.push_back(std::make_unique<PlaneModel>(containerTexture.get(), glm::vec3( 0.0f,  0.0f, 0.0f),DEFAULT));




//    skyboxShader = std::make_unique<Shader>((currentDir + "/shader-files/skybox.vs").c_str(), (currentDir  + "/shader-files/skybox.fs").c_str());

    skyboxShader = std::make_unique<Shader>((currentDir + shaderPaths[skyboxVertex]).c_str(), (currentDir  + shaderPaths[skyboxFragment]).c_str());

    skybox = std::make_unique<Skybox>(skybox_b,currentDir,true);


//    tessHeightMapShader = std::make_unique<Shader>("shader-files/gpuheight.vs","shader-files/gpuheight.fs", nullptr,            // if wishing to render as is
//                                                   "shader-files/gpuheight.tcs", "shader-files/gpuheight.tes");


    tessHeightMapShader = std::make_unique<Shader>((currentDir + shaderPaths[tesselationVertex]).c_str(),(currentDir + shaderPaths[tesselationFragment]).c_str(), nullptr,            // if wishing to render as is
                                                   (currentDir + shaderPaths[tesselationTCS]).c_str(), (currentDir + shaderPaths[tesselationTES]).c_str());


    terrain = std::make_unique<Terrain>(containerTexture.get());


//    textShader = std::make_unique<Shader>("shader-files/text.vs","shader-files/text.fs");
    textShader = std::make_unique<Shader>((currentDir + shaderPaths[textVertex]).c_str(),(currentDir + shaderPaths[textFragment]).c_str());
    textRenderer = std::make_unique<TextRenderer>(SCR_WIDTH,SCR_HEIGHT);

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

    for(auto &s  : shaders){
        s->use();
        camera->updateCamera(s.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
    }

    for(std::unique_ptr<BaseModel>& c : this->models){
        shaders[c->getShaderType()]->use();
        c->draw(shaders[c->getShaderType()].get());
    }

//    tessHeightMapShader->use();
//    camera->updateCamera(tessHeightMapShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
//
//    terrain->draw(tessHeightMapShader.get());

//    fpsTime += deltaTime;
//    if(fpsTime >= 1){
//        fpsTime = fpsTime - 1;
//        frameSetPoint = frames;
//        frames = 0;
//    } else{
//        frames ++;
//    }

//    textShader->use();
//    std::string fps = std::to_string(frameSetPoint) + std::string(" FPS");
//    textRenderer->RenderText(textShader.get(),fps, ((float )SCR_WIDTH)-100, 25.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
//
//
//    skyboxShader->use();
//    camera->updateCamera(skyboxShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
//    skybox->draw(skyboxShader.get());

    if(game.changed()){
        std::cout<< "state changed" << std::endl;
        if(game.getState() == ROOM_D){
            std::cout<< "room d" << std::endl;
        }

        game.reset();
    }

    drawControls(window);
}


void Engine::drawControls(GLFWwindow *window) {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Controls");

    ImGui::Text("Room selection:");


    ImGui::NewLine();
    ImGui::SameLine();
    if (ImGui::Button("Room A"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        game.setStateRoomA();
    ImGui::SameLine();
    if (ImGui::Button("Room B"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        game.setStateRoomB();
    ImGui::SameLine();
    if (ImGui::Button("Room C"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        game.setStateRoomC();
    ImGui::SameLine();
    if (ImGui::Button("Room D"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        game.setStateRoomD();
    ImGui::SameLine();
    if (ImGui::Button("Room E"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        game.setStateRoomE();

    ImGui::NewLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();


    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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