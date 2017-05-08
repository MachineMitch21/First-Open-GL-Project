#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <GL/glew.h>

#define MAX_SHADERS 2
#define ERR_LOG 512

class Shader
{
public:
	Shader(std::vector<std::string> files, std::vector<GLenum> types);
	~Shader();

	void bind();

private:
	GLuint create_program();
	GLuint compile_shader(const std::string& shader_src, GLenum shader_type);
	std::string load_shader(const std::string& filename);

private:
	GLuint m_shaders[MAX_SHADERS];
	GLuint m_program;
	GLint success;
	GLchar err_log[ERR_LOG];
};

