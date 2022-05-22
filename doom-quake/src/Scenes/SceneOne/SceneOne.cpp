#include "Scenes/SceneOne/SceneOne.h"



SceneOne::SceneOne(){
    // Textures
    //  Texture paths
    std::string stoneImg = (currentDir + "/model-files/textures/stone.png");
    std::string grassImg = (currentDir + "/model-files/textures/textures_lennert.png");
    std::string awsomeFaceImg = (currentDir + "/model-files/cube/awesomeface.png");
    std::string containerImg = (currentDir + "/model-files/cube/container.jpg");
    std::string metalImg = (currentDir + "/model-files/textures/metal.png");
    std::string concreteImg = (currentDir + "/model-files/textures/concrete_image.png");
    std::string bulletHoleImage = (currentDir + "/model-files/textures/bulletHole.png");
    std::string woodFloorImage = (currentDir + "/model-files/textures/wood_2.png");
    std::string doorWallImage = (currentDir + "/model-files/textures/doorWall.png");
    std::string potholeImage = (currentDir + "/model-files/pothole/pothole.png");
    std::string dungeonImage = (currentDir + "/model-files/textures/dungeon_2.png");
    std::string wall = (currentDir + "/model-files/textures/brickwall.jpg");
    std::string wallNormal = (currentDir + "/model-files/textures/brickwall_normal.jpg");
    std::string woodFloorImageNormal = (currentDir + "/model-files/textures/wood_2_normal_stronger.png");
    std::string dungeonNormalImage = (currentDir + "/model-files/textures/dungeon_2_normal.png");
    std::string doorWallNormalImage = (currentDir + "/model-files/textures/doorWallNormal.png");
    std::string spaceMetalImage = (currentDir + "/model-files/textures/space_metal.png");
    std::string spaceMetalNormalImage = (currentDir + "/model-files/textures/space_metal_normal.png");
    std::string metalTwoImage = (currentDir + "/model-files/textures/metal_2.png");
    std::string metalTwoNormalImage = (currentDir + "/model-files/textures/metal_2_normal.png");
    std::string metalThreeImage = (currentDir + "/model-files/textures/metal_3.png");
    std::string metalThreeNormalImage = (currentDir + "/model-files/textures/metal_3_normal.png");




    // Pothole texture
    this->potholeTexture = std::make_unique<Texture>(potholeImage.c_str(),GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE);

    // Texture list (positions are stored in ETexture)
    this->textures = std::vector<std::unique_ptr<Texture>>();

    // The slots are just in case when using multiple textures in one shader
    this->textures.push_back(std::make_unique<Texture>(awsomeFaceImg.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(stoneImg.c_str(),GL_TEXTURE_2D,2,GL_RGBA,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(grassImg.c_str(),GL_TEXTURE_2D,3,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(metalImg.c_str(),GL_TEXTURE_2D,4,GL_RGB,GL_SRGB)); // important change!
    this->textures.push_back(std::make_unique<Texture>(concreteImg.c_str(),GL_TEXTURE_2D,5,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(woodFloorImage.c_str(),GL_TEXTURE_2D,6,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(doorWallImage.c_str(), GL_TEXTURE_2D,7,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(containerImg.c_str(), GL_TEXTURE_2D,8,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(wall.c_str(), GL_TEXTURE_2D,9,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(wallNormal.c_str(), GL_TEXTURE_2D,10,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(woodFloorImageNormal.c_str(),GL_TEXTURE_2D,11,GL_RGBA,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(dungeonImage.c_str(), GL_TEXTURE_2D,12,GL_RGB,GL_UNSIGNED_BYTE)); // new
    this->textures.push_back(std::make_unique<Texture>(dungeonNormalImage.c_str(), GL_TEXTURE_2D,13,GL_RGBA,GL_UNSIGNED_BYTE)); // new
    this->textures.push_back(std::make_unique<Texture>(doorWallNormalImage.c_str(), GL_TEXTURE_2D,14,GL_RGBA,GL_UNSIGNED_BYTE)); // new
    this->textures.push_back(std::make_unique<Texture>(spaceMetalImage.c_str(), GL_TEXTURE_2D,15,GL_RGB,GL_UNSIGNED_BYTE)); // new
    this->textures.push_back(std::make_unique<Texture>(spaceMetalNormalImage.c_str(), GL_TEXTURE_2D,16,GL_RGBA,GL_UNSIGNED_BYTE)); // new
    this->textures.push_back(std::make_unique<Texture>(metalTwoImage.c_str(), GL_TEXTURE_2D,17,GL_RGB,GL_UNSIGNED_BYTE,1)); // new
    this->textures.push_back(std::make_unique<Texture>(metalTwoNormalImage.c_str(), GL_TEXTURE_2D,18,GL_RGBA,GL_UNSIGNED_BYTE)); // new
    this->textures.push_back(std::make_unique<Texture>(metalThreeImage.c_str(), GL_TEXTURE_2D,19,GL_RGB,GL_UNSIGNED_BYTE, 1)); // new
    this->textures.push_back(std::make_unique<Texture>(metalThreeNormalImage.c_str(), GL_TEXTURE_2D,20,GL_RGBA,GL_UNSIGNED_BYTE)); // new

    // Instance of spotlight
    spotLight = std::make_unique<SpotLight>(LINE);

    // Model list initiated
    models = std::vector<std::unique_ptr<BaseModel>>();


    // Light lists based on each room

    std::vector<BaseModel*> lightMonsterRoom = std::vector<BaseModel*>();
    lightMonsterRoom.push_back(spotLight.get());
    //models.push_back(std::make_unique<DirectionLight>(glm::vec3(0.1f,  0.1f, 0.1f), glm::vec3(2.0f,  0.8f,  3.0f), LINE));
    //lightMonsterRoom.push_back(models[models.size()-1].get());
    models.push_back(std::make_unique<PointLight>(glm::vec3(0.1f,  0.1f, 0.1f), glm::vec3(2.0f,  0.8f,  3.0f), LINE));
    lightMonsterRoom.push_back(models[models.size()-1].get());


    std::vector<BaseModel*> lightSwordRoom = std::vector<BaseModel*>();
    lightSwordRoom.push_back(spotLight.get());
    models.push_back(std::make_unique<DirectionLight>(glm::vec3(0.1f,  0.1f, 0.1f), glm::vec3(-7.0f,  0.8f,  1.0f), LINE));
    lightSwordRoom.push_back(models[models.size()-1].get());

    std::vector<BaseModel*> lightSpiderRoom = std::vector<BaseModel*>();
    lightSpiderRoom.push_back(spotLight.get());
    models.push_back(std::make_unique<PointLight>(glm::vec3( 0.1f,  0.1f, 0.1f), glm::vec3(8.0f, 1.6f, 3.0f), LINE));
    lightSpiderRoom.push_back(models[models.size()-1].get());
//    models.push_back(std::make_unique<PointLight>(glm::vec3( 0.1f,  0.1f, 0.1f), glm::vec3(11.0f, 1.6f, -1.0f), LINE));
//    lightSpiderRoom.push_back(models[models.size()-1].get());

    std::vector<BaseModel*> lightSpaceShip = std::vector<BaseModel*>();
    lightSpaceShip.push_back(spotLight.get());
    models.push_back(std::make_unique<PointLight>(glm::vec3( 0.1f,  0.1f, 0.1f), glm::vec3(2.5f, 1.6f, -4.0f), LINE));
    lightSpaceShip.push_back(models[models.size()-1].get());

    std::vector<BaseModel*> lightSniperRoom = std::vector<BaseModel*>();
    lightSniperRoom.push_back(spotLight.get());
    models.push_back(std::make_unique<PointLight>(glm::vec3( 0.1f,  0.1f, 0.1f), glm::vec3(15.0f, 0.1f, 6.0f), LINE));
    lightSniperRoom.push_back(models[models.size()-1].get());



    // adding object (LeanrOpengl load model tutorial) to the scene ======================================================================================================================================
//    models.push_back(std::make_unique<Model>("model-files/plant/Monster.obj",glm::vec3(2.5f, -0.9f, 6.0f), glm::vec3(0.005f, 0.005f, 0.005f), glm::vec3(1.0f,2.8f,1.0f), LIGHT, lightMonsterRoom,false));
//    models.push_back(std::make_unique<Model>("model-files/spaceship/spaceship.obj",glm::vec3(2.5f, 0.0f, -4.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(1.4f,1.0f,1.2f), LIGHT, lightSpaceShip,false));
//    models.push_back(std::make_unique<Model>("model-files/doomSword/Doom Eternal Weapon.obj", glm::vec3(-6.0f, 0.2f, 8.9f), glm::vec3(4.0f, 4.0f, 4.0f), glm::vec3(0.1f,2.0f, 0.05f), LIGHT,  lightSwordRoom, false));
//    models.push_back(std::make_unique<Model>("model-files/spider/Only_Spider_with_Animations_Export.obj", glm::vec3(9.5f, -1.0f, 2.0f), glm::vec3(0.01f, 0.01f, 0.01f), glm::vec3(1.0f,1.0f, 2.0f), LIGHT, lightSpiderRoom, true));
//    models.push_back(std::make_unique<Model>("model-files/sniper/sniper.obj", glm::vec3(13.0f, 0.0f, 6.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(1.0f,1.0f, 1.0f), LIGHT,  lightSniperRoom));


    // Scene setup

    // the first pair of coordinates represent the current drawn plane, the secondpair of coordinates represent the shifted position of the plane!
    // adding all the plane models for the FLOOR ======================================================================================================================================
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,10), false, true, textures[ETexture::WOODFLOOR].get(),textures[ETexture::WOODFLOOR_NORMAL].get(), glm::vec3(2.5f, -1.0f, 5.0f), LIGHT, lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(-1.5f,-1.0f,1.0f), LIGHT, lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,9), false, true, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(-5.5f, -1.0f, 4.5f), LIGHT, lightSwordRoom,false));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(-1.5f, -1.0f, 8.0f), LIGHT, lightSwordRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,0,1), false, true, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(6.0f, -1.0f, 3.5f), LIGHT, lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,6), false, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(9.5f, -1.0f, 1.0f), LIGHT, lightSpiderRoom,true));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,1), false, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(7.5f, -1.0f, 4.5f),  LIGHT, lightSpiderRoom,true));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(9,0,2), false, true, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(11.5f, -1.0f, 6.0f), LIGHT, lightSniperRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,6), false, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(2.5f, -1.0f, -3.0f), LIGHT, lightSpaceShip,false));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(3.5f, -1.0f, -4.0f), LIGHT, lightSpaceShip,false));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(1.5f, -1.0f, -4.0f), LIGHT, lightSpaceShip,false));

    // adding all the plane models for the WALLS ======================================================================================================================================
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,3), true, false, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(5.0f, 0.5f, 1.5f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,6), true, false, textures[ETexture::DUNGEON].get(),textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(5.0f, 0.5f, 7.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,3,0), true, true, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(4.0f, 0.5f, 0.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(10,3,0), true, true, textures[ETexture::METALTHREE].get(),textures[ETexture::METALTHREENORMAL].get(), glm::vec3(-3.0f, 0.5f, 0.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,9), true, true, textures[ETexture::METALTHREE].get(),textures[ETexture::METALTHREENORMAL].get(), glm::vec3(-8.0f, 0.5f, 4.5f), LIGHT,lightSwordRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(8,3,0), true, false, textures[ETexture::METALTHREE].get(),textures[ETexture::METALTHREENORMAL].get(), glm::vec3(-4.0f, 0.5f, 9.0f), LIGHT,lightSwordRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,1), true, true, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(0.0f, 0.5f, 9.5f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,3,0), true, false, textures[ETexture::DUNGEON].get(), textures[ETexture::DUNGEONNORMAL].get() , glm::vec3(2.5f, 0.5f, 10.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,5), true, true, textures[ETexture::WOODFLOOR].get(),textures[ETexture::WOODFLOOR_NORMAL].get(), glm::vec3(0.0f, 0.5f, 4.5f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,3,0), true, false, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(-1.5f, 0.5f, 2.0f), LIGHT,lightSwordRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,5), true, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(-3.0f, 0.5f, 4.5f), LIGHT,lightSwordRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,3,0), true, false, textures[ETexture::SPACEMETAL].get(), textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(-1.5f, 0.5f, 7.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,3,0), true, false, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(6.0f, 0.5f, 4.0f), LIGHT,lightSpiderRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,3), true, true, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(7.0f, 0.5f, 5.5f), LIGHT,lightSniperRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(9,3,0), true, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(11.5f, 0.5f, 7.0f), LIGHT,lightSniperRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(16.0f, 0.5f, 6.0f), LIGHT,lightSniperRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(8,3,0), true, true, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(12.0f, 0.5f, 5.0f), LIGHT,lightSniperRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,1), true, false, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(8.0f, 0.5f, 4.5f), LIGHT,lightSpiderRoom));
    
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(4,3,0), true, false, textures[ETexture::DUNGEON].get(), textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(10.0f, 0.5f, 4.0f), LIGHT, lightSpiderRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,6), true, false, textures[ETexture::DUNGEON].get(), textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(12.0f, 0.5f, 1.0f), LIGHT, lightSpiderRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,3,0), true, true, textures[ETexture::DUNGEON].get(), textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(9.5f, 0.5f, -2.0f), LIGHT, lightSpiderRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,5), true, true, textures[ETexture::DUNGEON].get(), textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(7.0f, 0.5f, 0.5f), LIGHT, lightSpiderRoom));

    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,3,0), true, true, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(6.0f, 0.5f, 3.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, false, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(3.0f, 0.5f, -1.0f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,3,1), true, false, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(3.5f, 0.5f, -2.5f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, false, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(4.0f, 0.5f, -4.0f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(-1,3,1), true, false, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(3.5f, 0.5f, -5.5f), LIGHT,lightSpaceShip));
       
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,3,0), true, true, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(2.5f, 0.5f, -6.0f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,3,1), true, true, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(1.5f, 0.5f, -5.5f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, true, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(1.0f, 0.5f, -4.0f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(-1,3,1), true,true, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(1.5f, 0.5f, -2.5f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(0,3,2), true, true, textures[ETexture::SPACEMETAL].get(),textures[ETexture::SPACEMETALNORMAL].get(), glm::vec3(2.0f, 0.5f, -1.0f), LIGHT,lightSpaceShip));
    
    // Adding all plane models for the ROOF ======================================================================================================================================
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,10), false, false, textures[ETexture::DUNGEON].get(),textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(2.5f, 2.0f, 5.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(-1.5f, 2.0f, 1.0f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,9), false, false, textures[ETexture::METALTHREE].get(),textures[ETexture::METALTHREENORMAL].get(), glm::vec3(-5.5f, 2.0f, 4.5f), LIGHT,lightSwordRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(3,0,2), false, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(-1.5f, 2.0f, 8.0f), LIGHT,lightSwordRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(2,0,1), false, false, textures[ETexture::DUNGEON].get(),textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(6.0f, 2.0f, 3.5f), LIGHT,lightMonsterRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(5,0,6), false, false, textures[ETexture::DUNGEON].get(),textures[ETexture::DUNGEONNORMAL].get(), glm::vec3(9.5f, 2.0f, 1.0f), LIGHT,lightSpiderRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,1), false, false, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(7.5f, 2.0f, 4.5f), LIGHT,lightSpiderRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(9,0,2), false, false, textures[ETexture::WALL].get(),textures[ETexture::WALL_NORMAL].get(), glm::vec3(11.5f, 2.0f, 6.0f), LIGHT,lightSniperRoom));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,6), false, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(2.5f, 2.0f, -3.0f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(3.5f, 2.0f, -4.0f), LIGHT,lightSpaceShip));
    models.push_back(std::make_unique<PlaneModel>(glm::vec3(1,0,4), false, false, textures[ETexture::METALTWO].get(),textures[ETexture::METALTWONORMAL].get(), glm::vec3(1.5f, 2.0f, -4.0f), LIGHT,lightSpaceShip));



    // Octree bounding-box definition
    BoundingBox box = BoundingBox();
    box.centre = glm::vec3(0.0,0.0,0.0);
    box.dimensions = glm::vec3(50.0,50.0,50.0);

    // Octree instance with fixed depth 10
    octree = std::make_unique<Octree>(box, 10);

    // Append all models into the octree
    for(auto& m : models){
        octree->addModel(m.get());
    }
}

SceneOne::~SceneOne(){
    for(std::unique_ptr<BaseModel>& c : this->models){
        c.release();
    }
    octree.release();
}

void SceneOne::draw(std::vector<std::unique_ptr<Shader>> & shaders,std::vector<std::unique_ptr<Hit>>& hitPoints, Culling* culling, bool octreeVisible){

    // Draw the octree (only culling region)
    octree->draw(shaders,culling,octreeVisible);

    // Hitpoints aren't stored in the octree
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

void SceneOne::spotLightToggle(bool state) {
    spotLight->toggleSpotLight(state);
}







