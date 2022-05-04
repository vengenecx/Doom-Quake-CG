//
// Created by Lennert Steyaert on 22/03/2022.
//

#ifndef DOOM_QUAKE_CAMERA_H
#define DOOM_QUAKE_CAMERA_H
#include <glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include  <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <vector>
#include "Shaders/Shader.h"
#include "GLFW/glfw3.h"

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    LEFTSTRAFE,
    RIGHTSTRAFE
};

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    // camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors
    Camera(bool grounded = false, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    // constructor with scalar values
    Camera(bool grounded, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix();

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset);

    void updateCamera(Shader* shader, float SCR_WIDTH, float SCR_HEIGHT, bool translation=true);


private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();
    bool grounded;
};

//class Camera
//{
//public:
//    // Stores the main vectors of the camera
//    glm::vec3 Position;
//    glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
//    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
//    glm::mat4 cameraMatrix = glm::mat4(1.0f);
//
//    // euler Angles
//    float Yaw;
//    float Pitch;
//
//    // Prevents the camera from jumping around when first clicking left click
//    bool firstClick = true;
//
//    // Stores the width and height of the window
//    // changed values to floats because radians only work with floating points!!
//    // was nessecary to only walk on a 2D plane like in a real first person game.
//    float width;
//    float height;
//
//    // Adjust the speed of the camera and it's sensitivity when looking around
//    float speed = 0.04f;
//    float sensitivity = 100.0f;
//
//    // Camera constructor to set up initial values
//    Camera(float width, float height, glm::vec3 position);
//
//    // Updates the camera matrix to the Vertex Shader
//    void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
//    // Exports the camera matrix to a shader
//    void Matrix(Shader& shader, const char* uniform);
//    // Handles camera inputs
//    void Inputs(GLFWwindow* window);
//};
#endif //DOOM_QUAKE_CAMERA_H
