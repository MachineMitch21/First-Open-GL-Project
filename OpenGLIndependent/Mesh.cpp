#include "Mesh.h"
#include <iostream>
Mesh::Mesh(Vertex* vertices, unsigned int num_verts)
{
	m_drawCount = num_verts;

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	std::vector<GLfloat> vert_data;
	vert_data.reserve(m_drawCount * 8);

	/*for (unsigned int i = 0; i < m_drawCount; i++) {
		vert_data.push_back(glm::vec3(vertices[i].getData()[0], vertices[i].getData()[1], vertices[i].getData()[2]));
		vert_data.push_back(glm::vec3(vertices[i].getData()[3], vertices[i].getData()[4], vertices[i].getData()[5]));
	}*/

	for (unsigned int i = 0; i < m_drawCount; i++) {
		vert_data.push_back(vertices[i].getData()[0]);
		vert_data.push_back(vertices[i].getData()[1]);
		vert_data.push_back(vertices[i].getData()[2]);
		vert_data.push_back(vertices[i].getData()[3]);
		vert_data.push_back(vertices[i].getData()[4]);
		vert_data.push_back(vertices[i].getData()[5]);
		vert_data.push_back(vertices[i].getData()[6]);
		vert_data.push_back(vertices[i].getData()[7]);
	}

	glGenBuffers(NUM_BUFFERS, &m_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	//Tell OpenGL what data we will be using
	/*glBufferData(GL_ARRAY_BUFFER, (num_verts * 2) * sizeof(vert_data[0]), &vert_data[0], GL_STATIC_DRAW);

	//Tell OpenGL where our position data is
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vert_data[0]), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Tell OpenGL where our color data is
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vert_data[0]), (GLvoid*)(sizeof(vert_data[0])));
	glEnableVertexAttribArray(1);

	//Tell OpenGL where our texture coords are
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(vert_data[0]), (GLvoid*)(2 * sizeof(vert_data[0])));
	glEnableVertexAttribArray(2);*/

	glBufferData(GL_ARRAY_BUFFER, (num_verts * 8) * sizeof(vert_data[0]), &vert_data[0], GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Mesh::draw() {
	glBindVertexArray(m_vao);
	glPolygonMode(GL_FRONT_AND_BACK, DRAW_MODE);
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glBindVertexArray(0);
}

void Mesh::setDrawMode(GLenum mode) {
	DRAW_MODE = mode;
}

GLenum Mesh::getDrawMode() {
	return DRAW_MODE;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
}
