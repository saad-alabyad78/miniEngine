#include <Scene.h>

void Scene::MakeScene()
{
	
};


void Scene::Update()
{
	renderer->Clear();
	
	sky[0]->Draw();
};

void Scene::Input(float& deltaTime, GLFWcursorposfun mouse_callback) {
	//objects input
	

	//sitting input 
	if (window->key(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(window->m_WindowID, true);
	bool tab = window->key(GLFW_KEY_TAB);

	if (tab) {
		glfwSetInputMode(window->m_WindowID, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		glfwSetCursorPosCallback(window->m_WindowID, NULL);
	}
	else {
		glfwSetInputMode(window->m_WindowID, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetCursorPosCallback(window->m_WindowID, mouse_callback);
	}
	//camera input

	if (window->key(GLFW_KEY_W)) {
		camera->ProcessKeyboard(FORWARD, deltaTime);
	}
	else if (window->key(GLFW_KEY_S))
	{
		camera->ProcessKeyboard(BACKWARD, deltaTime);
	}

	if (window->key(GLFW_KEY_A))
	{
		camera->ProcessKeyboard(LEFT, deltaTime);
	}
	else if (window->key(GLFW_KEY_D))
	{
		camera->ProcessKeyboard(RIGHT, deltaTime);
	}
	if (window->key(GLFW_KEY_SPACE))
	{
		camera->ProcessKeyboard(UP, deltaTime);
	}
	if (window->key(GLFW_KEY_LEFT_SHIFT))
	{
		camera->ProcessKeyboard(DOWN, deltaTime);
	}
	
	if (window->key(GLFW_KEY_LEFT_CONTROL))
		camera->MovementSpeed++;
	if (window->key(GLFW_KEY_Q))
		camera->MovementSpeed = 12;

}


Scene::~Scene()
{

};