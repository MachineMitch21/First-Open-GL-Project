#include "Mesh.h"
#include <iostream>
Mesh::Mesh(GLfloat* vert_data, unsigned int num_verts, unsigned int elem_PerVert)
{
	m_drawCount = num_verts;

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//std::vector<GLfloat> vert_data;
	m_vertices.reserve(m_drawCount);

	/*for (unsigned int i = 0; i < m_drawCount; i++) {
		vert_data.push_back(glm::vec3(vertices[i].getData()[0], vertices[i].getData()[1], vertices[i].getData()[2]));
		vert_data.push_back(glm::vec3(vertices[i].getData()[3], vertices[i].getData()[4], vertices[i].getData()[5]));
	}*/

	for (unsigned int i = 0; i < m_drawCount; i+=elem_PerVert) {
		GLfloat temp_data[] = { vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i] };
		
		m_vertices.push_back(Vertex(temp_data, elem_PerVert));
		data.push_back(vert_data[i]);
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
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vert_data), vert_data, GL_STATIC_DRAW);

	// Tell OpenGL where to find our position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Tell OpenGL where to find our color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// Tell OpenGL where to find our texture coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	//glBindVertexArray(0);
}

void Mesh::draw(glm::vec3 translation, GLuint shader) {
	glBindVertexArray(m_vao);
	glPolygonMode(GL_FRONT_AND_BACK, DRAW_MODE);

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(shader, "model");
	model = glm::translate(model, translation);
	model = glm::rotate(model, glm::radians(20.0f * (GLfloat)glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	//glBindVertexArray(0);
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
