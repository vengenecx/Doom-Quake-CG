#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"Map/shaderClass.h"

class CameraMap
{
public:
	// Stores the main vectors of the camera
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	// Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;

	// Stores the width and height of the window
	// changed values to floats because radians only work with floating points!! 
	// was nessecary to only walk on a 2D plane like in a real first person game.
	float width;
	float height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 0.04f;
	float sensitivity = 100.0f;

	// Camera constructor to set up initial values
    CameraMap(float width, float height, glm::vec3 position);

	// Updates the camera matrix to the Vertex Shader
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	// Exports the camera matrix to a shader
	void Matrix(ShaderMap& shader, const char* uniform);
	// Handles camera inputs
	void Inputs(GLFWwindow* window);
};
#endif