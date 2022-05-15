//
// Created by Lennert Steyaert on 22/03/2022.
//

// We used the following URL to help us understand and code the following code:
// https://learnopengl.com/Getting-started/Camera 

#include <Camera/Camera.h>

// constructor with vectors
Camera::Camera(bool grounded, glm::vec3 position , glm::vec3 up, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), grounded(grounded)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

// constructor with scalar values
Camera::Camera(bool grounded,float posX, float posY, float posZ, float upX, float upY, float upZ,  float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), grounded(grounded)
{
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD) {
        // glm::vec3(X,Y,Z)!!! we only want to change the X-Z position
        if (grounded)
            Position += glm::vec3(glm::cos(glm::radians(Yaw)), 0, glm::sin(glm::radians(Yaw))) * velocity;
        else
            Position += Front * velocity;

    }
    if (direction == BACKWARD) {
        if (grounded)
            Position -= glm::vec3(glm::cos(glm::radians(Yaw)), 0, glm::sin(glm::radians(Yaw))) * velocity;
        else
            Position -= Front * velocity;
    }
    if (direction == LEFT) {
        Position -= Right * velocity;
    }
    if (direction == RIGHT) {
        Position += Right * velocity;
    }

    if(direction == LEFTSTRAFE){
        Position -= Right * ((float )(velocity/2.0));
        if (grounded)
            Position += glm::vec3(glm::cos(glm::radians(Yaw)), 0, glm::sin(glm::radians(Yaw))) * ((float )(velocity/2.0));
        else
            Position += Front * ((float )(velocity/2.0));
    }

    if(direction == RIGHTSTRAFE){
        Position += Right * ((float )(velocity/2.0));
        if (grounded)
            Position += glm::vec3(glm::cos(glm::radians(Yaw)), 0, glm::sin(glm::radians(Yaw))) * ((float )(velocity/2.0));
        else
            Position += Front * ((float )(velocity/2.0));
    }
}

// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw   += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}

// calculates the front vector from the Camera's (updated) Euler Angles
void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up    = glm::normalize(glm::cross(Right, Front));
}


void Camera::updateCamera(Shader *shader, float SCR_WIDTH, float SCR_HEIGHT, bool translation) {
    glm::mat4 projection = glm::perspective(glm::radians(Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100000.0f);
    glm::mat4 view;
    if(translation)
        view = GetViewMatrix();
    else
        view = glm::mat4(glm::mat3(GetViewMatrix()));

    shader->setMat4("projection", projection);
    shader->setMat4("view", view);

    if (shader->getShaderType() == LIGHT) {
        shader->setVec3("viewPos", Position);
        shader->setVec3("direction", Front);
    }
}


void Camera::cameraGrounded(bool grounded){
    this->grounded = grounded;
}


void Camera::updateSpeed(float speed) {
    this->MovementSpeed = speed;
}