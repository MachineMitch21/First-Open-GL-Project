#pragma once
#include "Vertex.h"
#include <GL/glew.h>
#include <vector>

class Mesh
{
public:
	Mesh(Vertex* vertices, /*GLuint* indices,*/ unsigned int num_verts /*unsigned int num_indices*/);
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
	GLenum DRAW_MODE = GL_LINE;
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	unsigned int m_drawCount;
};

