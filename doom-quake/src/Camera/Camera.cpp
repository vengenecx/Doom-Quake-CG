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
}


void Camera::cameraGrounded(bool grounded){
    this->grounded = grounded;
}


void Camera::updateSpeed(float speed) {
    this->MovementSpeed = speed;
}


//
//Camera::Camera(float width, float height, glm::vec3 position)
//{
//    Camera::width = width;
//    Camera::height = height;
//    Position = position;
//}
//
//void Camera::updateMatrix(float FOVdeg, float nearP
// lane, float farPlane)
//{
//    // Initializes matrices since otherwise they will be the null matrix
//    glm::mat4 view = glm::mat4(1.0f);
//    glm::mat4 projection = glm::mat4(1.0f);
//
//    // Makes camera look in the right direction from the right position
//    view = glm::lookAt(Position, Position + Orientation, Up);
//    // Adds perspective to the scene
//    projection = glm::perspective(glm::radians(FOVdeg), width / height, nearPlane, farPlane);
//
//    // Sets new camera matrix
//    cameraMatrix = projection * view;
//}
//
//void Camera::Matrix(Shader& shader, const char* uniform)
//{
//    // Exports camera matrix
//    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
//}
//
//void Camera::Inputs(GLFWwindow* window)
//{
//    // Handles key inputs
//    // main keys
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//    {
//        glm::vec3 copy = Orientation;
//        copy.y = 0;
//        Position += speed * copy;
//    }
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//    {
//        Position += speed * -glm::normalize(glm::cross(Orientation, Up));
//    }
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//    {
//        glm::vec3 copy = Orientation;
//        copy.y = 0;
//        Position += speed * -copy;
//    }
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//    {
//        Position += speed * glm::normalize(glm::cross(Orientation, Up));
//    }
//
//    // extra keys
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
//    {
//        Position += speed * Up;
//    }
//    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
//    {
//        Position += speed * -Up;
//    }
//    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
//    {
//        speed = 0.4f;
//    }
//    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
//    {
//        speed = 0.04f;;
//    }
//
//
//    // Handles mouse inputs
//    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
//    {
//        // Hides mouse cursor
//        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
//
//        // Prevents camera from jumping on the first click
//        if (firstClick)
//        {
//            glfwSetCursorPos(window, (width / 2), (height / 2));
//            firstClick = false;
//        }
//
//        // Stores the coordinates of the cursor
//        double mouseX;
//        double mouseY;
//        // Fetches the coordinates of the cursor
//        glfwGetCursorPos(window, &mouseX, &mouseY);
//
//        // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
//        // and then "transforms" them into degrees
//        float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
//        float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;
//
//        // Calculates upcoming vertical change in the Orientation
//        glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));
//
//        // Decides whether or not the next vertical Orientation is legal or not
//        if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
//        {
//            Orientation = newOrientation;
//        }
//
//        // Rotates the Orientation left and right
//        Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);
//
//        // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
//        glfwSetCursorPos(window, (width / 2), (height / 2));
//    }
//    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
//    {
//        // Unhides cursor since camera is not looking around anymore
//        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//        // Makes sure the next time the camera looks around it doesn't jump
//        firstClick = true;
//    }
//}