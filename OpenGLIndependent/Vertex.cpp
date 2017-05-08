#include "Vertex.h"



Vertex::Vertex(const glm::vec3& pos)
{
	setPos(pos);
}

void Vertex::setPos(glm::vec3 pos) {
	v_pos = pos;
}

void Vertex::setTexCoord(glm::vec2 coord) {
	t_coord = coord;
}

glm::vec3 Vertex::getPos() {
	return v_pos;
}

glm::vec2 Vertex::getTexCoord() {
	return t_coord;
}

Vertex::~Vertex()
{
}
