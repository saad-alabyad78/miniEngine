#pragma once

#include "Window.h"
#include "Camera.h"
#include <ShapeDesigner.h>
#include <Mesh.h>
#include <Shape.h>
#include <Skybox.h>
#include <Light.h>
#include <stair.h>

class Scene {
private:
	Window* window;
	Camera* camera;;
	std::vector<Mesh*>meshes, day_meshes, night_meshes;
	std::vector<Mesh*> trees_meshes;
	std::vector<v4>colliders;
	std::vector<Stairs> stairs;
	std::map<std::string, Mesh*>custom_meshes;
	Renderer* renderer;
	Shape* shape;
	ShapeDesigner* designer;
	Shader* shader, * light_shader;
	Light* light;
	std::vector<SkyBox*> sky;
	int sky_selector;
	bool doorOpen;
	float doorRotate;

public:
	Scene(Window* window, Camera* camera)
	:camera(camera), window(window)
	{
		doorOpen = false;
		doorRotate = 0;
		shape = new Shape();
		renderer = new Renderer();
		designer = new ShapeDesigner();
		shader = new Shader("res/shaders/Texture3.shader");
		light_shader = new Shader("res/shaders/sun.shader");

		light = new Light(camera, night_meshes);

		sky_selector = 0;
		std::string d = "day";
		std::string n = "night";
		sky = {
			new SkyBox(camera, window, d),
			new SkyBox(camera, window, n),
		};
		MakeScene();
	};
	
	~Scene();

	void MakeScene();
	void Input(float &deltaTime, GLFWcursorposfun mouse_callback, std::map<std::string, bool> buttons);
	void Update();

private:
	void player(float scale = 1, v3 position = v3(0, 0, 0), float yRotate = 0.0f);
	void util(float scale = 1, v3 position = v3(0, 0, 0));
	void trees(float scale = 1, v3 position = v3(0, 0, 0));
	void qibali(float scaler=1, v3 position=v3(0,0,0), float yRotate = 0.0f);
	void floor(float scale, v3 position);
	void bstan(float scale, v3 position, float yRotate);
	void mashreb(float scale, v3 position);
	void mosqe(float scale, v3 position);
	void mosqe2(float scale, v3 position);
	void Dome_of_the_Rock(float scaler, v3 position);
	void floorDomeRock(float scaler, v3 position);
	void chainDome(float scaler, v3 position);
	void Rock_Dome(float scaler, v3 position, float yRotate);
	void fences(float scale, v3 position);
};