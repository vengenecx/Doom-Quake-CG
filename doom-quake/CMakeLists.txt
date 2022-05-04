cmake_minimum_required(VERSION 3.21)
project(doom_quake)

set(CMAKE_CXX_STANDARD 17)

# Doom project includes
include_directories(include)

# added for LINUX - Benoit
# include_directories (/usr/include/freetype2)

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

                include/Model/Triangle/TriangleModel.h
                include/Scenes/SceneOne.h
                include/Scenes/SceneBig.h

                src/Octree/Node.cpp 
                src/Octree/NodeCluster.cpp 
                src/Octree/Octree.cpp 
                src/Ray/Ray.cpp
                src/Register/EBO.cpp
                src/Register/VAO.cpp
                src/Register/VBO.cpp
                src/Model/Cube/CubeModel.cpp
                
                src/Model/Triangle/TriangleModel.cpp 
                src/Scenes/SceneOne.cpp
                src/Scenes/SceneBig.cpp
                

                include/Texture/Texture.h
                src/Texture/Texture.cpp
                src/Model/BaseModel.cpp
                include/Model/BaseModel.h
                include/Shaders/ShaderType.h
                include/Model/Skybox/Skybox.h
                src/Model/Skybox/Skybox.cpp include/Model/Plane/PlaneModel.h
                src/Model/Plane/PlaneModel.cpp include/Map/Terrain/Terrain.h
                src/Map/Terrain/Terrain.cpp
                include/Text/TextRenderer.h src/Text/TextRenderer.cpp)

               

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

# if(APPLE)
#     find_package(Freetype REQUIRED)
#     message(STATUS "Found Freetype in ${FREETYPE_INCLUDE_DIRS}")
#     target_link_libraries(doom_quake ${FREETYPE_LIBRARIES})
#     target_include_directories(doom_quake PRIVATE ${FREETYPE_INCLUDE_DIRS})
# endif(APPLE)

find_package(Freetype REQUIRED)
message(STATUS "Found Freetype in ${FREETYPE_INCLUDE_DIRS}")
target_link_libraries(doom_quake ${FREETYPE_LIBRARIES})
target_include_directories(doom_quake PRIVATE ${FREETYPE_INCLUDE_DIRS})