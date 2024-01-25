#pragma once
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include "Debug.h"


class Window {
private:

public:
	unsigned int WIDTH, HEIGHT;
	GLFWwindow* m_WindowID;
	Window(const unsigned int SCR_WIDTH,const unsigned int SCR_HEIGHT);
	~Window(); 
	void config();
	int isRunning();
	void swapBuffer();
	void pollEvents();
	int key(int KEY);

private:
	GLFWwindow* CreateWindow();
};