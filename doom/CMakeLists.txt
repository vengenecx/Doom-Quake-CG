cmake_minimum_required(VERSION 3.21)
project (doom)

set(CMAKE_CXX_STANDARD 14)

add_executable(doom src/main.cpp)
add_subdirectory(glfw-3.3.6)
target_link_libraries(doom glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(doom OpenGL::GL)