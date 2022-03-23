//
// Created by Lennert Steyaert on 16/03/2022.
//

#ifndef DOOM_QUAKE_BASICSHADER_H
#define DOOM_QUAKE_BASICSHADER_H

static const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

static const char *fragmentShaderSource = "#version 330 core\n"
                                 "out vec4 FragColor;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                 "}\0";

static const char* shaderPaths[] = {
        "shader-files/shader.vs",
        "shader-files/shader.fs",
        "shader-files/modelloading.vs",
        "shader-files/modelloading.fs"
};


#endif //DOOM_QUAKE_BASICSHADER_H
