#pragma once

#include<Engine\ShapeDesigner.h>
#include<Shader.h>
#include<Camera.h>
#include<set>


class Light {
private:
	Camera* camera;
public:

	std::string state = "day";
	std::vector<v3>lampsPositions;
	Shader* light_shader;
	std::vector<Mesh*>& night_meshes;
	ShapeDesigner* designer;

	float lampScale;
	float lampRotation;

	Light(Camera*& camera, std::vector<Mesh*>& night_meshes)
		:camera(camera), night_meshes(night_meshes)
	{
		designer = new ShapeDesigner();
	};

	void Update(Shader*& shader)
	{
		if (state == "day")
		{
			Son(shader);
			noFlashLight(camera->Position, camera->Front, shader);
			for (int i = 0; i < lampsPositions.size(); i++) {
				noLamp(lampsPositions[i], shader, std::to_string(i));
			}
		}

		if (state == "night")
		{
			Moon(shader);
			flashLight(camera->Position, camera->Front, shader);
			for (int i = 0; i < lampsPositions.size(); i++) {
				Lamp(lampsPositions[i], shader, std::to_string(i));
			}
		}

	};

	void Son(Shader*& shader) {
		shader->setVec3("son.direction", -v3(1, 1, 1));
		shader->setVec3("son.ambient", v3(0.4, 0.4, 0.4));
		shader->setVec3("son.diffuse", v3(0.9, 0.9, 0.9));
		shader->setVec3("son.specular", v3(0.6, 0.6, 0.26));
		shader->setVec3("viewPos", camera->Position);
		shader->set1f("shininess", 100);
	};

	void Moon(Shader*& shader) {
		shader->setVec3("son.direction", -v3(1, 1, 1));
		shader->setVec3("son.ambient", v3(.01, 0.01, 0.01));
		shader->setVec3("son.diffuse", v3(.13, 0.13, .3));
		shader->setVec3("son.specular", v3(.2, .2, .2));
		shader->setVec3("viewPos", camera->Position);
		shader->set1f("shininess", 100.0);
	};

	void Lamp(v3 lampPos, Shader*& shader, std::string index)
	{
		shader->setVec3(("lamp[" + index + "].position").c_str(), lampPos);
		shader->setVec3(("lamp[" + index + "].ambient").c_str(), v3(0.2, 0.2, .3));
		shader->setVec3(("lamp[" + index + "].diffuse").c_str(), v3(.3, .3, .3));
		shader->setVec3(("lamp[" + index + "].specular").c_str(), v3(0.4, 0.4, 0.42));

		shader->set1f("lamp[" + index + "].constant", 0.2);
		shader->set1f("lamp[" + index + "].linear", 0.01);
		shader->set1f("lamp[" + index + "].quadratic", 0.001);

		shader->setVec3("viewPos", camera->Position);
	};

	void noLamp(v3 lampPos, Shader*& shader, std::string index)
	{
		shader->setVec3(("lamp[" + index + "].position").c_str(), lampPos);
		shader->setVec3(("lamp[" + index + "].ambient").c_str(), v3(0, 0, 0));
		shader->setVec3(("lamp[" + index + "].diffuse").c_str(), v3(0, 0, 0));
		shader->setVec3(("lamp[" + index + "].specular").c_str(), v3(0, 0, 0));

		shader->set1f(("lamp[" + index + "].constant").c_str(), 1e3);
		shader->set1f(("lamp[" + index + "].linear").c_str(), 1e3);
		shader->set1f(("lamp[" + index + "].quadratic").c_str(), 1e3);

		shader->setVec3("viewPos", camera->Position);
	};

	void flashLight(v3 flashPos, v3 flashDir, Shader*& shader)
	{
		shader->setVec3("flash.position", flashPos);
		shader->setVec3("flash.direction", flashDir);

		shader->setVec3("flash.ambient", v3(0.0, 0.0, 0.0));
		shader->setVec3("flash.diffuse", v3(1.2, 1.0, 1.0));
		shader->setVec3("flash.specular", v3(0.2, 0.6, 0.82));

		shader->set1f("flash.constant", 0.6);
		shader->set1f("flash.linear", 0.0001);
		shader->set1f("flash.quadratic", 0.0001);
		shader->set1f("flash.cutOff", static_cast<float>(cos(radians(12.0f))));
		shader->set1f("flash.outerCutOff", static_cast<float>(cos(radians(20.0f))));

		shader->setVec3("viewPos", camera->Position);
	};

	void noFlashLight(v3 flashPos, v3 flashDir, Shader*& shader)
	{
		shader->setVec3("flash.position", flashPos);
		shader->setVec3("flash.direction", flashDir);

		shader->setVec3("flash.ambient", v3(.0, .0, .0));
		shader->setVec3("flash.diffuse", v3(.0, .0, .0));
		shader->setVec3("flash.specular", v3(.0, .0, .0));

		shader->set1f("flash.constant", 1e9);
		shader->set1f("flash.linear", 1e9);
		shader->set1f("flash.quadratic", 1e9);
		shader->set1f("flash.cutOff", static_cast<float>(cos(radians(.0))));
		shader->set1f("flash.outerCutOff", static_cast<float>(cos(radians(.0))));

		shader->setVec3("viewPos", camera->Position);
	};

};