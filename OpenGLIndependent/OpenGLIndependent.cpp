// OpenGLIndependent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Window.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Shader.h"

int main()
{
	Window window("OpenGL", 800, 600);

	Vertex vertices[] = {	Vertex(glm::vec3(0.5f, 0.5f, 0.0f)),
							Vertex(glm::vec3(0.5, -0.5f, 0.0f)),
							Vertex(glm::vec3(-0.5f,	 0.5f, 0.0f)),
							Vertex(glm::vec3(0.5f, -0.5f, 0.0f)),
							Vertex(glm::vec3(-0.5, -0.5f, 0.0f)),
							Vertex(glm::vec3(-0.5f, 0.5f, 0.0f)) };
		
		std::string files[] = { "res\\shader.fs", "res\\shader.vs" };
	GLenum types[] = { GL_FRAGMENT_SHADER, GL_VERTEX_SHADER };

	Shader shader(files, types);
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while (!window.IsClosed()) {
		window.clear(0.0f, 0.0f, 0.15f, .8f);

		shader.bind();
		mesh.draw();

		window.update();
	}
    return 0;
}

