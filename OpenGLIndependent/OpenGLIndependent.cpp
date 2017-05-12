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

		GLfloat vert1 [] = {-0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,	};
		GLfloat vert2 [] = { 0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,	};
		GLfloat vert3 [] = { 0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  };
		GLfloat vert4 [] = { 0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  };
		GLfloat vert5 [] = {-0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert6 [] = {-0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,	};
		GLfloat vert7 [] = {-0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,	};
		GLfloat vert8 [] = { 0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  };
		GLfloat vert9 [] = { 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	};
		GLfloat vert10[] = { 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	};
		GLfloat vert11[] = {-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,  };
		GLfloat vert12[] = {-0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,	};
		GLfloat vert13[] = {-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  };
		GLfloat vert14[] = {-0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	};
		GLfloat vert15[] = {-0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert16[] = {-0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert17[] = {-0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,	};
		GLfloat vert18[] = {-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  };
		GLfloat vert19[] = { 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,	};
		GLfloat vert20[] = { 0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  };
		GLfloat vert21[] = { 0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert22[] = { 0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert23[] = { 0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  };
		GLfloat vert24[] = { 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,	};
		GLfloat vert25[] = {-0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert26[] = { 0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,	};
		GLfloat vert27[] = { 0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  };
		GLfloat vert28[] = { 0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  };
		GLfloat vert29[] = {-0.5f,-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,	};
		GLfloat vert30[] = {-0.5f,-0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert31[] = {-0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,	};
		GLfloat vert32[] = { 0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  };
		GLfloat vert33[] = { 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,	};
		GLfloat vert34[] = { 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,	};
		GLfloat vert35[] = {-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  };
		GLfloat vert36[] = {-0.5f, 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f	};

		Vertex vertices[] = {	Vertex(vert1 , 8),
								Vertex(vert2 , 8),
								Vertex(vert3 , 8),
								Vertex(vert4 , 8),
								Vertex(vert5 , 8),
								Vertex(vert6 , 8),
								Vertex(vert7 , 8),
								Vertex(vert8 , 8),
								Vertex(vert9 , 8),
								Vertex(vert10, 8),
								Vertex(vert11, 8),
								Vertex(vert12, 8),
								Vertex(vert13, 8),
								Vertex(vert14, 8),
								Vertex(vert15, 8),
								Vertex(vert16, 8),
								Vertex(vert17, 8),
								Vertex(vert18, 8),
								Vertex(vert19, 8),
								Vertex(vert20, 8),
								Vertex(vert21, 8),
								Vertex(vert22, 8),
								Vertex(vert23, 8),
								Vertex(vert24, 8),
								Vertex(vert25, 8),
								Vertex(vert26, 8),
								Vertex(vert27, 8),
								Vertex(vert28, 8),
								Vertex(vert29, 8),
								Vertex(vert30, 8),
								Vertex(vert31, 8),
								Vertex(vert32, 8),
								Vertex(vert33, 8),
								Vertex(vert34, 8),
								Vertex(vert35, 8),
								Vertex(vert36, 8) };
		
		
		


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

	glEnable(GL_DEPTH_TEST);

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

		if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
			window.close();
		}

		shader.bind();

		/*// Create transformations
		glm::mat4 transform;
		transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
		transform = glm::rotate(transform, (GLfloat)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.0f, 0.0f, 1.0f));

		std::cout << (GLfloat)glfwGetTime() << std::endl;

		// Get matrix's uniform location and set matrix
		GLint transformLoc = glGetUniformLocation(shader.getProgram(), "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));*/

		// Create transformations
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(45.0f, (GLfloat)window.getWidth() / (GLfloat)window.getHeight(), 0.1f, 100.0f);
		// Get their uniform location
		GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
		GLint viewLoc = glGetUniformLocation( shader.getProgram(), "view");
		GLint projLoc = glGetUniformLocation( shader.getProgram(), "projection");
		// Pass them to the shaders
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		mesh.draw();

		window.update();
	}
    return 0;
}

