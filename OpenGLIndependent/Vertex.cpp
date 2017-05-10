#include "Vertex.h"



Vertex::Vertex(GLfloat* vertex_data, unsigned int element_count)
{
	m_vertexData = vertex_data;
	m_elemCount = element_count;
}

GLfloat* Vertex::getData() {
	return m_vertexData;
}

unsigned int Vertex::getElemCount() {
	return m_elemCount;
}

Vertex::~Vertex()
{
}
