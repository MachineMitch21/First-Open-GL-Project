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

	GLfloat vert1[6] = { 0.5f,-0.5f, 0.0f, 1.0f, 0.0f, 0.0f };
	GLfloat vert2[6] = {-0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f };
	GLfloat vert3[6] = { 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f };

	Vertex vertices[] = { Vertex(vert1, 6),
							Vertex(vert2, 6),
							Vertex(vert3, 6) };


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
		window.clear(0.2f, 0.3f, 0.3f, 1.0f);

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

