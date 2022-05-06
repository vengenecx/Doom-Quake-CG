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

namespace fs = std::filesystem;


class SceneOne : public Scene {
    public:
        void draw(std::vector<std::unique_ptr<Shader>> & shaders,std::vector<std::unique_ptr<Hit>>& hitPoints, bool octreeVisible);
        SceneOne();
        void remove();

        void shoot(Ray* ray, std::vector<std::unique_ptr<Hit>> & hitPoints);
    
    private:
        std::string currentDir = (fs::current_path()).string();

        std::vector<std::unique_ptr<BaseModel>> models;


        std::vector<std::unique_ptr<Texture>> textures;


        // all the textures:
//        std::unique_ptr<Texture> containerTexture;
//        std::unique_ptr<Texture> awesomeTexture;
//        std::unique_ptr<Texture> stoneTexture;
//        std::unique_ptr<Texture> grassTexture;
//        std::unique_ptr<Texture> metalTexture;
//        std::unique_ptr<Texture> concreteTexture;
//        std::unique_ptr<Texture> bulletHoleTexture;
//        std::unique_ptr<Texture> woodFLoorTexture;
//        std::unique_ptr<Texture> doorWallTexture;


        std::unique_ptr<Texture> potholeTexture;

        std::vector<float>  vertices;

        // start ground vertices
//        std::vector<float> groundVerticesOne{
//                // positions          // colors           // texture coords
//                5.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                5.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                0.0f,  0.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesOne{
                // positions          // colors           // texture coords
                2.5f,  0.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                2.5f, 0.0f, -5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -2.5f, 0.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -2.5f,  0.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };



//        std::vector<float> groundVerticesTwo{
//                // positions          // colors           // texture coords
//                0.0f,  -1.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                0.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -3.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -3.0f,  -1.0f, 2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesTwo{
                // positions          // colors           // texture coords
                1.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                1.5f, 0.0f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -1.5f, 0.0f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -1.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };


//        std::vector<float> groundVerticesThree{
//                // positions          // colors           // texture coords
//                -3.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                -3.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -8.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -8.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesThree{
                // positions          // colors           // texture coords
                2.5f,  0.0f, 4.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                2.5f, 0.0f, -4.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -2.5f, 0.0f, -4.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -2.5f,  0.0f, 4.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };


//        std::vector<float> groundVerticesFour{
//                // positions          // colors           // texture coords
//                0.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                0.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -3.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -3.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesFour{
                // positions          // colors           // texture coords
                1.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                1.5f, 0.0f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -1.5f, 0.0f, -1.0,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -1.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> groundVerticesFive{
//                // positions          // colors           // texture coords
//                7.0f,  -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                7.0f, -1.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                5.0f, -1.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                5.0f,  -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesFive{
                // positions          // colors           // texture coords
                1.0f,  0.0f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                1.0f, 0.0f, -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -1.0f, 0.0f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -1.0,  0.0f, 0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> groundVerticesSix{
//                // positions          // colors           // texture coords
//                12.0f,  -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                12.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                7.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                7.0f,  -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesSix{
                // positions          // colors           // texture coords
                2.5f,  0.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                2.5f, 0.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -2.5f, 0.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -2.5f,  0.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> groundVerticesSeven{
//                // positions          // colors           // texture coords
//                8.0f,  -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                8.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                7.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                7.0f,  -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesSeven{
                // positions          // colors           // texture coords
                0.5f,  0.0f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.5f, 0.0f, -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, 0.0f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  0.0f, 0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> groundVerticesEight{
//                // positions          // colors           // texture coords
//                16.0f,  -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                16.0f, -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                7.0f, -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                7.0f,  -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesEight{
                // positions          // colors           // texture coords
                4.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                4.5f, 0.0f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -4.5f, 0.0f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -4.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> groundVerticesNine{
//                // positions          // colors           // texture coords
//                3.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                3.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                2.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                2.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesNine{
                // positions          // colors           // texture coords
                0.5f,  0.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.5f, 0.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, 0.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  0.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> groundVerticesTen{
//                // positions          // colors           // texture coords
//                4.0f,  -1.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                4.0f, -1.0f, -5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                3.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                3.0f,  -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> groundVerticesTen{
                // positions          // colors           // texture coords
                0.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.5f, 0.0f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, 0.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  0.0f, 2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> groundVerticesEleven{
//                // positions          // colors           // texture coords
//                2.0f,  -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                2.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                1.0f, -1.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                1.0f,  -1.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

    std::vector<float> groundVerticesEleven{
            // positions          // colors           // texture coords
            0.5f,  0.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
            0.5f, 0.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, 0.0f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.0f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
    };



    // start wall vertices
//        std::vector<float> wallVerticesOneOne{
//                // positions          // colors           // texture coords
//                5.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                5.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                5.0f, 2.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                5.0f,  -1.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesOneOne{
                // positions          // colors           // texture coords
                0.0f,  -1.5f, -1.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, 1.5f, -1.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 1.5f, 1.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  -1.5f, 1.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };


//        std::vector<float> wallVerticesOneTwo{
//                // positions          // colors           // texture coords
//                5.0f,  -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                5.0f, 2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                5.0f, 2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                5.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };


        std::vector<float> wallVerticesOneTwo{
                // positions          // colors           // texture coords
                0.0f,  -1.5f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, 1.5f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 1.5f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  -1.5f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwoOne{
//                // positions          // colors           // texture coords
//                5.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                5.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                3.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                3.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwoOne{
                // positions          // colors           // texture coords
                1.0f,  -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                1.0f, 1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -1.0f, 1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -1.0f,  -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwoTwo{
//                // positions          // colors           // texture coords
//                2.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                2.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -8.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -8.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwoTwo{
                // positions          // colors           // texture coords
                5.0f,  -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                5.0f, 1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -5.0f, 1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -5.0f,  -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesThree{
//                // positions          // colors           // texture coords
//                -8.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                -8.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -8.0f, 2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -8.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesThree{
                // positions          // colors           // texture coords
                0.0f,  -1.5f, -4.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, 1.5f, -4.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 1.5f, 4.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  -1.5f, 4.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesFour{
//                // positions          // colors           // texture coords
//                -8.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                -8.0f, 2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                0.0f, 2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                0.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesFour{
                // positions          // colors           // texture coords
                -4.0f,  -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -4.0f, 1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                4.0f, 1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                4.0f,  -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesFive{
//                // positions          // colors           // texture coords
//                0.0f,  -1.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                0.0f, 2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                0.0f, 2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                0.0f,  -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesFive{
                // positions          // colors           // texture coords
                0.0f,  -1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, 1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  -1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesSix{
//                // positions          // colors           // texture coords
//                0.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                0.0f, -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                5.0f, -1.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                5.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesSix{
                // positions          // colors           // texture coords
                -2.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -2.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                2.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                2.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesSeven{
//                // positions          // colors           // texture coords
//                0.0f,  2.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                0.0f, -1.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                0.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                0.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesSeven{
                // positions          // colors           // texture coords
                0.0f,  1.5f, -2.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, -2.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, 2.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, 2.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesEight{
//                // positions          // colors           // texture coords
//                0.0f,  2.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                0.0f, -1.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -3.0f, -1.0f, 2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -3.0f,  2.0f, 2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesEight{
                // positions          // colors           // texture coords
                1.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                1.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -1.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -1.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesNine{
//                // positions          // colors           // texture coords
//                -3.0f,  2.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                -3.0f, -1.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -3.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -3.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesNine{
                // positions          // colors           // texture coords
                0.0f,  1.5f, -2.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, -2.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, 2.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, 2.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTen{
//                // positions          // colors           // texture coords
//                0.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                0.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                -3.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                -3.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTen{
                // positions          // colors           // texture coords
                1.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                1.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -1.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -1.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };



//        std::vector<float> wallVerticesEleven{
//                // positions          // colors           // texture coords
//                5.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                5.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                7.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                7.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesEleven{
                // positions          // colors           // texture coords
                -1.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -1.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                1.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                1.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwelve{
//                // positions          // colors           // texture coords
//                7.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                7.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                7.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                7.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwelve{
                // positions          // colors           // texture coords
                0.0f,  1.5f, -1.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, -1.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, 1.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, 1.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesThirteen{
//                // positions          // colors           // texture coords
//                7.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                7.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                16.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                16.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesThirteen{
                // positions          // colors           // texture coords
                -4.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -4.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                4.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                4.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };









//        std::vector<float> wallVerticesFourteen{
//                // positions          // colors           // texture coords
//                16.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                16.0f, -1.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                16.0f, -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                16.0f,  2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesFourteen{
                // positions          // colors           // texture coords
                0.0f,  1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesFifteenOne{
//                // positions          // colors           // texture coords
//                16.0f,  2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                16.0f, -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                8.0f, -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                8.0f,  2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesFifteenOne{
                // positions          // colors           // texture coords
                -4.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -4.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                4.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                4.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//    std::vector<float> wallVerticesFifteenTwo{
//                // positions          // colors           // texture coords
//                8.0f,  2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                8.0f, -1.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                8.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                8.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesFifteenTwo{
                // positions          // colors           // texture coords
                0.0f,  1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
//    std::vector<float> wallVerticesSixsteen{
//                // positions          // colors           // texture coords
//                8.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                8.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                12.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                12.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesSixsteen{
                // positions          // colors           // texture coords
                -2.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -2.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                2.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                2.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
//    std::vector<float> wallVerticesSeventeen{
//                // positions          // colors           // texture coords
//                12.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                12.0f, -1.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                12.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                12.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesSeventeen{
                // positions          // colors           // texture coords
                0.0f,  1.5f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
//    std::vector<float> wallVerticesEighteen{
//                // positions          // colors           // texture coords
//                12.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                12.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                7.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                7.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesEighteen{
                // positions          // colors           // texture coords
                -2.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -2.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                2.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                2.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
//    std::vector<float> wallVerticesNineteenOne{
//                // positions          // colors           // texture coords
//                7.0f,  2.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                7.0f, -1.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                7.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                7.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesNineteenOne{
                // positions          // colors           // texture coords
                0.0f,  1.5f, 2.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, 2.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, -2.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, -2.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
//        std::vector<float> wallVerticesNineteenTwo{
//                // positions          // colors           // texture coords
//                7.0f,  2.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                7.0f, -1.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                5.0f, -1.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                5.0f,  2.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesNineteenTwo{
                // positions          // colors           // texture coords
                1.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                1.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -1.0f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -1.0f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwenty{
//                // positions          // colors           // texture coords
//                3.0f,  2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                3.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                3.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                3.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwenty{
                // positions          // colors           // texture coords
                0.0f,  1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
//        std::vector<float> wallVerticesTwentyone{
//                // positions          // colors           // texture coords
//                3.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                3.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                4.0f, -1.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                4.0f,  2.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwentyone{
                // positions          // colors           // texture coords
                -0.5f,  1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -0.5f, -1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.5f, -1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.5f,  1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwentytwo{
//                // positions          // colors           // texture coords
//                4.0f,  2.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                4.0f, -1.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                4.0f, -1.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                4.0f,  2.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwentytwo{
                // positions          // colors           // texture coords
                0.0f,  1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwentythree{
//                // positions          // colors           // texture coords
//                4.0f,  2.0f, -5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                4.0f, -1.0f, -5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                3.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                3.0f,  2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwentythree{
                // positions          // colors           // texture coords
                0.5f,  1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.5f, -1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, -1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwentyfour{
//                // positions          // colors           // texture coords
//                3.0f,  2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                3.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                2.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                2.0f,  2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };
        std::vector<float> wallVerticesTwentyfour{
                // positions          // colors           // texture coords
                0.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, -1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  1.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwentyfive{
//                // positions          // colors           // texture coords
//                2.0f,  2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                2.0f, -1.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                1.0f, -1.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                1.0f,  2.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwentyfive{
                // positions          // colors           // texture coords
                0.5f,  1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.5f, -1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, -1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwentysix{
//                // positions          // colors           // texture coords
//                1.0f,  2.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                1.0f, -1.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                1.0f, -1.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                1.0f,  2.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwentysix{
                // positions          // colors           // texture coords
                0.0f,  1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
//        std::vector<float> wallVerticesTwentyseven{
//                // positions          // colors           // texture coords
//                2.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                2.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                1.0f, -1.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                1.0f,  2.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwentyseven{
                // positions          // colors           // texture coords
                0.5f,  1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.5f, -1.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, -1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  1.5f, -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };

//        std::vector<float> wallVerticesTwentyeight{
//                // positions          // colors           // texture coords
//                2.0f,  2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
//                2.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
//                2.0f, -1.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//                2.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
//        };

        std::vector<float> wallVerticesTwentyeight{
                // positions          // colors           // texture coords
                0.0f,  1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, -1.5f, 1.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, -1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  1.5f, -1.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };




        // start roof vertices
        std::vector<float> roofVerticesOne{
                // positions          // colors           // texture coords
                5.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                5.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                0.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                0.0f,  2.0f, 10.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesTwo{
                // positions          // colors           // texture coords
                0.0f,  2.0f, 2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -3.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -3.0f,  2.0f, 2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesThree{
                // positions          // colors           // texture coords
                -3.0f,  2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                -3.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -8.0f, 2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -8.0f,  2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesFour{
                // positions          // colors           // texture coords
                0.0f,  2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                0.0f, 2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                -3.0f, 2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -3.0f,  2.0f, 9.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesFive{
                // positions          // colors           // texture coords
                7.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                7.0f, 2.0f, 3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                5.0f, 2.0f, 3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                5.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesSix{
                // positions          // colors           // texture coords
                12.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                12.0f, 2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                7.0f, 2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                7.0f,  2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesSeven{
                // positions          // colors           // texture coords
                8.0f,  2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                8.0f, 2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                7.0f, 2.0f, 4.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                7.0f,  2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesEight{
                // positions          // colors           // texture coords
                16.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                16.0f, 2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                7.0f, 2.0f, 5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                7.0f,  2.0f, 7.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesNine{
                // positions          // colors           // texture coords
                3.0f,  2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                3.0f, 2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                2.0f, 2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                2.0f,  2.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesTen{
                // positions          // colors           // texture coords
                4.0f,  2.0f, -3.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                4.0f, 2.0f, -5.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                3.0f, 2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                3.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };
        std::vector<float> roofVerticesEleven{
                // positions          // colors           // texture coords
                2.0f,  2.0f, -2.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
                2.0f, 2.0f, -6.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
                1.0f, 2.0f, -5.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                1.0f,  2.0f, -3.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // top left
        };        
};

#endif