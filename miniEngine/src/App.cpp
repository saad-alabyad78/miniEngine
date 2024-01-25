#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Window.h"
#include <Scene.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw_gl3.h>
#include <set>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


// settings
const unsigned int SCR_WIDTH = 1600 * 0.8;
const unsigned int SCR_HEIGHT = 900* 0.8;

// camera
Camera *camera = new Camera(v3(-5, 7, 0));
float lastX = (float)SCR_WIDTH;
float lastY = (float)SCR_HEIGHT;
bool firstMouse = true;

Window *window = new Window(SCR_HEIGHT, SCR_WIDTH);
Scene* scene = new Scene(window,camera);


// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main() {

	glfwSetFramebufferSizeCallback(window->m_WindowID, framebuffer_size_callback);
	glfwSetCursorPosCallback(window->m_WindowID, mouse_callback);
	glfwSetScrollCallback(window->m_WindowID, scroll_callback);

	window->config();
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window->m_WindowID, GLFW_STICKY_KEYS, GL_TRUE);
	// tell GLFW to capture our mouse
	glfwSetInputMode(window->m_WindowID, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window->m_WindowID, true);
	ImGui::StyleColorsClassic();

	map<string, bool> switches{};
	switches["fps"] = true;
	switches["night"] = false;
	switches["door"] = false;

	while (window->isRunning()) {
		// per-frame time logic
		// --------------------
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		ImGui_ImplGlfwGL3_NewFrame();

		map<string, bool> buttons{};

		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Text("Press 'Tab' to show cursor");
		if (ImGui::Button("Dome of The Rock", ImVec2(200.0f, 70.0f))) {
			buttons["po1"] = true;
		}
		if (ImGui::Button("Qibli Mosque", ImVec2(200.0f, 70.0f))) {
			buttons["po2"] = true;
		}
		if (ImGui::Button("Sky View", ImVec2(200.0f, 70.0f))) {
			buttons["po3"] = true;
		}
		if (ImGui::RadioButton("First Person", switches["fps"]) || window->key(GLFW_KEY_F5)) {
			switches["fps"] = !switches["fps"];
		}
		buttons["fps"] = switches["fps"];
		if (ImGui::RadioButton("Night Mode", switches["night"])) {
			switches["night"] = !switches["night"];
			if (switches["night"]) {
				buttons["moon"] = true;
			}
			else {
				buttons["son"] = true;
			}
		}
		if (ImGui::RadioButton("Qibli Door", switches["door"]) || window->key(GLFW_KEY_E)) {
			switches["door"] = !switches["door"];
			if (switches["door"]) {
				buttons["d_open"] = true;
			}
			else {
				buttons["d_close"] = true;
			}
		}

		scene->Input(deltaTime, mouse_callback, buttons);
		scene->Update();

		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		window->swapBuffer();
		window->pollEvents();
	}
	return 0;
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera->ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera->ProcessMouseScroll(static_cast<float>(yoffset));
}



