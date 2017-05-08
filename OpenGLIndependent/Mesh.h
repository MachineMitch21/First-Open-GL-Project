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

private:
	enum {
		POSITION_VB,
		NUM_BUFFERS
	};
	GLuint m_vao;
	GLuint m_vbo;
	unsigned int m_drawCount;
};

