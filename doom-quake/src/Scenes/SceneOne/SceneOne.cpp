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

    
//    std::cout << "path: " << currentDir + "/model-files/grass/woodFloorOne.png" << std::endl;

    this->potholeTexture = std::make_unique<Texture>(potholeImage.c_str(),GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE);


    this->textures = std::vector<std::unique_ptr<Texture>>();

    this->textures.push_back(std::make_unique<Texture>(awsomeFaceImg.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(stoneImg.c_str(),GL_TEXTURE_2D,2,GL_RGBA,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(grassImg.c_str(),GL_TEXTURE_2D,3,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(metalImg.c_str(),GL_TEXTURE_2D,4,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(concreteImg.c_str(),GL_TEXTURE_2D,5,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(woodFloorImage.c_str(),GL_TEXTURE_2D,6,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(doorWallImage.c_str(), GL_TEXTURE_2D,7,GL_RGB,GL_UNSIGNED_BYTE));
    this->textures.push_back(std::make_unique<Texture>(containerImg.c_str(), GL_TEXTURE_2D,8,GL_RGB,GL_UNSIGNED_BYTE));



//    this->awesomeTexture = std::make_unique<Texture>(awsomeFaceImg.c_str(),GL_TEXTURE_2D,1,GL_RGBA,GL_UNSIGNED_BYTE);
//    this->stoneTexture = std::make_unique<Texture>(stoneImg.c_str(),GL_TEXTURE_2D,2,GL_RGBA,GL_UNSIGNED_BYTE);
//    this->grassTexture = std::make_unique<Texture>(grassImg.c_str(),GL_TEXTURE_2D,3,GL_RGB,GL_UNSIGNED_BYTE);
//    this->metalTexture = std::make_unique<Texture>(metalImg.c_str(),GL_TEXTURE_2D,4,GL_RGB,GL_UNSIGNED_BYTE);
//    this->concreteTexture = std::make_unique<Texture>(concreteImg.c_str(),GL_TEXTURE_2D,5,GL_RGB,GL_UNSIGNED_BYTE);
//    this->woodFLoorTexture = std::make_unique<Texture>(woodFloorImage.c_str(),GL_TEXTURE_2D,6,GL_RGB,GL_UNSIGNED_BYTE);
//    this->doorWallTexture = std::make_unique<Texture>(doorWallImage.c_str(), GL_TEXTURE_2D,7,GL_RGB,GL_UNSIGNED_BYTE);



    models = std::vector<std::unique_ptr<BaseModel>>();

//    models.push_back(std::make_unique<Model>("model-files/hellknight/Hellknight_LATEST.obj", glm::vec3(2.0f, 0.0f, 5.0f), glm::vec3(0.7f, 0.7f, 0.7f), MODEL_LOADER_SHADER));
//    models.push_back(std::make_unique<Model>("model-files/doomSword/Doom Eternal Weapon.obj", glm::vec3(-6.0f, 0.2f, 8.9f), glm::vec3(4.0f, 4.0f, 4.0f), MODEL_LOADER_SHADER));



    // models.push_back(std::make_unique<Model>("model-files/doomSword/Doom Eternal Weapon.obj", glm::vec3(4.0f, 0.0f, 10.0f), glm::vec3(2.0f, 2.0f, 2.0f), MODEL_LOADER_SHADER));

    // models.push_back(std::make_unique<CubeModel>(containerTexture.get(),awesomeTexture.get(), glm::vec3(0.5f,  -0.5f, 9.5f),DOUBLE_TEXTURE_COLOR_SHADER));
    // models.push_back(std::make_unique<CubeModel>(concreteTexture.get(),concreteTexture.get(), glm::vec3(2.0f,  -0.5f, 3.0f),DOUBLE_TEXTURE_COLOR_SHADER));
    // models.push_back(std::make_unique<Model>("model-files/backpack/backpack.obj",glm::vec3(4.0f, -0.5f, 10.0f),MODEL_LOADER_SHADER));


//    models.push_back(std::make_unique<PlaneModel>(groundVerticesOne, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesTwo, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesThree, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesFour, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesFive, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesSix, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesSeven, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesEight, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesNine, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesTen, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(groundVerticesEleven, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesOneOne, containerTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesOneTwo, containerTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwoOne, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwoTwo, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesThree, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesFour, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesFive, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesSix, doorWallTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesSeven, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesEight, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesNine, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTen, doorWallTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesEleven, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwelve, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesThirteen, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesFourteen, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesFifteenOne, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesFifteenTwo, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesSixsteen, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesSeventeen, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesEighteen, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesNineteenOne, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesNineteenTwo, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwenty, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyone, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentytwo, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentythree, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyfour, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyfive, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentysix, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyseven, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyeight, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//
//
//
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesOne, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesTwo, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesThree, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesFour, concreteTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesFive, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesSix, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesSeven, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesEight, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesNine, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesTen, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesEleven, woodFLoorTexture.get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));



    models.push_back(std::make_unique<PlaneModel>(groundVerticesOne, textures[ETexture::WOODFLOOR].get(), glm::vec3(2.5f, -1.0f, 5.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesTwo, textures[ETexture::WOODFLOOR].get(), glm::vec3(-1.5,-1.0,1.0), DEFAULT));


    models.push_back(std::make_unique<PlaneModel>(groundVerticesThree, textures[ETexture::WOODFLOOR].get(), glm::vec3(-5.5f, -1.0f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesFour, textures[ETexture::WOODFLOOR].get(), glm::vec3(-1.5f, -1.0f, 8.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesFive, textures[ETexture::WOODFLOOR].get(), glm::vec3(6.0f, -1.0f, 3.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesSix, textures[ETexture::WOODFLOOR].get(), glm::vec3(9.5f, -1.0f, 1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesSeven, textures[ETexture::WOODFLOOR].get(), glm::vec3(7.5f, -1.0f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesEight, textures[ETexture::WOODFLOOR].get(), glm::vec3(11.5f, -1.0f, 6.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesNine, textures[ETexture::WOODFLOOR].get(), glm::vec3(2.5f, -1.0f, -3.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesTen, textures[ETexture::WOODFLOOR].get(), glm::vec3(3.5f, -1.0f, -4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(groundVerticesEleven, textures[ETexture::WOODFLOOR].get(), glm::vec3(1.5f, -1.0f, -4.0f), DEFAULT));



    models.push_back(std::make_unique<PlaneModel>(wallVerticesOneOne, textures[ETexture::CONTAINER].get(), glm::vec3(5.0f, 0.5f, 1.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesOneTwo, textures[ETexture::CONTAINER].get(), glm::vec3(5.0f, 0.5f, 7.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwoOne, textures[ETexture::CONCRETE].get(), glm::vec3(4.0f, 0.5f, 0.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwoTwo, textures[ETexture::CONCRETE].get(), glm::vec3(-3.0f, 0.5f, 0.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(wallVerticesThree, textures[ETexture::CONCRETE].get(), glm::vec3(-8.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesFour, textures[ETexture::CONCRETE].get(), glm::vec3(-4.0f, 0.5f, 9.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesFive, textures[ETexture::CONCRETE].get(), glm::vec3(0.0f, 0.5f, 9.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesSix, textures[ETexture::DOORWALL].get(), glm::vec3(2.5f, 0.5f, 10.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(wallVerticesSeven, textures[ETexture::CONCRETE].get(), glm::vec3(0.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesEight, textures[ETexture::CONCRETE].get(), glm::vec3(-1.5f, 0.5f, 2.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesNine, textures[ETexture::CONCRETE].get(), glm::vec3(-3.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTen, textures[ETexture::DOORWALL].get(), glm::vec3(-1.5f, 0.5f, 7.0f), DEFAULT));

    models.push_back(std::make_unique<PlaneModel>(wallVerticesEleven, textures[ETexture::CONCRETE].get(), glm::vec3(6.0f, 0.5f, 4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwelve, textures[ETexture::CONCRETE].get(), glm::vec3(7.0f, 0.5f, 5.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesThirteen, textures[ETexture::CONCRETE].get(), glm::vec3(11.5f, 0.5f, 7.0f), DEFAULT));



    models.push_back(std::make_unique<PlaneModel>(wallVerticesFourteen, textures[ETexture::CONCRETE].get(), glm::vec3(16.0f, 0.5f, 6.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesFifteenOne, textures[ETexture::CONCRETE].get(), glm::vec3(12.0f, 0.5f, 5.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesFifteenTwo, textures[ETexture::CONCRETE].get(), glm::vec3(8.0f, 0.5f, 4.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesSixsteen, textures[ETexture::CONCRETE].get(), glm::vec3(10.0f, 0.5f, 4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesSeventeen, textures[ETexture::CONCRETE].get(), glm::vec3(12.0f, 0.5f, 1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesEighteen, textures[ETexture::CONCRETE].get(), glm::vec3(9.5f, 0.5f, -2.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesNineteenOne, textures[ETexture::CONCRETE].get(), glm::vec3(7.0f, 0.5f, 0.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesNineteenTwo, textures[ETexture::CONCRETE].get(), glm::vec3(6.0f, 0.5f, 3.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwenty, textures[ETexture::CONCRETE].get(), glm::vec3(3.0f, 0.5f, -1.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyone, textures[ETexture::CONCRETE].get(), glm::vec3(3.5f, 0.5f, -2.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentytwo, textures[ETexture::CONCRETE].get(), glm::vec3(4.0f, 0.5f, -4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentythree, textures[ETexture::CONCRETE].get(), glm::vec3(3.5f, 0.5f, -5.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyfour, textures[ETexture::CONCRETE].get(), glm::vec3(2.5f, 0.5f, -6.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyfive, textures[ETexture::CONCRETE].get(), glm::vec3(1.5f, 0.5f, -5.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentysix, textures[ETexture::CONCRETE].get(), glm::vec3(1.0f, 0.5f, -4.0f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyseven, textures[ETexture::CONCRETE].get(), glm::vec3(1.5f, 0.5f, -2.5f), DEFAULT));
    models.push_back(std::make_unique<PlaneModel>(wallVerticesTwentyeight, textures[ETexture::CONCRETE].get(), glm::vec3(2.0f, 0.5f, -1.0f), DEFAULT));


//
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesOne, textures[ETexture::CONCRETE].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesTwo, textures[ETexture::CONCRETE].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesThree, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesFour, textures[ETexture::CONCRETE].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesFive, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesSix, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesSeven, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesEight, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesNine, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesTen, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//    models.push_back(std::make_unique<PlaneModel>(roofVerticesEleven, textures[ETexture::WOODFLOOR].get(), glm::vec3(0.0f, 0.0f, 0.0f), DEFAULT));
//

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







