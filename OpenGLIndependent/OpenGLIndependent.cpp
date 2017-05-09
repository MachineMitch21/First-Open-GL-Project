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

	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};
		
	std::string files[] = { "res\\shader.fs", "res\\shader.vs" };
	GLenum types[] = { GL_FRAGMENT_SHADER, GL_VERTEX_SHADER };

	Shader shader(files, types);
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	//Get the max vertex attributes available to use
	GLint nrAttrs;	
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttrs);

	while (!window.IsClosed()) {
		window.clear(0.0f, 0.0f, 0.15f, .8f);

		if (window.isKeyPressed(GLFW_KEY_W) && window.isKeyPressed(GLFW_KEY_LEFT_CONTROL)) {
			mesh.setDrawMode(GL_LINE);
		}

		if (window.isKeyPressed(GLFW_KEY_S) && window.isKeyPressed(GLFW_KEY_LEFT_CONTROL)) {
			mesh.setDrawMode(GL_FILL);
		}

		shader.bind();
		mesh.draw();

		window.update();
	}
    return 0;
}

