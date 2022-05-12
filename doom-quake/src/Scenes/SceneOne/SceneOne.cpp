#include "Scenes/SceneOne/SceneOne.h"

// default constructor
SceneOne::SceneOne(){
    // 8-bit/color RGB gives least issues!
    std::string stoneImg = (currentDir + "/model-files/grass/stone.png");
    std::string grassImg = (currentDir + "/model-files/grass/grass_lennert.png");
    std::string awsomeFaceImg = (currentDir + "/model-files/cube/awesomeface.png");
    std::string containerImg = (currentDir + "/model-files/cube/container.jpg");
    std::string metalImg = (currentDir + "/model-files/grass/metal.png");
    std::string concreteImg = (currentDir + "/model-files/grass/concrete_image.png");
    std::string bulletHoleImage = (currentDir + "/model-files/grass/bulletHole.png");
    std::string woodFloorImage = (currentDir + "/model-files/grass/woodFloorOne.png");
    std::string doorWallImage = (currentDir + "/model-files/grass/doorWall.png");
    std::string potholeImage = (currentDir + "/model-files/pothole/pothole.png");
    std::string dungeonImage = (currentDir + "/model-files/grass/dungeon_texture.png");

//    std::cout << "path: " << currentDir + "/model-files/grass/woodFloorOne.png" << std::endl;

    this->potholeTexture = std::make_unique<Texture>(potholeImage.c_str(),GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE);


    this->textures = std::vector<std::unique_ptr<Texture>>();

    this->textures.push_back(std::make_unique<Texture>(awsomeFaceImg.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(stoneImg.c_str(),GL_TEXTURE_2D,2,GL_RGBA,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(grassImg.c_str(),GL_TEXTURE_2D,3,GL_RGB,GL_UNSIGNED_BYTE));
    
    this->textures.push_back(std::make_unique<Texture>(metalImg.c_str(),GL_TEXTURE_2D,4,GL_RGB,GL_SRGB)); // important change!

    this->textures.push_back(std::make_unique<Texture>(concreteImg.c_str(),GL_TEXTURE_2D,5,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(woodFloorImage.c_str(),GL_TEXTURE_2D,6,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(doorWallImage.c_str(), GL_TEXTURE_2D,7,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(containerImg.c_str(), GL_TEXTURE_2D,8,GL_RGB,GL_UNSIGNED_BYTE));

    this->textures.push_back(std::make_unique<Texture>(dungeonImage.c_str(), GL_TEXTURE_2D,9,GL_RGB,GL_UNSIGNED_BYTE)); // new


    models = std::vector<std::unique_ptr<BaseModel>>();

    models.push_back(std::make_unique<Model>("model-files/hellknight/Hellknight_LATEST.obj", glm::vec3(2.0f, 0.0f, 5.0f), glm::vec3(0.7f, 0.7f, 0.7f), glm::vec3(1.0f,1.0f, 1.0f), MODEL_LOADER_SHADER));

    models.push_back(std::make_unique<Model>("model-files/spaceship/spaceship.obj",glm::vec3(2.5f, 0.0f, -4.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(2.0f,2.0f,2.0f), MODEL_LOADER_SHADER));

    models.push_back(std::make_unique<Model>("model-files/doomSword/Doom Eternal Weapon.obj", glm::vec3(-6.0f, 0.2f, 8.9f), glm::vec3(4.0f, 4.0f, 4.0f), glm::vec3(1.0f,1.0f, 1.0f), MODEL_LOADER_SHADER));
    
    models.push_back(std::make_unique<Model>("model-files/spider/Only_Spider_with_Animations_Export.obj", glm::vec3(9.5f, -1.0f, 2.0f), glm::vec3(0.01f, 0.01f, 0.01f), glm::vec3(1.0f,1.0f, 1.0f), MODEL_LOADER_SHADER));

    models.push_back(std::make_unique<Model>("model-files/sniper/sniper.obj", glm::vec3(13.0f, 0.0f, 6.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(1.0f,1.0f, 1.0f), MODEL_LOADER_SHADER));

    models.push_back(std::make_unique<CubeModel>(textures[ETexture::DUNGEON].get(),textures[ETexture::WOODFLOOR].get(), glm::vec3(0.5f,  -0.5f, 9.5f),DOUBLE_TEXTURE_COLOR_SHADER));
    models.push_back(std::make_unique<CubeModel>(textures[ETexture::WOODFLOOR].get(),textures[ETexture::WOODFLOOR].get(), glm::vec3(2.0f,  -0.5f, 3.0f),DOUBLE_TEXTURE_COLOR_SHADER));


    // the first pair of coordinates represent the current drawn plane, the secondpair of coordinates represent the shifted position of the plane!
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,10), false, textures[ETexture::STONE].get(), glm::vec3(2.5f, -1.0f, 5.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(-1.5,-1.0,1.0), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,9), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(-5.5f, -1.0f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(-1.5f, -1.0f, 8.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,0,1), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(6.0f, -1.0f, 3.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,6), false, textures[ETexture::DUNGEON].get(), glm::vec3(9.5f, -1.0f, 1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,1), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(7.5f, -1.0f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(9,0,2), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(11.5f, -1.0f, 6.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,6), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(2.5f, -1.0f, -3.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(3.5f, -1.0f, -4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(1.5f, -1.0f, -4.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,3), true, textures[ETexture::CONTAINER].get(), glm::vec3(5.0f, 0.5f, 1.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,6), true, textures[ETexture::CONTAINER].get(), glm::vec3(5.0f, 0.5f, 7.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(4.0f, 0.5f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(10,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(-3.0f, 0.5f, 0.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,9), true, textures[ETexture::CONCRETE].get(), glm::vec3(-8.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(8,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(-4.0f, 0.5f, 9.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,1), true, textures[ETexture::CONCRETE].get(), glm::vec3(0.0f, 0.5f, 9.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,3,0), true, textures[ETexture::DOORWALL].get(), glm::vec3(2.5f, 0.5f, 10.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,5), true, textures[ETexture::CONCRETE].get(), glm::vec3(0.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(-1.5f, 0.5f, 2.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,5), true, textures[ETexture::CONCRETE].get(), glm::vec3(-3.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,3,0), true, textures[ETexture::DOORWALL].get(), glm::vec3(-1.5f, 0.5f, 7.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(6.0f, 0.5f, 4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,3), true, textures[ETexture::CONCRETE].get(), glm::vec3(7.0f, 0.5f, 5.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(9,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(11.5f, 0.5f, 7.0f), DEFAULT));



    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, textures[ETexture::CONCRETE].get(), glm::vec3(16.0f, 0.5f, 6.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(8,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(12.0f, 0.5f, 5.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,1), true, textures[ETexture::CONCRETE].get(), glm::vec3(8.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(4,3,0), true, textures[ETexture::DUNGEON].get(), glm::vec3(10.0f, 0.5f, 4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,6), true, textures[ETexture::DUNGEON].get(), glm::vec3(12.0f, 0.5f, 1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,3,0), true, textures[ETexture::DUNGEON].get(), glm::vec3(9.5f, 0.5f, -2.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,5), true, textures[ETexture::DUNGEON].get(), glm::vec3(7.0f, 0.5f, 0.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(6.0f, 0.5f, 3.0f), DEFAULT));
    
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, textures[ETexture::CONCRETE].get(), glm::vec3(3.0f, 0.5f, -1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,3,1), true, textures[ETexture::CONCRETE].get(), glm::vec3(3.5f, 0.5f, -2.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, textures[ETexture::CONCRETE].get(), glm::vec3(4.0f, 0.5f, -4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(-1,3,1), true, textures[ETexture::CONCRETE].get(), glm::vec3(3.5f, 0.5f, -5.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,3,0), true, textures[ETexture::CONCRETE].get(), glm::vec3(2.5f, 0.5f, -6.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,3,1), true, textures[ETexture::CONCRETE].get(), glm::vec3(1.5f, 0.5f, -5.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, textures[ETexture::CONCRETE].get(), glm::vec3(1.0f, 0.5f, -4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(-1,3,1), true, textures[ETexture::CONCRETE].get(), glm::vec3(1.5f, 0.5f, -2.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, textures[ETexture::CONCRETE].get(), glm::vec3(2.0f, 0.5f, -1.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,10), false, textures[ETexture::CONCRETE].get(), glm::vec3(2.5f, 2.0f, 5.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, textures[ETexture::CONCRETE].get(), glm::vec3(-1.5f, 2.0f, 1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,9), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(-5.5f, 2.0f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, textures[ETexture::CONCRETE].get(), glm::vec3(-1.5f, 2.0f, 8.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,0,1), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(6.0f, 2.0f, 3.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,6), false, textures[ETexture::DUNGEON].get(), glm::vec3(9.5f, 2.0f, 1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,1), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(7.5f, 2.0f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(9,0,2), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(11.5f, 2.0f, 6.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,6), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(2.5f, 2.0f, -3.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(3.5f, 2.0f, -4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, textures[ETexture::WOODFLOOR].get(), glm::vec3(1.5f, 2.0f, -4.0f), DEFAULT));

    models.push_back(std::make_unique<LightBox>(textures[ETexture::WOODFLOOR].get(),textures[ETexture::WOODFLOOR].get(), glm::vec3(0.5f,  -0.5f, 5.5f),DOUBLE_TEXTURE_COLOR_SHADER));

    BoundingBox box = BoundingBox();
    box.centre = glm::vec3(0.0,0.0,0.0);
    box.dimensions = glm::vec3(50.0,50.0,50.0);

    octree = std::make_unique<Octree>(box, 10);

    // Append all models into the octree
    for(auto& m : models){
        octree->addModel(m.get());
    }
//    octree->addModel(models[0].get());
//    octree->addModel(models[1].get());
}

void SceneOne::draw(std::vector<std::unique_ptr<Shader>> & shaders,std::vector<std::unique_ptr<Hit>>& hitPoints, bool octreeVisible){
    for(std::unique_ptr<BaseModel>& c : this->models){
        shaders[c->getShaderType()]->use();
        c->draw(shaders[c->getShaderType()].get());
    }

    if(octreeVisible){
        shaders[LINE]->use();
        octree->draw(shaders[LINE].get());
    }

    shaders[DEFAULT]->use();
    for(auto& hp: hitPoints){
        hp->draw(shaders[DEFAULT].get(), potholeTexture.get());
    }
}

void SceneOne::remove(){
    for(std::unique_ptr<BaseModel>& c : this->models){
        c->remove();
    }
}


void SceneOne::shoot(Ray* ray, std::vector<std::unique_ptr<Hit>> & hitPoints){
    octree->shoot(*ray,hitPoints);
}
