#include "Scenes/SceneTwo/SceneTwo.h"

// default constructor
SceneTwo::SceneTwo(){

    // 8-bit/color RGB gives least issues!
    std::string stoneImg = (currentDir + "/model-files/grass/stone.png");
    std::string grassImg = (currentDir + "/model-files/grass/grass_lennert.png");
    std::string awsomeFaceImg = (currentDir + "/model-files/cube/awesomeface.png");
    std::string containerImg = (currentDir + "/model-files/cube/container.jpg");
    std::string metalImg = (currentDir + "/model-files/grass/metal.png");
    std::string concreteImg = (currentDir + "/model-files/grass/concrete_image.png");
    std::string bulletHoleImage = (currentDir + "/model-files/grass/bulletHole.png");
    std::string woodFloorImage = (currentDir + "/model-files/grass/woodFloorOne.png");
    
    std::cout << "path: " << currentDir + "/model-files/grass/woodFloorOne.png" << std::endl;

    this->woodFLoorTexture = std::make_unique<Texture>(woodFloorImage.c_str(),GL_TEXTURE_2D,6,GL_RGB,GL_UNSIGNED_BYTE);
    this->concreteTexture = std::make_unique<Texture>(concreteImg.c_str(),GL_TEXTURE_2D,5,GL_RGB,GL_UNSIGNED_BYTE);
    this->metalTexture = std::make_unique<Texture>(metalImg.c_str(),GL_TEXTURE_2D,4,GL_RGB,GL_UNSIGNED_BYTE);
    this->containerTexture = std::make_unique<Texture>(containerImg.c_str(),GL_TEXTURE_2D,0,GL_RGB,GL_UNSIGNED_BYTE);
    this->awesomeTexture = std::make_unique<Texture>(awsomeFaceImg.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE);
    this->stoneTexture = std::make_unique<Texture>(stoneImg.c_str(),GL_TEXTURE_2D,2,GL_RGBA,GL_UNSIGNED_BYTE);
    this->grassTexture = std::make_unique<Texture>(grassImg.c_str(),GL_TEXTURE_2D,3,GL_RGB,GL_UNSIGNED_BYTE);

    models = std::vector<std::unique_ptr<BaseModel>>();
    
    models.push_back(std::make_unique<Model>("model-files/Humvee_models/Humvee.obj",glm::vec3(2.0f, 0.5f, 5.0f),glm::vec3(0.1f, 0.1f, 0.1f),MODEL_LOADER_SHADER));
    models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3(0.5f,  -0.5f, 9.5f),DOUBLE_TEXTURE_COLOR_SHADER));
    models.push_back(std::make_unique<CubeModel>(concreteTexture.get(),concreteTexture.get(), glm::vec3(2.0f,  -0.5f, 3.0f),DOUBLE_TEXTURE_COLOR_SHADER));
//     models.push_back(std::make_unique<Model>("model-files/backpack/backpack.obj",glm::vec3(4.0f, -0.5f, 10.0f),MODEL_LOADER_SHADER));


    // all vertices can be found back in the header file (SceneONe.h)
    models.push_back(std::make_unique<PlaneModel>(groundVerticesOne, containerTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesTwo, containerTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesOne, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwo, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesThree, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesFour, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesFive, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesSix, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(roofVerticesOne, metalTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(roofVerticesTwo, metalTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));


    std::cout << "SceneOne.cpp: models pushed back..." << std::endl;
}

void SceneTwo::draw(std::vector<std::unique_ptr<Shader>> & shaders,std::vector<std::unique_ptr<Hit>>& hitPoints,Culling* culling, bool octreeVisible){
    for(std::unique_ptr<BaseModel>& c : this->models){
        shaders[c->getShaderType()]->use();
        c->draw(shaders[c->getShaderType()].get());
    }


}

void SceneTwo::remove(){
    for(std::unique_ptr<BaseModel>& c : this->models){
        c->remove();
    }
}

void SceneTwo::shoot(Ray* ray, std::vector<std::unique_ptr<Hit>> & hitPoints){

}

void SceneTwo::spotLightToggle(bool state){
    
}





