#include "Window.h"
#include <stdio.h>
#include <iostream>

Window::Window(const unsigned int SCR_HEIGHT , const unsigned int SCR_WIDTH)
	:HEIGHT(SCR_HEIGHT) , WIDTH(SCR_WIDTH)
{
	this->m_WindowID =  this->CreateWindow();

	if (!this->m_WindowID) {
		std::cout << "window could not be created " << std::endl;
		std::cin.get();
		ASSERT(false);
	}
};

Window::~Window()
{

}

int Window::isRunning() 
{
	return glfwWindowShouldClose(this->m_WindowID) - 1;
}

int Window::key(int KEY)
{
	return glfwGetKey(this->m_WindowID, KEY) == GLFW_PRESS; 
}

void Window::swapBuffer()
{
	glfwSwapBuffers(this->m_WindowID);
}
void Window::pollEvents()
{
	glfwPollEvents();
}


// configure global opengl state
// -----------------------------

void Window::config() {
	GlCall(glfwSwapInterval(3));
	GlCall(glEnable(GL_DEPTH_TEST));
	//glDepthFunc(GL_ALWAYS);

	GlCall(glEnable(GL_BLEND));
	GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

GLFWwindow* Window::CreateWindow()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW\n" << std::endl ;
		return nullptr;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(this->WIDTH, this->HEIGHT, "hello saad", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" << std::endl;
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW\n" << std::endl ;
		glfwTerminate();
		return nullptr;
	}

	std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

	return window;
};