#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Window
{
public:
	Window(const std::string title, int width, int height);
	~Window();

	bool IsClosed();
	void update();
	void clear(float r, float g, float b, float a);

private:
	void init_glfw();
	
private:
	GLFWwindow* m_window;
	int m_height;
	int m_width;
	std::string m_title;
};

