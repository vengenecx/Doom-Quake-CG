cmake_minimum_required(VERSION 3.21)
project(doom_quake)

set(CMAKE_CXX_STANDARD 17)

# Doom project includes
include_directories(include)
add_executable( doom_quake src/main.cpp
                include/Engine.h include/glad.h
                include/khrplatform.h
                src/glad/glad.c
                src/engine.cpp
                include/Shaders/basicShader.h
                src/Shaders/Shader.cpp
                include/Shaders/Shader.h
                include/Shaders/EShader.h
                include/Model/LearnOpenglModel/Mesh.h
                src/Model/LearnOpenglModel/Mesh.cpp
                include/Model/LearnOpenglModel/Model.h
                src/Model/LearnOpenglModel/Model.cpp
                include/Octree/Octree.h
                include/Octree/Node.h
                include/Octree/Octants.h
                include/Camera/Camera.h
                src/Camera/Camera.cpp
                include/Model/Cube/CubeModel.h
                include/Octree/BoundingBox.h 
                include/Ray/Ray.h 
                include/Octree/NodeCluster.h
                include/Register/EBO.h
                include/Register/VAO.h
                include/Register/VBO.h

                src/Octree/Node.cpp 
                src/Octree/NodeCluster.cpp 
                src/Octree/Octree.cpp 
                src/Ray/Ray.cpp
                src/Register/EBO.cpp
                src/Register/VAO.cpp
                src/Register/VBO.cpp
                src/Model/Cube/CubeModel.cpp
                include/Texture/Texture.h
                src/Texture/Texture.cpp
                src/Model/BaseModel.cpp
                include/Model/BaseModel.h
                include/Shaders/ShaderType.h include/Model/Skybox/Skybox.h src/Model/Skybox/Skybox.cpp)

               

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
file(COPY shader-files DESTINATION .)

# Model files include
file(COPY model-files DESTINATION .)