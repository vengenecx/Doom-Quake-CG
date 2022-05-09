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

    shaders[0] = std::make_unique<Shader>((currentDir + shaderPaths[doubleTextureColorVertex]).c_str(),(currentDir + shaderPaths[doubleTextureColorFragment]).c_str());
    shaders[1] = std::make_unique<Shader>((currentDir + shaderPaths[modelLoadingVertex]).c_str(),(currentDir + shaderPaths[modelLoadingFragment]).c_str());
    shaders[2] = std::make_unique<Shader>((currentDir + shaderPaths[defaultVertex]).c_str(),(currentDir + shaderPaths[defaultFragment]).c_str());
    shaders[3] = std::make_unique<Shader>((currentDir + shaderPaths[crossVertex]).c_str(),(currentDir + shaderPaths[crossFragment]).c_str());
    shaders[4] = std::make_unique<Shader>((currentDir + shaderPaths[lineVertex]).c_str(),(currentDir + shaderPaths[lineFragment]).c_str());
    shaders[5] = std::make_unique<Shader>((currentDir + shaderPaths[lightVertex]).c_str(),(currentDir + shaderPaths[lightFragment]).c_str());
    //  Model shader (assimp)
    //meshModelShader = std::make_unique<Shader>(shaderPaths[defaultVertex],shaderPaths[defaultFragment]);

    //ourShader = std::make_unique<Shader>(shaderPaths[modelLoadingVertex],shaderPaths[modelLoadingFragment]);


    //model = std::make_unique<Model>("model-files/body/FinalBaseMesh.obj");
    //model = std::make_unique<Model>("model-files/Humvee_models/Humvee.obj");



    // camera = std::make_unique<Camera>(true,glm::vec3(2.0f, 0.0f, 6.0f));

//    camera = std::make_unique<Camera>(false,glm::vec3(60.0f, 60.0f, -60.0f));

//    camera = std::make_unique<Camera>(true,glm::vec3(0.0f, 0.0f, 0.0f));

    camera = std::make_unique<Camera>(fpsCamera,glm::vec3(0.0f, 0.2f, -2.0f));

//    // Cube test
    //doubleTextureColShader = std::make_unique<Shader>("shader-files/doubletexturecolor.vs", "shader-files/doubletexturecolor.fs");


    if(lennert){

        std::string img_1 = (currentDir + "/model-files/cube/container.jpg");
//    std::string img_1 = (currentDir + "/model-files/grass/grass.jpeg");

        //std::string img_1 = (currentDir + "/model-files/grass/stone.png");
        std::string img_2 = (currentDir + "/model-files/cube/awesomeface.png");

        std::string img_3 = (currentDir + "/model-files/pothole/pothole.png");

        this->containerTexture = std::make_unique<Texture>(img_1.c_str(),GL_TEXTURE_2D,0,GL_RGB,GL_UNSIGNED_BYTE);
        this->awesomeTexture = std::make_unique<Texture>(img_2.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE);
        this->potholeTexture = std::make_unique<Texture>(img_3.c_str(),GL_TEXTURE_2D,2,GL_RGBA,GL_UNSIGNED_BYTE);


        models = std::vector<std::unique_ptr<BaseModel>>();

//    models.push_back(std::make_unique<Model>("model-files/backpack/backpack.obj",glm::vec3(0.0f, 2.0f, -8.0f),MODEL_LOADER_SHADER));
//    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 0.0f,  0.0f, 0.0f),DOUBLE_TEXTURE_COLOR_SHADER));
//    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( 0.0f,  0.0f, -5.0f),DOUBLE_TEXTURE_COLOR_SHADER));
//        models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( -10.0f,  -10.0f, -10.0f),DOUBLE_TEXTURE_COLOR_SHADER));

        models.push_back(std::make_unique<CubeModel>(glm::vec3( 2.0f,  2.0f, 2.0f),containerTexture.get(),awesomeTexture.get(), glm::vec3( -10.0f,  -10.0f, -10.0f),DOUBLE_TEXTURE_COLOR_SHADER));

        //        models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( -12.0f,  -12.0f, -12.0f),DOUBLE_TEXTURE_COLOR_SHADER));
        models.push_back(std::make_unique<CubeModel>(glm::vec3( 1.0f,  1.0f, 1.0f),containerTexture.get(),awesomeTexture.get(), glm::vec3( -12.0f,  -12.0f, -12.0f),DOUBLE_TEXTURE_COLOR_SHADER));

        models.push_back(std::make_unique<PlaneModel>(containerTexture.get(), glm::vec3( -10.0f,  -10.0f, 0.0f),DEFAULT));

        //models.push_back(std::make_unique<CrossModel>(CROSS));

//    std::unique_ptr<BoundingBox> boxm1 = std::make_unique<BoundingBox>();
//    boxm1->centre = glm::vec3(0.0,0.0,0.0);
//    boxm1->dimensions = glm::vec3(10.0,10.0,10.0);
//
//    models.push_back(std::make_unique<TestModel>(LINE,std::move(boxm1)));



//    BoundingBox boxm1 = BoundingBox();
//    boxm1.centre = glm::vec3(0.0,0.0,-10.0);
//    boxm1.dimensions = glm::vec3(10.0,10.0,10.0);
//
//    models.push_back(std::make_unique<TestModel>(LINE,boxm1));

        BoundingBox box = BoundingBox();
        box.centre = glm::vec3(0.0,0.0,0.0);
        box.dimensions = glm::vec3(50.0,50.0,50.0);


        octree = std::make_unique<Octree>(box, 10);

//    BoundingBox boxm1 = BoundingBox();
//    boxm1.centre = glm::vec3(0.0,0.0,0.0);
//    boxm1.dimensions = glm::vec3(4.0,4.0,4.0);
////     boxm1.centre = glm::vec3(10.0,10.0,10.0);
////     boxm1.dimensions = glm::vec3(20.0,20.0,20.0);
//    BaseModel * m1 = new TestModel(DEFAULT,boxm1);
////
//    octree->addModel(m1);


//     BoundingBox boxm2 = BoundingBox();
//     boxm2.centre = glm::vec3(5.0,5.0,5.0);
//     boxm2.dimensions = glm::vec3(4.0,4.0,4.0);
//     BaseModel * m2 = new TestModel(DEFAULT,boxm2);
//
//     octree->addModel(m2);
//
//    BoundingBox boxm3 = BoundingBox();
//    boxm3.centre = glm::vec3(15.0,15.0,15.0);
//    boxm3.dimensions = glm::vec3(4.0,4.0,4.0);
//    BaseModel * m3 = new TestModel(DEFAULT,boxm3);
//
//    octree->addModel(m3);
//
//
//    BoundingBox boxm4 = BoundingBox();
//    boxm4.centre = glm::vec3(20.0,20.0,20.0);
//    boxm4.dimensions = glm::vec3(4.0,4.0,4.0);
//    BaseModel * m4 = new TestModel(DEFAULT,boxm4);
//
//    octree->addModel(m4);


        //model = std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3( -10.0f,  -10.0f, -10.0f),DOUBLE_TEXTURE_COLOR_SHADER);

        octree->addModel(models[0].get());
        octree->addModel(models[1].get());
        octree->addModel(models[2].get());
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

    if(lennert){
        for(std::unique_ptr<BaseModel>& c : this->models){
            shaders[c->getShaderType()]->use();
            c->draw(shaders[c->getShaderType()].get());
        }

//        if(showOctree){
//            shaders[LINE]->use();
//            octree->draw(shaders[LINE].get());
//        }

        shaders[DEFAULT]->use();
        for(auto& hp: hitPoints){
            hp->draw(shaders[DEFAULT].get(), potholeTexture.get());
        }

//    tessHeightMapShader->use();
//    camera->updateCamera(tessHeightMapShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
//
//    terrain->draw(tessHeightMapShader.get());



//    textShader->use();
//    std::string fps = std::to_string(frameSetPoint) + std::string(" FPS");
//    textRenderer->RenderText(textShader.get(),fps, ((float )SCR_WIDTH)-100, 25.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
//
//
//    skyboxShader->use();
//    camera->updateCamera(skyboxShader.get(),(float )SCR_WIDTH,(float ) SCR_HEIGHT);
//    skybox->draw(skyboxShader.get());

    } else{
        currentScene->draw(shaders,hitPoints,culling.get(),showOctree);
    }

    shaders[crosshair->getShaderType()]->use();
    if(executeShoot)
        crosshair->shoot();
    if(realeaseShoot)
        crosshair->resetShoot();
    crosshair->draw(shaders[crosshair->getShaderType()].get());

    //shaders[LINE]->use();
    //culling->draw(shaders[LINE].get());

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
    ImGui::Checkbox("Octree", &showOctree);
    ImGui::SameLine();
    ImGui::SliderFloat("Speed", &speed, 0.0f, 6.0f);

    ImGui::Checkbox("FPS-camera", &fpsCamera);

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
//        std::cout << "W pressed" << std::endl;
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
//        std::cout<< "M pressed" << std::endl;
        if(!mouse_visible){
//            std::cout<< "normal mouse" << std::endl;
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        } else{
//            std::cout<< "disabled mouse" << std::endl;
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
//    std::cout << "mouse movement" << std::endl;
}

void Engine::remove() {
    currentScene->remove();
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void Engine::scrollHandler(GLFWwindow* window, double xoffset, double yoffset)
{
//    std::cout << "mouse scroll" <<  std::endl;
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