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
        "/shader-files/default.fs",
        "/shader-files/gpuheight.vs",
        "/shader-files/gpuheight.fs",
        "/shader-files/gpuheight.tcs",
        "/shader-files/gpuheight.tes",
        "/shader-files/text.vs",
        "/shader-files/text.fs",
        "/shader-files/skybox.vs",
        "/shader-files/skybox.fs",
        "/shader-files/cross.vs",
        "/shader-files/cross.fs",
        "/shader-files/line.vs",
        "/shader-files/line.fs"
};

static std::vector<std::string> skybox_a
        {
                "/model-files/skybox/a/right.jpg",
                "/model-files/skybox/a/left.jpg",
                "/model-files/skybox/a/top.jpg",
                "/model-files/skybox/a/bottom.jpg",
                "/model-files/skybox/a/front.jpg",
                "/model-files/skybox/a/back.jpg"
        };

static std::vector<std::string> skybox_b
        {
                "/model-files/skybox/b/px.png",
                "/model-files/skybox/b/nx.png",
                "/model-files/skybox/b/py.png",
                "/model-files/skybox/b/ny.png",
                "/model-files/skybox/b/pz.png",
                "/model-files/skybox/b/nz.png"
        };


#endif //DOOM_QUAKE_BASICSHADER_H
