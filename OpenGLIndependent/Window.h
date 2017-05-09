#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

class Window
{
public:
	Window(const std::string title, int width, int height);
	~Window();

	bool IsClosed();
	void update();
	void clear(float r, float g, float b, float a);
	
	bool isKeyPressed(unsigned int keycode);
	bool isMouseButtonPressed(unsigned int button);

private:
	void init_glfw();
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	
private:
	GLFWwindow* m_window;
	int m_height;
	int m_width;
	std::string m_title;
	static bool	m_keys[MAX_KEYS];
	static bool	m_buttons[MAX_MOUSE_BUTTONS];
	static double mx, my;
};

