//
// Created by Lennert Steyaert on 16/03/2022.
//

#ifndef DOOM_QUAKE_BASICSHADER_H
#define DOOM_QUAKE_BASICSHADER_H

#include <vector>
#include <string>

//static const char *vertexShaderSource = "#version 330 core\n"
//                                 "layout (location = 0) in vec3 aPos;\n"
//                                 "void main()\n"
//                                 "{\n"
//                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//                                 "}\0";
//
//static const char *fragmentShaderSource = "#version 330 core\n"
//                                 "out vec4 FragColor;\n"
//                                 "void main()\n"
//                                 "{\n"
//                                 "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                 "}\0";

static const char* shaderPaths[] = {
        "/shader-files/modelloading.vs",
        "/shader-files/modelloading.fs",
        "/shader-files/doubletexturecolor.vs",
        "/shader-files/doubletexturecolor.fs",
        "/shader-files/default.vs",
        "/shader-files/default.fs"
};

static std::vector<std::string> skybox_a
        {
                "/model-files/skybox/right.jpg",
                "/model-files/skybox/left.jpg",
                "/model-files/skybox/top.jpg",
                "/model-files/skybox/bottom.jpg",
                "/model-files/skybox/front.jpg",
                "/model-files/skybox/back.jpg"
        };

static std::vector<std::string> skybox_b
        {
                "/model-files/skybox/px.png",
                "/model-files/skybox/nx.png",
                "/model-files/skybox/py.png",
                "/model-files/skybox/ny.png",
                "/model-files/skybox/pz.png",
                "/model-files/skybox/nz.png"
        };


#endif //DOOM_QUAKE_BASICSHADER_H
