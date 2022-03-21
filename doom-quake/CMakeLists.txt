cmake_minimum_required(VERSION 3.21)
project(doom_quake)

set(CMAKE_CXX_STANDARD 14)

# Doom project includes
include_directories(include)
add_executable(doom_quake src/main.cpp include/Engine.h include/glad.h include/khrplatform.h src/glad/glad.c src/engine.cpp include/Shaders/basicShader.h src/Shaders/Shader.cpp include/Shaders/Shader.h include/Shaders/EShader.h include/Mesh.h src/Mesh.cpp include/Model.h src/Model.cpp include/Octree/Octree.h include/Octree/Node.h include/Octree/Octants.h)

# GLFW

add_subdirectory(glfw-3.3.6)
target_link_libraries(doom_quake glfw)


# Opengl
find_package(OpenGL REQUIRED)
target_link_libraries(doom_quake OpenGL::GL)

# Assimp
add_subdirectory(assimp-master)
target_link_libraries(doom_quake assimp)


# GLM
add_subdirectory(glm-master)
target_link_libraries(doom_quake glm)

# STB
include_directories(stb-master)

# Shader files include
#include_directories()
file(COPY shader-files DESTINATION .)