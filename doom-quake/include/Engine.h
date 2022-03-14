//
// Created by Lennert Steyaert on 14/03/2022.
//

#ifndef DOOM_QUAKE_ENGINE_H
#define DOOM_QUAKE_ENGINE_H

#include "GLFW/glfw3.h"

class Engine {
public:
    void loop(GLFWwindow *window);
private:
    void keyHandler(GLFWwindow *window);
};
#endif //DOOM_QUAKE_ENGINE_H
