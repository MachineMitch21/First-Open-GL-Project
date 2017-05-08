#include "Mesh.h"
#include <iostream>
Mesh::Mesh(Vertex* vertices, unsigned int num_verts)
{
	m_drawCount = num_verts;

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	std::vector<glm::vec3> vert_positions;

	vert_positions.reserve(m_drawCount);

	for (unsigned int i = 0; i < m_drawCount; i++) {
		vert_positions.push_back(vertices[i].getPos());
		std::cout << vertices[i].getPos().x << ", " << vertices[i].getPos().y << ", " << vertices[i].getPos().z << std::endl;
	}

	glGenBuffers(NUM_BUFFERS, &m_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, num_verts * sizeof(vert_positions[0]), &vert_positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindVertexArray(0);
}

void Mesh::draw() {
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
}
