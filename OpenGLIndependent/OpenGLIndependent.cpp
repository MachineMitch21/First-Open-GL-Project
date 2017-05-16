// OpenGLIndependent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Window.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

int main()
{
	Window window("Antisocial Engine", 800, 600);

	Camera camera(&window);

	window.setActiveCamera(&camera);

	//window.setActiveCamera(&camera);

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
		glm::vec3(-3.0f, 1.5f, -12.5f),
		glm::vec3(-1.0f, -0.25f, 0.0f),
		glm::vec3(2.0f, -5.0f, -15.0f),
		glm::vec3(-1.5f, 2.2f, 2.5f),
		glm::vec3(-2.5f, 1.0f, -5.5f),
		glm::vec3(0.0f, 0.0f, 5.0f),
		glm::vec3(-1.0f, 1.5f, 0.0f),
		glm::vec3(3.0f, 1.5f, 12.5f)
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

		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		if (window.isKeyPressed(GLFW_KEY_M)) {
			meshes.push_back(new Mesh(vertices, 36, 8));
		}

		if (window.isKeyPressed(GLFW_KEY_N)) {
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

		if (window.isKeyPressed(GLFW_KEY_LEFT_CONTROL) && window.isKeyPressed(GLFW_KEY_LEFT_SHIFT) && window.isKeyPressed(GLFW_KEY_C)) {
			if (!window.isCursorActive())
				window.setCursor(window.SHOW);
		}else if (window.isKeyPressed(GLFW_KEY_LEFT_CONTROL) && window.isKeyPressed(GLFW_KEY_LEFT_ALT) && window.isKeyPressed(GLFW_KEY_C)) {
			if (window.isCursorActive())
				window.setCursor(window.DISABLE);
		}


		if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
			window.close();
		}

		

		shader.bind();
		

		// Get their uniform location
		GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
		
		
		// Pass them to the shaders
		
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		

		for (GLuint i = 0; i < meshes.size(); i++) {
			meshes[i]->draw(cubePositions[i], shader.getProgram());
		}

		camera.setSpeed(5.0f * deltaTime);

		if(!window.isCursorActive())
			camera.move(shader.getProgram(), (GLfloat)window.getX(), (GLfloat)window.getY());

		window.update();
	}
    return 0;
}

