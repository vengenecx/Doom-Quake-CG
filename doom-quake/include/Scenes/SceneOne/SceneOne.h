#ifndef DOOM_QUAKE_SCENEONE_H
#define DOOM_QUAKE_SCENEONE_H

#include "Model/BaseModel.h"
#include "Model/Cube/CubeModel.h"
#include "Model/LearnOpenglModel/Model.h"
#include "Model/Plane/PlaneModel.h"
#include "Texture/Texture.h"
#include "Shaders/ShaderType.h"
#include<filesystem>
#include "Camera/Camera.h"
#include "Shaders/basicShader.h"
#include "Shaders/EShader.h"

#include "Texture/ETexture.h"

#include "Scenes/Scene.h"

#include "Model/PointLight/PointLight.h"
#include "Model/Test/TestModel.h"
#include "Model/DirectionLight/DirectionLight.h"
#include "Model/SpotLight/SpotLight.h"

namespace fs = std::filesystem;


class SceneOne : public Scene {
public:
    SceneOne();

    void draw(std::vector<std::unique_ptr<Shader>> & shaders,std::vector<std::unique_ptr<Hit>>& hitPoints, Culling* culling, bool octreeVisible);
    void remove();
    void shoot(Ray* ray, std::vector<std::unique_ptr<Hit>> & hitPoints);
    void spotLightToggle(bool state);
    
private:
    std::string currentDir = (fs::current_path()).string();
    std::vector<std::unique_ptr<BaseModel>> models; // List of all models
    std::vector<std::unique_ptr<Texture>> textures; // All textures
    std::unique_ptr<Texture> potholeTexture;

    std::unique_ptr<SpotLight> spotLight; // Spotlight implementation
};

#endif