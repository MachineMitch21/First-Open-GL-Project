#include "Window.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

Window::Window(const std::string title, int width, int height)
{
	m_title = title;
	m_width = width;
	m_height = height;

	init_glfw();
	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (m_window == nullptr) {
		std::cerr << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
	}
	
	glfwMakeContextCurrent(m_window);

	GLenum status = glewInit();

	if (status != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
	}
	else {
		std::cout << "GLEW initialized" << std::endl;
	}

	glfwGetFramebufferSize(m_window, &m_width, &m_height);
	glViewport(0, 0, m_width, m_height);

	glfwSetKeyCallback(m_window, key_callback);
}

bool Window::IsClosed() {
	return glfwWindowShouldClose(m_window);
}

void Window::update() {
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

void Window::clear(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::init_glfw() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
}

//Callback functions

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(glfwGetCurrentContext(), GL_TRUE);
}