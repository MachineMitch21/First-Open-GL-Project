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

	GLfloat vertices[] = { -0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
							0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
							0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
							-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
							-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f	};



	glm::vec3 cubePositions[] = {
		glm::vec3(1.0f, -0.25f, 0.0f),
		glm::vec3(2.0f, 5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-2.5f, 1.0f, -5.5f),
		glm::vec3(0.0f, 0.0f, -5.0f),
		glm::vec3(-1.0f, 1.5f, 0.0f),
		glm::vec3(-3.0f, 1.5f, -12.5f)
	};
		
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};
		
	std::string files[] = { "res\\shader.fs", "res\\shader.vs" };
	GLenum types[] = { GL_FRAGMENT_SHADER, GL_VERTEX_SHADER };

	Shader shader(files, types);

	/*Mesh cube1(vertices, 36, 8);
	Mesh cube2(vertices, 36, 8);
	Mesh cube3(vertices, 36, 8);
	Mesh cube4(vertices, 36, 8);
	Mesh cube5(vertices, 36, 8);*/

	std::vector<Mesh*> meshes;
	/*meshes.push_back(cube1);
	meshes.push_back(cube2);
	meshes.push_back(cube3);
	meshes.push_back(cube4);
	meshes.push_back(cube5);*/

	Texture texture("res\\bricks.jpg");

	//Get the max vertex attributes available to use
	GLint nrAttrs;	
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttrs);

	glEnable(GL_DEPTH_TEST);

	while (!window.IsClosed()) {
		window.clear(0.2f, 0.3f, 0.3f, 1.0f);

		if (window.isKeyPressed(GLFW_KEY_M)) {
			meshes.push_back(new Mesh(vertices, 36, 8));
		}

		if (window.isKeyPressed(GLFW_KEY_D)) {
			if(meshes.size() > 0)
				meshes.pop_back();
		}

		if (window.isKeyPressed(GLFW_KEY_W) && window.isKeyPressed(GLFW_KEY_LEFT_CONTROL)) {
			for(int i = 0; i < meshes.size(); i++)
				meshes[i]->setDrawMode(GL_LINE);
		}

		if (window.isKeyPressed(GLFW_KEY_S) && window.isKeyPressed(GLFW_KEY_LEFT_CONTROL)) {
			for (int i = 0; i < meshes.size(); i++)
				meshes[i]->setDrawMode(GL_FILL);
		}

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
			std::cout << "Mouse pressed at: " << window.getX() << ", " << window.getY() << std::endl;
		}

		if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
			window.close();
		}

		shader.bind();
		
		glm::mat4 view;
		glm::mat4 projection;
		
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(45.0f, (GLfloat)window.getWidth() / (GLfloat)window.getHeight(), 0.1f, 100.0f);
		// Get their uniform location
		GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
		GLint viewLoc = glGetUniformLocation( shader.getProgram(), "view");
		GLint projLoc = glGetUniformLocation( shader.getProgram(), "projection");
		// Pass them to the shaders
		
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		for (GLuint i = 0; i < meshes.size(); i++) {
			meshes[i]->draw(cubePositions[i], shader.getProgram());
		}

		window.update();
	}
    return 0;
}

