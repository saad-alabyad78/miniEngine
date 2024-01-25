#include <ShapeDesigner.h>

void ShapeDesigner::Qibali_Dome_for_abd(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> slslahdome_textures =
	{
	 Texture("res/textures/slslah/gray2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(slslahdome_textures);

	mesh = shape->Sphere(scale * 5, scale * 40, 100 * scale, 3.6);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCone(scale * 5.6, scale * 4.9, scale * 1, 100 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, -1.8, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * 1.1, scale * 5.2, scale * 5, 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, -2.5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(scale * 0.15, scale * 20, scale * 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 6.45, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(scale * 0.15, scale * 20, scale * 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 5.45, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(scale * 0.25, scale * 20, scale * 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 5.95, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 0.1, scale * 2, 20 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * .06, scale * .4, scale * .3, 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 7.2, 0), v3(0, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);
}
void ShapeDesigner::Qibali_Dome_for_abd(NoTextureDefaultParameters, mat4 model0)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> slslahdome_textures =
	{
	 Texture("res/textures/slslah/gray2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(slslahdome_textures);

	mesh = shape->Sphere(scale * 5, scale * 40, 100 * scale, 3.6);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCone(scale * 5.6, scale * 4.9, scale * 1, 100 * scale);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, -1.8, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * 1.1, scale * 5.2, scale * 5, 20);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, -2.5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(scale * 0.15, scale * 20, scale * 20);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, 6.45, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(scale * 0.15, scale * 20, scale * 20);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, 5.45, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(scale * 0.25, scale * 20, scale * 20);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, 5.95, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 0.1, scale * 2, 20 * scale);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, 5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * .06, scale * .4, scale * .3, 20);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, v3(0, 7.2, 0), v3(0, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);
}