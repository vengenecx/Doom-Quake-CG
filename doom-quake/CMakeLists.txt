cmake_minimum_required(VERSION 3.21)
project(doom_quake)

set(CMAKE_CXX_STANDARD 14)

add_executable(doom_quake src/main.cpp include/Engine.h)
add_subdirectory(glfw-3.3.6)
target_link_libraries(doom_quake glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(doom_quake OpenGL::GL)