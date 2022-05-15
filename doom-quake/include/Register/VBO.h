#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include"glad.h"

#include <vector>

// Based on: https://github.com/VictorGordan/opengl-tutorials

class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
//	VBO(GLfloat* vertices, GLsizeiptr size);
    VBO(std::vector<GLfloat>& vertices, GLsizeiptr size, bool dynamic = false);

    void update(std::vector<GLfloat>& vertices,GLsizeiptr size);

	// Binds the VBO
	void bind();
	// Unbinds the VBO
	void unbind();
	// Deletes the VBO
	void remove();
};

#endif