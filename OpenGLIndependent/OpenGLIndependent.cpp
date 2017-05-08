// OpenGLIndependent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"

int main()
{
	GLuint vbo;

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	Window window("OpenGL", 800, 600);

	while (!window.IsClosed()) {
		window.clear(0.0f, 0.0f, 0.15f, .8f);

		window.update();
	}
    return 0;
}

