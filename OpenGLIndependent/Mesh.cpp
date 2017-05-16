#include "Mesh.h"
#include <iostream>
Mesh::Mesh(GLfloat* vert_data, unsigned int num_verts, unsigned int elem_PerVert)
{
	m_drawCount = num_verts;
	m_elemPerVert = elem_PerVert;

	m_vertices.reserve(m_drawCount);

	for (unsigned int i = 0; i < m_drawCount; i+=elem_PerVert) {
		GLfloat temp_data[] = { vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i], vert_data[i] };
		
		m_vertices.push_back(Vertex(temp_data, elem_PerVert));
		data.push_back(vert_data[i]);
	}

	//Prepare our vertex array
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//Prepare our vertex buffer object
	glGenBuffers(NUM_BUFFERS, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, (m_drawCount * m_elemPerVert) * sizeof(vert_data[0]), &vert_data[0], GL_STATIC_DRAW);

	GLuint index = 0;
	bool zeroIsSet = false;

	if (elem_PerVert >= 3) {
		(index == 0 ? index = index, zeroIsSet = true : index++);
		usePositionData(index, 3);
	}

	if (elem_PerVert >= 6) {
		index++;
		useColorData(index, 3);
	}

	if (elem_PerVert >= 8 || elem_PerVert >= 5) {
		index++;
		useTextureData(index, 2);
	}
}

void Mesh::usePositionData(GLuint index, GLint size) {
	// Tell OpenGL where to find our position attribute
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, m_elemPerVert * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(index);
}

void Mesh::useColorData(GLuint index, GLint size) {
	// Tell OpenGL where to find our color attribute
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, m_elemPerVert * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(index);
}

void Mesh::useTextureData(GLuint index, GLint size) {
	// Tell OpenGL where to find our texture coordinates
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, m_elemPerVert * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(index);
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
