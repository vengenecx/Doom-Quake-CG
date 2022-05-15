//
// Created by Lennert Steyaert on 14/03/2022.
//

#include <Engine.h>
// not nessecary anymore
// #include "Model/Plane/PlaneModel.h" 



Engine::Engine()
{

    std::string currentDir = (fs::current_path()).string();
    std::cout << currentDir << std::endl;


    if(!lennert){
        currentScene = std::make_unique<SceneOne>();
    }

    game = Game();


    shaders = std::vector<std::unique_ptr<Shader>>(6);
//    shaders[0] = std::make_unique<Shader>("shader-files/doubletexturecolor.vs", "shader-files/doubletexturecolor.fs");

    shaders[0] = std::make_unique<Shader>((currentDir + shaderPaths[doubleTextureColorVertex]).c_str(),(currentDir + shaderPaths[doubleTextureColorFragment]).c_str(),DOUBLE_TEXTURE_COLOR_SHADER);
    shaders[1] = std::make_unique<Shader>((currentDir + shaderPaths[modelLoadingVertex]).c_str(),(currentDir + shaderPaths[modelLoadingFragment]).c_str(), MODEL_LOADER_SHADER);
    shaders[2] = std::make_unique<Shader>((currentDir + shaderPaths[defaultVertex]).c_str(),(currentDir + shaderPaths[defaultFragment]).c_str(), DEFAULT );
    shaders[3] = std::make_unique<Shader>((currentDir + shaderPaths[crossVertex]).c_str(),(currentDir + shaderPaths[crossFragment]).c_str(), CROSS);
    shaders[4] = std::make_unique<Shader>((currentDir + shaderPaths[lineVertex]).c_str(),(currentDir + shaderPaths[lineFragment]).c_str(), LINE);
    shaders[5] = std::make_unique<Shader>((currentDir + shaderPaths[lightVertex]).c_str(),(currentDir + shaderPaths[lightFragment]).c_str(),LIGHT);


    camera = std::make_unique<Camera>(fpsCamera,glm::vec3(0.0f, 0.2f, -2.0f));


//    Other additional tests
//    skyboxShader = std::make_unique<Shader>((currentDir + shaderPaths[skyboxVertex]).c_str(), (currentDir  + shaderPaths[skyboxFragment]).c_str());
//    skybox = std::make_unique<Skybox>(skybox_b,currentDir,true);
//    tessHeightMapShader = std::make_unique<Shader>("shader-files/gpuheight.vs","shader-files/gpuheight.fs", nullptr,            // if wishing to render as is
//                                                   "shader-files/gpuheight.tcs", "shader-files/gpuheight.tes");

//     tessHeightMapShader = std::make_unique<Shader>((currentDir + shaderPaths[tesselationVertex]).c_str(),(currentDir + shaderPaths[tesselationFragment]).c_str(), nullptr, // if wishing to render as is
//                                                    (currentDir + shaderPaths[tesselationTCS]).c_str(), (currentDir + shaderPaths[tesselationTES]).c_str());

//     terrain = std::make_unique<Terrain>(containerTexture.get());


    ray = std::make_unique<Ray>(glm::vec3(0.0,0.0,0.0),glm::vec3(1.0,1.0,1.0));

    culling = std::make_unique<Culling>(camera->Position,camera->Front);

    crosshair = std::make_unique<CrossModel>(CROSS);

    // Hitpoints
    hitPoints = std::vector<std::unique_ptr<Hit>>();

}


Engine::~Engine(){
    // for(auto shader : shaders){
    //     delete shader;
    // }
}


void Engine::loop(GLFWwindow *window, int width, int height) {

    // per-frame time logic
    // --------------------
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    this->keyHandler(window);

    if(activeShoot){
        fpsTime += deltaTime;
    }
    if(fpsTime >= 0.1){
        fpsTime = 0;
        frameSetPoint = frames;
        frames = 0;
        realeaseShoot = true;
        activeShoot = false;
    } else{
        frames ++;
    }

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    while(hitPoints.size() >= 30){
        hitPoints.erase(hitPoints.begin());
    }

    for(auto &s : shaders){
        s->use();
        camera->updateCamera(s.get(),(float )width,(float ) height);
    }

    currentScene->draw(shaders,hitPoints,culling.get(),showOctree);

    shaders[crosshair->getShaderType()]->use();
    if(executeShoot)
        crosshair->shoot();
    if(realeaseShoot)
        crosshair->resetShoot();
    crosshair->draw(shaders[crosshair->getShaderType()].get());

    shaders[LINE]->use();
    culling->draw(shaders[LINE].get());

    if(executeShoot){
//        std::cout<< "shoot" << std::endl;
        executeShoot = false;
        activeShoot = true;
    }
    if(realeaseShoot){
//        std::cout<< "release shoot" << std::endl;
        realeaseShoot = false;
    }

    if(game.changed()){
//        std::cout<< "state changed" << std::endl;
        if(game.getState() == ROOM_D){
//            std::cout<< "room d" << std::endl;
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

    ImGui::NewLine();
    ImGui::Checkbox("Octree", &showOctree);
    ImGui::SameLine();
    ImGui::SliderFloat("Speed", &speed, 0.0f, 6.0f);

    ImGui::Checkbox("FPS-camera", &fpsCamera);
    ImGui::SameLine();
    ImGui::Checkbox("Spotlight", &spotLight);

    currentScene->spotLightToggle(spotLight);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::NewLine();
    ImGui::Text("Pos: (%.3f,%.3f,%.3f)", camera->Position.x, camera->Position.y, camera->Position.z);

    ImGui::End();


    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


    camera->updateSpeed(speed);
}


void Engine::keyHandler(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera->ProcessKeyboard(FORWARD, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//        std::cout << "S pressed" << std::endl;
        camera->ProcessKeyboard(BACKWARD, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//        std::cout << "A pressed" << std::endl;
       camera->ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//        std::cout << "D pressed" << std::endl;
        camera->ProcessKeyboard(RIGHT, deltaTime);
    }

     if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
//         std::cout << "Q pressed" << std::endl;
         camera->ProcessKeyboard(LEFTSTRAFE, deltaTime);
     }
     if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
//         std::cout << "E pressed" << std::endl;
         camera->ProcessKeyboard(RIGHTSTRAFE, deltaTime);
     }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !spaceActive) {
//        std::cout << "Space pressed" << std::endl;
        executeShoot = true;

//        std::cout << camera->Front.x << " ," <<  camera->Front.y << " ,"   <<  camera->Front.z << std::endl;
//        std::cout << camera->Position.x << " ," <<  camera->Position.y << " ,"   <<  camera->Position.z << std::endl;
        ray->setRay(camera->Position,camera->Front);

        if(!lennert){
            currentScene->shoot(ray.get(),hitPoints);
        } else{
            octree->shoot(*ray.get(), hitPoints);
        }

        spaceActive = true;
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE && spaceActive) {
        spaceActive= false;
    }


    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && !m_pressed) {
        if(!mouse_visible){
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        } else{
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
        mouse_visible = !mouse_visible;
        m_pressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_RELEASE && m_pressed) {
        m_pressed = false;
    }

    culling->setCulling(camera->Position,camera->Front);
    camera->cameraGrounded(fpsCamera);
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
    culling->setCulling(camera->Position,camera->Front);
}

void Engine::remove() {
    currentScene->remove();
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void Engine::scrollHandler(GLFWwindow* window, double xoffset, double yoffset)
{
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