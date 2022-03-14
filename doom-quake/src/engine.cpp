//
// Created by Lennert Steyaert on 14/03/2022.
//

#include <engine.h>
#include <iostream>

void Engine::render(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

