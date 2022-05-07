#ifndef DOOM_QUAKE_SCENETWO_H
#define DOOM_QUAKE_SCENETWO_H

#include "Model/BaseModel.h"
#include "Model/Cube/CubeModel.h"
#include "Model/LearnOpenglModel/Model.h"
#include "Model/Plane/PlaneModel.h"
#include "Texture/Texture.h"
#include "Shaders/ShaderType.h"
#include <filesystem>
#include "Camera/Camera.h"
#include "Shaders/basicShader.h"
#include "Shaders/EShader.h"
#include "Scenes/Scene.h"

namespace fs = std::filesystem;



class SceneTwo : public Scene {
    public:

        SceneTwo();
        void draw(std::vector<std::unique_ptr<Shader>> & shaders,std::vector<std::unique_ptr<Hit>>& hitPoints,Culling* culling, bool octreeVisible);
        void remove();
        void shoot(Ray* ray, std::vector<std::unique_ptr<Hit>> & hitPoints);
    
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
        std::unique_ptr<Texture> bulletHoleTexture;
        std::unique_ptr<Texture> woodFLoorTexture;




        std::string currentDir = (fs::current_path()).string();

        std::vector<float>  vertices;

        std::vector<float> groundVerticesOne{
                // positions          // colors           // texture coords
                3.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                3.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> groundVerticesTwo{
                // positions          // colors           // texture coords
                10.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                10.0f, -1.0f, 6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                3.0f, -1.0f, 6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                3.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> wallVerticesOne{
                // positions          // colors           // texture coords
                3.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                3.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };


        std::vector<float> wallVerticesTwo{
                // positions          // colors           // texture coords
                0.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> wallVerticesThree{
                // positions          // colors           // texture coords
                0.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                10.0f, -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                10.0f, 2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> wallVerticesFour{
                // positions          // colors           // texture coords
                10.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                10.0f, -1.0f, 6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                10.0f, 2.0f, 6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                10.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> wallVerticesFive{
                // positions          // colors           // texture coords
                10.0f,  -1.0f, 6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                3.0f, -1.0f, 6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                3.0f, 2.0f, 6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                10.0f,  2.0f, 6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> wallVerticesSix{
                // positions          // colors           // texture coords
                3.0f,  -1.0f, 6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                3.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                3.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                3.0f,  2.0f, 6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> roofVerticesOne{
                // positions          // colors           // texture coords
                3.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                3.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

        std::vector<float> roofVerticesTwo{
                // positions          // colors           // texture coords
                10.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                10.0f, 2.0f, 6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                3.0f, 2.0f, 6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                3.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

};

#endif //DOOM_QUAKE_SCENETWO_H