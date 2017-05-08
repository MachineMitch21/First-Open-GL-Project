#pragma once
#include "Vertex.h"
#include <GL/glew.h>
#include <vector>

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	~Mesh();

	void draw();

private:
	enum {
		POSITION_VB,
		TEXCOORD_VB,
		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

