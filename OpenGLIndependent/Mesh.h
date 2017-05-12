#pragma once
#include "Vertex.h"
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int num_verts);
	~Mesh();

	void draw();
	void setDrawMode(GLenum mode);
	GLenum getDrawMode();

private:
	enum {
		POSITION_VB,
		NUM_BUFFERS
	};
	GLuint m_vao;
	GLuint m_vbo;
	GLuint m_ebo;
	GLenum DRAW_MODE = GL_FILL;
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	unsigned int m_drawCount;
	unsigned int m_vertexSize;
};

