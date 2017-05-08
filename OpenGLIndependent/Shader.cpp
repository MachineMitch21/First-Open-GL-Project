#include "Shader.h"

Shader::Shader(std::vector<std::string> files, std::vector<GLenum> types)
{
	if (!(files.size() > MAX_SHADERS)) {
		for (int i = 0; i < files.size(); i++) {
			m_shaders[i] = compile_shader(load_shader(files.at(i)), types.at(i));
		}
	}
	else {
		std::cerr << "ERROR: --Only 2 shader types allowed--" << std::endl;
	}

}

void Shader::bind() {
	glUseProgram(m_program);
}

GLuint Shader::create_program() {
	m_program = glCreateProgram();

	//Attach shaders to newly create program and then link everything
	for (int i = 0; i < MAX_SHADERS; i++) {
		glAttachShader(m_program, m_shaders[i]);
	}
	glLinkProgram(m_program);

	glGetProgramiv(m_program, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(m_program, ERR_LOG, NULL, err_log);
		std::cout << "ERROR linking shader program:: " << m_program << " ::\n" << err_log << std::endl;
	}

	return m_program;
}

GLuint Shader::compile_shader(const std::string& shader_src, GLenum shader_type) {
	GLuint shader;
	//We have to convert to a type that OpenGL understands
	const GLchar* const* src = (const GLchar* const*)shader_src.c_str();
	
	//Create the shader and compile it
	shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, src, NULL);
	glCompileShader(shader);

	//Check for compilation errors
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	//If compilation had errors
	if (!success) {
		glGetShaderInfoLog(shader, ERR_LOG, NULL, err_log);
		std::cout << "Error compiling shader::- " << shader << " -::\n" << err_log << std::endl;
	}

	return shader;
}

std::string Shader::load_shader(const std::string& filename){
	std::string line;
	std::ifstream shader_file(filename);
	std::string shader_src;

	if (shader_file.is_open()) {
		while (std::getline(shader_file, line)) {
			shader_src += line;
		}
		shader_file.close();
	}
	else {
		std::cout << "--Unable to load shader file--" << std::endl;
	}

	return shader_src;
}

Shader::~Shader()
{
	for (int i = 0; i < MAX_SHADERS; i++) {
		glDeleteShader(m_shaders[i]);
	}
}
