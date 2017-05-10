// OpenGLIndependent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Window.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

int main()
{
	Window window("Antisocial Engine", 800, 600);

	GLfloat vert1[] = {  0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat vert2[] = {  0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
	GLfloat vert3[] = { -0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	GLfloat vert4[] = { -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat vert5[] = {  0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat vert6[] = { -0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f };

	Vertex vertices[] = {	Vertex(vert1, 8),
							Vertex(vert2, 8),
							Vertex(vert3, 8),
							Vertex(vert4, 8),
							Vertex(vert5, 8),
							Vertex(vert6, 8)	};


	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};
		
	std::string files[] = { "res\\shader.fs", "res\\shader.vs" };
	GLenum types[] = { GL_FRAGMENT_SHADER, GL_VERTEX_SHADER };

	Shader shader(files, types);

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Texture texture("res\\bricks.jpg");

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

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
			std::cout << "Mouse pressed at: " << window.getX() << ", " << window.getY() << std::endl;
		}

		shader.bind();
		mesh.draw();

		window.update();
	}
    return 0;
}

