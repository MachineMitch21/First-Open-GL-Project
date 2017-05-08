#pragma once
#include "Vertex.h"
#include <GL/glew.h>
#include <vector>

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
	unsigned int m_drawCount;
};

