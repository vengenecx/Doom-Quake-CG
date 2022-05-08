cmake_minimum_required(VERSION 3.16)
project(doom_quake)

set(CMAKE_CXX_STANDARD 17)


if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()


# van TOM:
# src: https://stackoverflow.com/questions/46060038/undefined-reference-to-symbol-libdl-so-2-error-adding-symbols-dso-missing
if (LINUX)
set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
endif (LINUX)

# Doom project includes
if (LINUX)
    include_directories(include glfw-3.3.6/include)
else()
    include_directories(include)
endif (LINUX)


add_executable( doom_quake src/main.cpp
                include/Engine.h include/glad.h
                include/khrplatform.h
                src/glad/glad.c
                src/engine.cpp
                include/Shaders/basicShader.h
                src/Shaders/Shader.cpp
                include/Shaders/Shader.h
                include/Shaders/EShader.h
                include/Mesh.h
                src/Mesh.cpp
                include/Model.h
                src/Model.cpp
                include/Octree/Octree.h
                include/Octree/Node.h
                include/Octree/Octants.h
                include/Camera/Camera.h
                src/Camera/Camera.cpp
                include/Octree/BoundingBox.h 
                include/Ray/Ray.h 
                include/Octree/NodeCluster.h 
                include/Map/EBO.h
                include/Map/shaderClass.h
                include/Map/Texture.h
                include/Map/VAO.h
                include/Map/VBO.h
                
                include/Map/CameraMap.h
                src/Octree/Node.cpp 
                src/Octree/NodeCluster.cpp 
                src/Octree/Octree.cpp 
                src/Ray/Ray.cpp
                src/Map/EBO.cpp
                src/Map/shaderClass.cpp
                src/Map/stb.cpp
                src/Map/Texture.cpp
                src/Map/VAO.cpp
                src/Map/VBO.cpp
                src/Map/CameraMap.cpp
                )


if (WIN32 OR __APPLE__) 

    message(STATUS "building for non Linux OS")
    add_subdirectory(glfw-3.3.6)
    # GLFW
    target_link_libraries(doom_quake glfw)

    add_subdirectory(assimp-master)
    target_link_libraries(doom_quake assimp)
    

else()

    message(STATUS "Building for Linux")
    target_link_libraries(doom_quake glfw)

    # Assimp
    find_library(libassimp assimp)
    target_link_libraries(doom_quake ${libassimp})

endif (WIN32 OR __APPLE__) 




# Opengl
find_package(OpenGL REQUIRED)
target_link_libraries(doom_quake OpenGL::GL)



# GLM
add_subdirectory(glm-master)
target_link_libraries(doom_quake glm)

# STB
include_directories(stb-master)

# Shader files include
file(COPY shader-files DESTINATION .)

# Model files include
file(COPY model-files DESTINATION .)