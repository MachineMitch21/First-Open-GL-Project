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
	Mesh(GLfloat* vert_data, unsigned int num_verts, unsigned int elem_perVert);
	~Mesh();

	void draw(glm::vec3 translation, GLuint shader);
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
	std::vector<GLfloat> data;
	std::vector<GLuint> m_indices;
	unsigned int m_drawCount;
	unsigned int m_vertexSize;
	unsigned int m_elemPerVert;

private:
	void usePositionData(GLuint index, GLint size);
	void useColorData(GLuint index, GLint size);
	void useTextureData(GLuint index, GLint size);
};

