#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad.h>

#include <vector>

class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
//	VBO(GLfloat* vertices, GLsizeiptr size);
    VBO(std::vector<GLfloat> vertices, GLsizeiptr size);

	// Binds the VBO
	void bind();
	// Unbinds the VBO
	void unbind();
	// Deletes the VBO
	void remove();
};

#endif