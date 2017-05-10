#pragma once

#include <gl\glew.h>
#include <string>
#include <iostream>

class Texture
{
public:
	Texture(const std::string& filename);
	~Texture();

	void bind();

private:
	GLuint m_texture;
	int m_width;
	int m_height;
	int m_numComponents;
};

