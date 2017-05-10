#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>

class Vertex
{
public:
	Vertex(GLfloat* vertex_data, unsigned int element_count);

	void setPos(GLfloat pos[3]);
	void setColor(GLfloat color[3]);
	void setTexture(GLfloat texture[2]);

	GLfloat* getPos();
	GLfloat* getColor();
	GLfloat* getTexture();

	GLfloat* getData();

	unsigned int getElemCount();
	~Vertex();

private:
	GLfloat* m_vertexData;
	glm::vec3 m_pos;
	glm::vec3 m_color;
	glm::vec2 m_texture;
	unsigned int m_elemCount;
};

