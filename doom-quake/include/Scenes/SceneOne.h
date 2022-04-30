#ifndef DOOM_QUAKE_SCENEONE_H
#define DOOM_QUAKE_SCENEONE_H

#include "Model/BaseModel.h"
#include "Model/Cube/CubeModel.h"
#include "Model/LearnOpenglModel/Model.h"
#include "Model/Plane/PlaneModel.h"
#include "Texture/Texture.h"
#include "Shaders/ShaderType.h"
#include<filesystem>
#include <Camera/Camera.h>
#include <Shaders/basicShader.h>
#include <Shaders/EShader.h>

namespace fs = std::filesystem;

#include <vector>
#include <memory>

class SceneOne{
    public:
        // old: 
        void drawing(std::vector<std::unique_ptr<Shader>> & shaders);
        //void drawing(std::vector<Shader*> & shaders);
        // new:
        SceneOne();
        void remove();
    
    private:
        // to append al the models to:
        std::vector<std::unique_ptr<BaseModel>> models;

        // all the textures:
        std::unique_ptr<Texture> containerTexture;
        std::unique_ptr<Texture> awesomeTexture;
        std::unique_ptr<Texture> stoneTexture;
        std::unique_ptr<Texture> grassTexture;
        std::unique_ptr<Texture> metalTexture;
        std::unique_ptr<Texture> concreteTexture;

        std::string currentDir = (fs::current_path()).string();

        std::vector<float>  vertices;


};

#endif //DOOM_QUAKE_SCENEONE_H