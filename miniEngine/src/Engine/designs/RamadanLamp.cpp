#include <ShapeDesigner.h>

void ShapeDesigner::RamadanLamp(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;


	std::vector<Texture>sides =
	{
		Texture("res/textures/RamadanLamp/1.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};

	std::vector<Texture>bottom_up =
	{
		Texture("res/textures/woodSpec.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};

	v3 center = v3(0, 20, 0);

	shape->setTextures(sides);

	mesh = shape->FilledCircle(5 * scale, 3.2 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center, v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(bottom_up);

	mesh = shape->Cone(4.5 * scale, 4.7 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center - v3(0, 5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(4.5 * scale, 4.7 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 5, 0), v3(0, 0, 180));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(sides);

	mesh = shape->Sphere(3.4 * scale, 50 * scale, 100 * scale, 5.3);
	model = fastModel(scale, positionVec3, Yrotate, center - v3(0, 3.8, 0), v3(0, 0, 180));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(3.4 * scale, 50 * scale, 100 * scale, 5.3);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 3.8, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	shape->setTextures(bottom_up);

	mesh = shape->Sphere(1.5 * scale, 40 * scale, 100 * scale, 5.3);
	model = fastModel(scale, positionVec3, Yrotate, center - v3(0, 6.3, 0), v3(0, 0, 180));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(1.5 * scale, 40 * scale, 100 * scale, 5.3);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 6.3, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(sides);

	mesh = shape->Cone(0.4 * scale, 2 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 7.5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(0.4 * scale, 2 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center - v3(0, 7.5, 0), v3(0, 0, 180));
	mesh->setModel(model);
	meshes.push_back(mesh);

}
