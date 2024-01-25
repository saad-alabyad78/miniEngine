#include <ShapeDesigner.h>


void ShapeDesigner::idk1(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> gray_textures =
	{
	 Texture("res/textures/idkcollection/gray2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> grayer_textures =
	{
	 Texture("res/textures/idkcollection/grayer.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/idkcollection/anciantstone2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};
	shape->setTextures(gray_textures);


	v3 center = v3(0, 10, -10);

	mesh = shape->Sphere(4 * scale, 50 * scale, 100 * scale, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	shape->setTextures(grayer_textures);
	mesh = shape->EmptyCircle(0.2 * scale, 4.5 * scale, 4 * scale, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, 22.5, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	shape->setTextures(grayer_textures);

	mesh = shape->Sphere(0.2 * scale, 5 * scale, 5 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 4.55, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);



	mesh = shape->Sphere(0.1 * scale, 5 * scale, 5 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 5.3, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(0.15 * scale, 1.9 * scale, 5 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 4, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(lightrock_textures);
	//
	float c = 1;
	float r = 3.4;
	std::vector<std::pair<v3, float> >v =
	{
		{v3(0, -2, r) , 0},
		{v3(0, -2, -r) , 0},
		{v3(r, -2, 0) , 90},
		{v3(-r, -2, 0) , 90},
		{v3(-r + c, -2, r - c) , 45},
		{v3(r - c, -2, -r + c) , 45},
		{v3(-r + c, -2,  -r + c) , -45},
		{v3(r - c, -2, r - c) , -45}
	};


	for (auto& i : v) {
		mesh = shape->FullGate(1.72 * scale, .75 * scale, 2 * scale, 1.3 * scale, 1.0 * scale, 30 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + i.first, v3(90, 0, i.second));
		mesh->setModel(model);
		meshes.push_back(mesh);
	}

	scale /= 5;

	center += v3(0, 22, -40);

	c *= 5.6 * 2;
	r *= 5.6;
	v =
	{
		{v3(-r + c, -2, r) , 0},
		{v3(+r - c, -2, -r) , 0},
		{v3(r, -2, r - c) , 0},
		{v3(-r, -2, -r + c) , 0},
		{v3(-r , -2, r - c) , 0},
		{v3(r - c, -2, r) , 0},
		{v3(-r + c, -2,  -r) , 0},
		{v3(r , -2, -r + c) , 0}
	};

	for (auto& i : v) {



		center += i.first;

		mesh = shape->FilledCircle(8.5 * scale, 1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -9, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, +9, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Sphere(1.6 * scale, 10 * scale, 10 * scale, 5);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.5, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(1.8 * scale, 2.1 * scale, 1.8 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -12.5, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.4, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);


		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -14.1, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.2 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 9, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Cone(1.7 * scale, 5 * scale, 8);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10.6, 0), v3(0, i.second, 180));
		mesh->setModel(model);
		meshes.push_back(mesh);


		center -= i.first;
	}


}

void ShapeDesigner::idk2(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> gray_textures =
	{
	 Texture("res/textures/idkcollection/gray2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> grayer_textures =
	{
	 Texture("res/textures/idkcollection/grayer.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/idkcollection/anciantstone2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};
	shape->setTextures(grayer_textures);


	v3 center = v3(0, 10, -10);

	mesh = shape->Sphere(2 * scale, 50 * scale, 100 * scale, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	shape->setTextures(grayer_textures);
	mesh = shape->EmptyCircle(0.2 * scale, 4.5 * scale / 2, 4 * scale / 2, 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, 22.5, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(0.2 * scale, 5 * scale, 5 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 2.3, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Sphere(0.1 * scale, 5 * scale, 5 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 2.65, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(0.15 * scale / 2, 1.9 * scale / 2, 5 * scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 2, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(lightrock_textures);
	//
	float c = 1;
	float r = 3.4;
	std::vector<std::pair<v3, float> >v =
	{
		{v3(0	  , -1.2 , r) ,  00},
		{v3(0	  , -1.2 ,-r) ,  00},
		{v3(r	  , -1.2 , 0) ,  90},
		{v3(-r	  , -1.2 , 0) ,  90},
		{v3(-r + c, -1.2 , r - c) ,  45},
		{v3(r - c, -1.2 ,-r + c) ,  45},
		{v3(-r + c, -1.2 ,-r + c) , -45},
		{v3(r - c, -1.2 , r - c) , -45}
	};


	for (auto& i : v) {
		i.first.x /= 2.45;
		i.first.z /= 2.45;
		mesh = shape->FullGate(1.72 * scale / 2, .75 * scale, 2 * scale / 2, 1.3 * scale / 2, 1.0 * scale / 2, 30 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + i.first, v3(90, 0, i.second));
		mesh->setModel(model);
		meshes.push_back(mesh);
	}

	scale /= 5;

	center += v3(0, 22, -40);

	c *= 5.6 * 2;
	r *= 5.6;
	v =
	{
		{v3(-r + c, -2, r) ,  0},
		{v3(+r - c, -2,-r) ,  0},
		{v3(+r    , -2, r - c) ,  0},
		{v3(-r    , -2,-r + c) ,  0},
		{v3(-r    , -2, r - c) ,  0},
		{v3(+r - c, -2, r) ,  0},
		{v3(-r + c, -2,-r) ,  0},
		{v3(+r    , -2,-r + c) ,  0}
	};

	for (auto& i : v) {

		i.first.x /= 2.1;
		i.first.z /= 2.1;
		i.first.y += 3.5;
		center += i.first;

		mesh = shape->FilledCircle(8.5 * scale, 1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -9, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, +9, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Sphere(1.6 * scale, 10 * scale, 10 * scale, 5);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.5, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(1.8 * scale, 2.1 * scale, 1.8 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -12.5, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.4, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);


		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -14.1, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.2 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 9, 0), v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Cone(1.7 * scale, 5 * scale, 8);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10.6, 0), v3(0, i.second, 180));
		mesh->setModel(model);
		meshes.push_back(mesh);


		center -= i.first;
	}


}


void ShapeDesigner::idk3(NoTextureDefaultParameters)
{

	Mesh* mesh;
	mat4 model;

	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/idkcollection/anciantstone2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};
	shape->setTextures(lightrock_textures);

	v3 center = v3(0, 0, 0);

	mesh = shape->FilledCube(scale * 1, scale * 0.17, scale * 1);
	model = fastModel(scale, positionVec3, Yrotate, center, v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);



	mesh = shape->FilledCircle(scale * 0.15, scale * 0.69, scale * 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0.3, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(scale * 0.2, scale * 0.5, scale * 8);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0.6, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(scale * 0.3, scale * 0.2, scale * 0.3);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 1.1, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(scale * 0.47, scale * 0.27, scale * 0.47);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 1.7, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 0.66, scale * 1, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 1.44, 0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 0.4, scale * 0.8, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0.9, 0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
}

void ShapeDesigner::idk3(NoTextureDefaultParameters, mat4 model0)
{

	Mesh* mesh;
	mat4 model;

	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/idkcollection/anciantstone2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};
	shape->setTextures(lightrock_textures);

	v3 center = v3(0, 0, 0);

	mesh = shape->FilledCube(scale * 1, scale * 0.17, scale * 1);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, center, v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(scale * 0.15, scale * 0.69, scale * 8);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, center + v3(0, 0.3, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCircle(scale * 0.2, scale * 0.5, scale * 8);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, center + v3(0, 0.6, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(scale * 0.3, scale * 0.2, scale * 0.3);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, center + v3(0, 1.1, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(scale * 0.47, scale * 0.27, scale * 0.47);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, center + v3(0, 1.7, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 0.66, scale * 1, 4);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, center + v3(0, 1.44, 0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 0.4, scale * 0.8, 4);
	model = fastModel2Copy(model0, scale, positionVec3, Yrotate, center + v3(0, 0.9, 0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
}

void ShapeDesigner::idk4(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	mesh = shape->FilledCube(scale * 2, scale * 2.5, scale * 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	std::vector<std::pair<v3, v3> >v =
	{
		{v3(0,0, 2.3), v3(-90,90,0)},
		{v3(0,0,-2.3), v3(-90,90,0)},
		{v3(2.3,0,0), v3(0,0,-90)},
		{v3(-2.3,0,0), v3(0,0,-90)},
	};
	for (auto& i : v)
	{
		mesh = shape->threeCubes(scale * 2.5, scale * 0.3, scale * 2, scale * 1.6, scale * 0.3, scale * 1.2);
		model = fastModel(scale, positionVec3, Yrotate, i.first, i.second);
		mesh->setModel(model);
		meshes.push_back(mesh);
	}

	mesh = shape->HalfGate(scale * 1.5, scale * 1.65, scale * 0.3, 30 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 0, 3), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


}
