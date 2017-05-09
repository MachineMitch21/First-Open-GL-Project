#include "Window.h"

bool Window::m_keys[MAX_KEYS];
bool Window::m_buttons[MAX_MOUSE_BUTTONS];
double Window::mx;
double Window::my;

Window::Window(const std::string title, int width, int height)
{
	m_title = title;
	m_width = width;
	m_height = height;

	for (int i = 0; i < MAX_KEYS; i++) {
		m_keys[i] = false;
	}

	for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
		m_buttons[i] = false;
	}

	if (!init())
		glfwTerminate();

}

bool Window::IsClosed() {
	return glfwWindowShouldClose(m_window);
}

bool Window::isKeyPressed(unsigned int keycode) {

	if (keycode >= MAX_KEYS) {
		return false;
	}
	return m_keys[keycode];
}

bool Window::isMouseButtonPressed(unsigned int button) {
	if (button >= MAX_MOUSE_BUTTONS) {
		return false;
	}
	return m_buttons[button];
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

bool Window::init() {
	bool isInitialized = true;
	GLenum status;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);

	if (m_window == nullptr) {
		std::cerr << "Failed to create GLFW window!" << std::endl;
		isInitialized = false;
	}

	glfwMakeContextCurrent(m_window);
	glViewport(0, 0, m_width, m_height);

	status = glewInit();

	if (status != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		isInitialized = false;
	}

	glfwGetFramebufferSize(m_window, &m_width, &m_height);
	glfwSetKeyCallback(m_window, key_callback);
	glfwSetWindowUserPointer(m_window, this);
	
	return isInitialized;
}

//Callback functions

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_keys[key] = (action != GLFW_RELEASE);
}