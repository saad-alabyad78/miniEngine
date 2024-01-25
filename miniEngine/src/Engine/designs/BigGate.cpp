#include <ShapeDesigner.h>

void ShapeDesigner::BigGate(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::map<std::string, std::vector<Texture>>texture =
	{
		{"stone1" ,{Texture("res/textures/fence.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),}},
		{"stone2" ,{Texture("res/textures/darkrock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),}}
	};

	v3 center = v3(0, 0, 0);
	shape->setTextures(texture["stone1"]);
	mesh = shape->FullGate(4 * scale, 1.4 * scale, 4 * scale, 3.4 * scale, 3.3 * scale, 30 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center, v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(texture["stone2"]);

	mesh = shape->FilledCubeTexture(0.45 * scale, 1.4 * scale, 3 * scale, 1);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(3.58, -3, 0), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(0.45 * scale, 1.4 * scale, 3 * scale, 1);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-3.58, -3, 0), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(0.49 * scale, 1.477 * scale, 0.1 * scale, 1);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(3.55, 0, 0), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(0.49 * scale, 1.477 * scale, 0.1 * scale, 1);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-3.55, 0, 0), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
}
void ShapeDesigner::BigGate2(NoTextureDefaultParameters, mat4 model0)
{
	Mesh* mesh;
	mat4 model;

	std::map<std::string, std::vector<Texture>>texture =
	{
		{"stone1" ,{Texture("res/textures/qibali/stone.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),}},
		{"stone2" ,{Texture("res/textures/qibali/outerwall_qibai.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),}}
	};

	v3 center = v3(0, 0, 0);
	shape->setTextures(texture["stone1"]);
	mesh = shape->FullGate(4 * scale, 1.4 * scale, 4 * scale, 3.4 * scale, 3.3 * scale, 30 * scale);
	model = fastModel2(scale, positionVec3, Yrotate, center, v3(90, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(texture["stone2"]);

	mesh = shape->FilledCubeTexture(0.45 * scale, 1.4 * scale, 3 * scale, 0.25 / scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(3.58, -3, 0), v3(90, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(0.45 * scale, 1.4 * scale, 3 * scale, 0.25 / scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(-3.58, -3, 0), v3(90, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(0.49 * scale, 1.477 * scale, 0.1 * scale, 0.25 / scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(3.55, 0, 0), v3(90, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(0.49 * scale, 1.477 * scale, 0.1 * scale, 0.25 / scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(-3.55, 0, 0), v3(90, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);
}
