#include <ShapeDesigner.h>


void ShapeDesigner::column(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture>sides =
	{
	  Texture("res/textures/testSon.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};

	std::vector<Texture>bottom_up =
	{
	  Texture("res/textures/woodSpec.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};

	//shape->setTextures(bottom_up);

	v3 center = v3(10, 10, 10);

	mesh = shape->FilledCircle(8.5 * scale, 1 * scale, 100 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -9, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, +9, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(1.6 * scale, 10 * scale, 10 * scale, 5);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(1.8 * scale, 2.1 * scale, 1.8 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -12.5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.4, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -14.1, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(.5 * scale, 1.2 * scale, 100 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 9, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(1.7 * scale, 5 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10.6, 0), v3(0, 0, 180));
	mesh->setModel(model);
	meshes.push_back(mesh);
}
