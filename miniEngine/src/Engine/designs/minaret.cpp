#include <ShapeDesigner.h>

void ShapeDesigner::Minaret1(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;


	std::map<std::string, std::vector<Texture>>texture =
	{
		{"stone1" ,{Texture("res/textures/stone/1.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),}},
		{"stone2" ,{Texture("res/textures/stone/2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),}}
	};

	v3 center = v3(0, 0, 0);

	//shape->setTextures(texture["stone1"]);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center, v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 20, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(4 * scale, 1.5 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 29, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(1.51 * scale, 20 * scale, 20 * scale, 3.5);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 33.3, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(4.1 * scale, 0.2 * scale, 4.1 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 25, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(4.1 * scale, 0.2 * scale, 4.1 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 29, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(.1 * scale, 0.9 * scale, .1 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 35, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.5 * scale, .4 * scale, 100 * scale, 1.4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 36.3, 0), v3(-75, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.42 * scale, .352 * scale, 100 * scale, 1.6);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 36.35, 0.1), v3(-93, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);


	scale /= 7;

	std::vector<v3>cs =
	{
		v3(22, 190.5, 22),
		v3(22, 190.5, 0),
		v3(22, 190.5, -21.9),

		v3(-22, 190.5, 0),
		v3(-22, 190.5, 22),
		v3(-22, 190.5, -22),

		v3(0, 190.5, 22),
		v3(0, 190.5, -22)

	};

	for (auto& i : cs) {

		center += i;

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


		center -= i;
	}
}

void ShapeDesigner::Minaret1(NoTextureDefaultParameters, mat4 model0)
{
	Mesh* mesh;
	mat4 model;


	std::map<std::string, std::vector<Texture>>texture =
	{
		{"stone1" ,{Texture("res/textures/stone/1.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),}},
		{"stone2" ,{Texture("res/textures/stone/2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),}}
	};

	v3 center = v3(0, 0, 0);

	//shape->setTextures(texture["stone1"]);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel2(scale, positionVec3, Yrotate, center, v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 10, 0), v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 20, 0), v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(4 * scale, 1.5 * scale, 8);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 29, 0), v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(1.51 * scale, 20 * scale, 20 * scale, 3.5);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 33.3, 0), v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(4.1 * scale, 0.2 * scale, 4.1 * scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 25, 0), v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(4.1 * scale, 0.2 * scale, 4.1 * scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 29, 0), v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(.1 * scale, 0.9 * scale, .1 * scale);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 35, 0), v3(0, 0, 0), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.5 * scale, .4 * scale, 100 * scale, 1.4);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 36.3, 0), v3(-75, 0, 90), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.42 * scale, .352 * scale, 100 * scale, 1.6);
	model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 36.35, 0.1), v3(-93, 0, 90), model0);
	mesh->setModel(model);
	meshes.push_back(mesh);


	scale /= 7;

	std::vector<v3>cs =
	{
		v3(22, 190.5, 22),
		v3(22, 190.5, 0),
		v3(22, 190.5, -21.9),

		v3(-22, 190.5, 0),
		v3(-22, 190.5, 22),
		v3(-22, 190.5, -22),

		v3(0, 190.5, 22),
		v3(0, 190.5, -22)

	};

	for (auto& i : cs) {

		center += i;

		mesh = shape->FilledCircle(8.5 * scale, 1 * scale, 100 * scale);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, -9, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, +9, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Sphere(1.6 * scale, 10 * scale, 10 * scale, 5);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, -10.5, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(1.8 * scale, 2.1 * scale, 1.8 * scale);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, -12.5, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, -10.4, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);


		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, -14.1, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.2 * scale, 100 * scale);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 9, 0), v3(0, 0, 0), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Cone(1.7 * scale, 5 * scale, 8);
		model = fastModel2(scale, positionVec3, Yrotate, center + v3(0, 10.6, 0), v3(0, 0, 180), model0);
		mesh->setModel(model);
		meshes.push_back(mesh);


		center -= i;
	}
}

void ShapeDesigner::Minaret2(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	v3 center = v3(0, 0, 0);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center, v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(3 * scale, 5 * scale, 3 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 20, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(4 * scale, 1.5 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 29, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(2 * scale, 3.6 * scale, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 27, 0), v3(0, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(1.4 * scale, 2.6 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 30.4, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(1.51 * scale, 20 * scale, 20 * scale, 3.5);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 33.3, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(3.9 * scale, 0.2 * scale, 3.9 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 25, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(5.35 * scale, 0.25 * scale, 5.35 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 29, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(.1 * scale, 0.9 * scale, .1 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 35, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.5 * scale, .4 * scale, 100 * scale, 1.4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 36.3, 0), v3(-75, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.42 * scale, .352 * scale, 100 * scale, 1.6);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 36.35, 0.1), v3(-93, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);


	scale /= 7;

	std::vector<v3>cs =
	{
		v3(22, 190.5, 22),
		//v3(22, 190.5, 0),
		v3(22, 190.5, -21.9),

		//v3(-22, 190.5, 0),
		v3(-22, 190.5, 22),
		v3(-22, 190.5, -22),

		//v3(0, 190.5, 22),
		//v3(0, 190.5, -22)

	};

	for (auto& i : cs) {

		center += i;

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


		center -= i;
	}
}

void ShapeDesigner::Minaret3(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	v3 center = v3(0, 10, 0);

	mesh = shape->FilledCircle(15 * scale, 1.5 * scale, 50 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(1.5 * scale, 30 * scale, 10 * scale, 3.76);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 14.9, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(0.1 * scale, 3.1 * scale, 15);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 12.6, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(0.26 * scale, 2.8 * scale, 15);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10.19, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(2.7 * scale, 3 * scale, 15);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10.19, 0), v3(180, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(.1 * scale, 0.9 * scale, .1 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 17, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.5 * scale, .4 * scale, 100 * scale, 1.4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 18.3, 0), v3(-75, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(.15 * scale, 0.42 * scale, .352 * scale, 100 * scale, 1.6);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 18.34, 0.1), v3(-93, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	scale /= 11.5;

	std::vector<v3>cs =
	{
		v3(20, 238.5,  20),
		v3(-20, 238.5,  20),
		v3(-20, 238.5, -20),
		v3(20, 238.5, -20),

		v3(0, 238.5,  28),
		v3(0, 238.5, -28),

		v3(28, 238.5,  0),
		v3(-28, 238.5, 0)
	};

	for (auto& i : cs) {

		center += i;

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


		center -= i;
	}


}