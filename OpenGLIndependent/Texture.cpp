#include "Texture.h"
#include "stb_image.h"

Texture::Texture(const std::string& filename)
{
	//Prep texture data
	stbi_uc* m_imageData = stbi_load(filename.c_str(), &m_width, &m_height, &m_numComponents, 4);

	if (m_imageData == NULL) {
		std::cerr << "Texture failed to load" << std::endl;
	}

	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	//Setup texture behaviors
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Send texture data to the GPU
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_imageData);

	stbi_image_free(m_imageData);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_texture);
}
