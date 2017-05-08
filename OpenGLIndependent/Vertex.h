#pragma once

#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3& pos);

	void setPos(glm::vec3 pos);
	void setTexCoord(glm::vec2 coord);
	glm::vec3 getPos();
	glm::vec2 getTexCoord();
	~Vertex();

private:
	glm::vec3 v_pos;
	glm::vec2 t_coord;
};

