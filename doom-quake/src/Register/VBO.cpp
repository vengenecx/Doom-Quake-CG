#include"Register/VBO.h"

// Constructor that generates a Vertex Buffer Object and links it to vertices
//VBO::VBO(GLfloat* vertices, GLsizeiptr size)
//{
//	glGenBuffers(1, &ID);
//	glBindBuffer(GL_ARRAY_BUFFER, ID);
//	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
//}

VBO::VBO(std::vector<float>& vertices, GLsizeiptr size, bool dynamic)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    if (dynamic)
        glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), &vertices[0], GL_DYNAMIC_DRAW);
    else
        glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), &vertices[0], GL_STATIC_DRAW);
}


void VBO::update(std::vector<GLfloat> &vertices, GLsizeiptr size) {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), &vertices[0], GL_DYNAMIC_DRAW);
}

// Binds the VBO
void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VBO
void VBO::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VBO
void VBO::remove()
{
	glDeleteBuffers(1, &ID);
}