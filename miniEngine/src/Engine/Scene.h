#pragma once

#include "Window.h"
#include "Camera.h"
#include <ShapeDesigner.h>
#include <Mesh.h>
#include <Shape.h>
#include <Skybox.h>
#include <Light.h>


class Scene {
private:
	Window* window;
	Camera* camera;;
	std::vector<Mesh*>meshes, day_meshes, night_meshes;
	std::vector<Mesh*> trees_meshes;
	Renderer* renderer;
	Shape* shape;
	ShapeDesigner* designer;
	Shader* shader, * light_shader;
	Light* light;
	std::vector<SkyBox*> sky;

public:
	Scene(Window* window, Camera* camera)
	:camera(camera), window(window)
	{
		shape = new Shape();
		renderer = new Renderer();
		designer = new ShapeDesigner();

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
	void Input(float &deltaTime, GLFWcursorposfun mouse_callback);
	void Update();

private:

};