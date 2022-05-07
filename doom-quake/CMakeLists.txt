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
                include/Scenes/SceneTwo/SceneTwo.h
                include/Scenes/SceneOne/SceneOne.h
                

                src/Octree/Node.cpp 
                src/Octree/NodeCluster.cpp 
                src/Octree/Octree.cpp 
                src/Ray/Ray.cpp
                src/Register/EBO.cpp
                src/Register/VAO.cpp
                src/Register/VBO.cpp
                src/Model/Cube/CubeModel.cpp
                
                src/Model/Triangle/TriangleModel.cpp
                src/Scenes/SceneTwo/SceneTwo.cpp
                src/Scenes/SceneOne/SceneOne.cpp
                
                include/Texture/Texture.h
                src/Texture/Texture.cpp
                src/Model/BaseModel.cpp
                include/Model/BaseModel.h
                include/Shaders/ShaderType.h
                include/Model/Skybox/Skybox.h
                src/Model/Skybox/Skybox.cpp include/Model/Plane/PlaneModel.h
                src/Model/Plane/PlaneModel.cpp include/Map/Terrain/Terrain.h
                src/Map/Terrain/Terrain.cpp

                include/Scenes/Scene.h

                include/Text/TextRenderer.h src/Text/TextRenderer.cpp include/Game/Game.h src/Game/Game.cpp

                include/imgui_impl_opengl3_loader.h
                include/imgui_impl_opengl3.h
                include/imgui_impl_opengl3.cpp
                include/imstb_truetype.h
                include/imstb_rectpack.h
                include/imstb_textedit.h
                include/imgui_impl_glfw.h
                include/imgui_impl_glfw.cpp
                include/imgui_widgets.cpp
                include/imgui_internal.h
                include/imgui_tables.cpp
                include/imgui_draw.cpp
                include/imgui_demo.cpp
                include/imgui.h
                include/imgui.cpp
                include/imconfig.h include/Model/Cross/CrossModel.h src/Model/Cross/CrossModel.cpp include/Model/Test/TestModel.cpp include/Hit/Hit.h src/Hit/Hit.cpp include/Texture/ETexture.h)


               

# GLFW
add_subdirectory(glfw-3.3.6)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})
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

# IMGUI
#include_directories(imgui-master)
#add_subdirectory(imgui-master)
#link_libraries(doom_quake imgui-master)

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})
#target_link_libraries(doom_quake ${SDL2_LIBRARIES})


#find_package(ALEGRO REQUIRED)
#include_directories(${ALERGO5_INCLUDE_DIRS})
#target_link_libraries(doom_quake ${ALERGO5_LIBRARIES})

#INCLUDE_DIRECTORIES(  /opt/homebrew/Cellar/allegro/5.2.7.0/include )
#LINK_DIRECTORIES(  /opt/homebrew/Cellar/allegro/5.2.7.0/lib )
#
#file(GLOB LIBRARIES "/opt/homebrew/Cellar/allegro/5.2.7.0/lib/*.dylib")
#message("LIBRARIES = ${LIBRARIES}")
#
#TARGET_LINK_LIBRARIES(doom_quake  ${LIBRARIES})

# Set where the ImGui files are stored
#set(IMGUI_PATH  imgui-master)
#file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
#add_library("ImGui" ${IMGUI_SOURCES})
#target_include_directories(ImGui PUBLIC ${IMGUI_PATH})
#target_include_directories(IMGUI PUBLIC ${IMGUI_PATH})
#target_link_libraries(doom_quake ImGui)

#
#add_subdirectory(imgui-master)
#include_directories(${PROJECT_SOURCE_DIR})
#target_link_libraries(doom_quake imgui)



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