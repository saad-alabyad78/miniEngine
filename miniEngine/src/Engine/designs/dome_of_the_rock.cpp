#include <ShapeDesigner.h>

void ShapeDesigner::Dome_of_the_Rock(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> wood_textures =
	{
	 Texture("res/textures/wood.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> neckRock_textures =
	{
	 Texture("res/textures/rock_dome/neckRock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> gold_textures =
	{
	 Texture("res/textures/rock_dome/testt.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> dome_textures =
	{
	 Texture("res/textures/rock_dome/testtt.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> wood_textures3 =
	{
	 Texture("res/textures/wood.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> wall_textures3 =
	{
	 Texture("res/textures/rock_dome/aaaa.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> slslahdome_textures =
	{
	 Texture("res/textures/slslah/gray2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> neck_textures =
	{
	 Texture("res/textures/slslah/grayer.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/rock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> smallWall_textures =
	{
	 Texture("res/textures/slslah/smallwall.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	std::vector<Texture> carpet =
	{
		Texture("res/textures/qibali/carpet.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	//////////////////////dome of the rock
	shape->setTextures(neckRock_textures);
	mesh = shape->EmptyCircle(scale * 2.2, scale * 13, scale * 12.8, scale * 50);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0, 24, 0), v3(0, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->EmptyCircle(scale * 0.8, scale * 13.75, scale * 12.8, scale * 70);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0, 22.5 + 4, 0), v3(0, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->Sphere(scale * 13.5, scale * 15, scale * 15, 3.7);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0, 24.6 + 4, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->EmptyCone(scale * 31.3, scale * 7.5, scale * 6, 8);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0, 17, 0), v3(0, 45 / 2, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	std::vector<std::pair<v3, float> > v =
	{
		{v3(-13.7,24.11  , 0) ,90 },
		{v3(13.7,24.11  ,0) , 90},
		{v3(0  ,24.11  , 13.7) , 0},
		{v3(0  ,24.11  ,-13.7) , 0}
	};
	for (auto& i : v)
	{
		shape->setTextures(dome_textures);
		mesh = shape->FilledCube(2 * scale, 3.2 * scale, 1 * scale);
		model = fastModel(scale, positionVec3, Yrotate, i.first, v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		i.first.y += 2.4;
		if (i.first.x)
			i.first.x += .2 * i.first.x / abs(i.first.x);
		if (i.first.z)
			i.first.z += .2 * i.first.z / abs(i.first.z);

		shape->setTextures(dome_textures);
		mesh = shape->FilledCube(2.5 * scale, 0.8 * scale, 0.9 * scale);
		model = fastModel(scale, positionVec3, Yrotate, i.first, v3(0, i.second, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);
	}


	//the jacket of dome

	shape->setTextures(wall_textures3);
	mesh = shape->EmptyCircle(scale * 7.5, scale * 32, scale * 30, 8);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 12, 0), v3(0, 180 + 45 / 2, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(carpet);
	mesh = shape->FilledCircle(1, scale * 31, 8);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, - 12, 0), v3(0, 180 + 45 / 2, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
	//the top of the dome

	shape->setTextures(dome_textures);
	mesh = shape->Sphere(scale * .4, scale * 5, scale * 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 43, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->Sphere(scale * .4, scale * 5, scale * 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 46, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->Sphere(scale * .5, scale * 5, scale * 20);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 44.5, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->Cone(scale * 0.3, scale * 6, 20 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 42, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->EmptyCircle(scale * 0.25, scale * 1, scale * 0.8, 20 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 48.6, 0), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);



}

void ShapeDesigner::Dome_of_the_Rock_GROUND(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> slslahdome_textures =
	{
	 Texture("res/textures/Dome_Ground/3.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};

	shape->setTextures(slslahdome_textures);

	mesh = shape->theDome_of_the_Rock_GROWND(scale * 5, scale * 5, scale * 5, 0.5);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, -10, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	mesh = shape->FilledStairs(scale * 13, scale * 5, scale * 11.6, 10);
	model = fastModel(scale, positionVec3, Yrotate, v3(-71, -10.5, 45), v3(-0.5, -75, 0));
	//Dome_of_the_Rock_GATE2(meshes, scale, Yrotate - 75, positionVec3 + scale * v3(-71 - sin(radians(-75.0f)) * 13, -5, 45 - cos(radians(-75.0f)) * 11.6));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 13, scale * 0.5, scale * 2, 17);
	model = fastModel(scale, positionVec3, Yrotate, v3(-68, -9.3, 56), v3(90, 0, -8.5));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 14, scale * 0.5, scale * 2, 17);
	model = fastModel(scale, positionVec3, Yrotate, v3(-73.6, -9.3, 33.5), v3(90, 0, -14));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//////////////////////////////////////////////////////////////////////////////////////////

	mesh = shape->FilledStairs(scale * 14, scale * 5, scale * 12, 10);
	model = fastModel(scale, positionVec3, Yrotate, v3(-103, -10, -94), v3(-0.5, -77.5, 0));
	//Dome_of_the_Rock_GATE2(meshes, scale, Yrotate - 77.5, positionVec3 + scale * v3(-103 - sin(radians(-77.5f)) * 14, -5, -94 - cos(radians(-77.5f)) * 12));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 13, scale * 0.5, scale * 2, 18);
	model = fastModel(scale, positionVec3, Yrotate, v3(-99, -8.5, -81.5), v3(90, 0, -9));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 13, scale * 0.5, scale * 2, 18.5);
	model = fastModel(scale, positionVec3, Yrotate, v3(-106, -8.55, -107), v3(90, 0, -8.5));
	mesh->setModel(model);
	meshes.push_back(mesh);

	///////////////////////////////////////////////////////////////////////////////////////////

	mesh = shape->FilledStairs(scale * 14, scale * 5, scale * 10, 10);
	model = fastModel(scale, positionVec3, Yrotate, v3(60, -9.9, -133), v3(0, 185, 0));
	//Dome_of_the_Rock_GATE2(meshes, scale, Yrotate + 185, positionVec3 + scale * v3(60 - sin(radians(185.0f)) * 14, -5, -133 - cos(radians(185.0f)) * 10));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledStairs(scale * 7, scale * 5, scale * 15, 200 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(30, -9.9, -135.1), v3(0, 185, 0));
	//Dome_of_the_Rock_GATE2(meshes, scale, Yrotate + 185, positionVec3 + scale * v3(30 - sin(radians(185.0f)) * 10, 0, -135.1 - cos(radians(185.0f)) * 10));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledStairs(scale * 13, scale * 2.5, scale * 5, 4);
	model = fastModel(scale, positionVec3, Yrotate, v3(-20, -7.4, -120), v3(0, 185, 0));
	//Dome_of_the_Rock_GATE2(meshes, scale, Yrotate + 185, positionVec3 + scale * v3(-20 - sin(radians(185.0f)) * 10, 0, -120.1 - cos(radians(185.0f)) * 10));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledStairs(scale * 13, scale * 2.5, scale * 5, 4);
	model = fastModel(scale, positionVec3, Yrotate, v3(-21.3, -12.2, -135), v3(0, 185, 0));
	//Dome_of_the_Rock_GATE2(meshes, scale, Yrotate + 185, positionVec3 + scale * v3(-21.3 - sin(radians(185.0f)) * 10, 0, -135 - cos(radians(185.0f)) * 10));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * 13, scale * 2.8, scale * 8, 1);
	model = fastModel(scale, positionVec3, Yrotate, v3(-20.05, -12, -122), v3(0, 185, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	/////////////////////////////////////////////////////////////////////////////////////

	mesh = shape->FilledStairs(scale * 13, scale * 5, scale * 11.6, 10);
	model = fastModel(scale, positionVec3, Yrotate, v3(122.1, -10, 13), v3(0, 90, 0));
	//Dome_of_the_Rock_GATE2(meshes, scale, Yrotate + 90, positionVec3 + scale * v3(122.1 - sin(radians(90.0f)) * 10, 0, 13 - cos(radians(90.0f)) * 10));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 12, scale * 0.5, scale * 2, 23);
	model = fastModel(scale, positionVec3, Yrotate, v3(121.5, -9.4, 26), v3(-90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	mesh = shape->Parallelogram(scale * 12, scale * 0.5, scale * 2, 23);
	model = fastModel(scale, positionVec3, Yrotate, v3(121.5, -9.4, 0), v3(-90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	///////////////////////////////////////////////////////////////////////////////////////

	mesh = shape->FilledStairs(scale * 13, scale * 5, scale * 11.6, 10);
	model = fastModel(scale, positionVec3, Yrotate, v3(30, -9.9, 124), v3(0, 10, 0));
	//Dome_of_the_Rock_GATE3(meshes, scale, Yrotate + 10, positionVec3 + scale * v3(30 - sin(radians(10.0f)) * 10, 0, 124 - cos(radians(10.0f)) * 10));
	mesh->setModel(model);
	meshes.push_back(mesh);

mesh = shape->Parallelogram(scale * 12, scale * 0.5, scale * 2, -23);
model = fastModel(scale, positionVec3, Yrotate, v3(42.8, -9.3, 122), v3(90, 0, 81));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->Parallelogram(scale * 12, scale * 0.5, scale * 2, -23);
model = fastModel(scale, positionVec3, Yrotate, v3(17, -9.3, 125.9), v3(90, 0, 80));
mesh->setModel(model);
meshes.push_back(mesh);

////////////////////////////////////////////////////////////////////////////////////////

mesh = shape->FilledStairs(scale * 13, scale * 5, scale * 11.6, 10);
model = fastModel(scale, positionVec3, Yrotate, v3(90, -9.9, 114), v3(0, 10, 0));
//Dome_of_the_Rock_GATE3(meshes, scale, Yrotate + 10, positionVec3 + scale * v3(90 - sin(radians(10.0f)) * 10, 0, 114 - cos(radians(10.0f)) * 10));

mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->Parallelogram(scale * 12, scale * 0.5, scale * 2, -23);
model = fastModel(scale, positionVec3, Yrotate, v3(103, -9.3, 111), v3(90, 0, 81));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->Parallelogram(scale * 12, scale * 0.5, scale * 2, -23);
model = fastModel(scale, positionVec3, Yrotate, v3(77, -9.3, 115.9), v3(90, 0, 81));
mesh->setModel(model);
meshes.push_back(mesh);



//small wall

mesh = shape->FilledCubeTexture(scale * 16, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(9.4, -3.4, -118.6), v3(0, 5.15, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 4.5, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(42.5, -3.4, -121.6), v3(0, 5.15, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 30.6, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(-63, -3.4, -111.9), v3(0, 5.15, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 16.6, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(91.45, -3.4, -126.1), v3(0, 5.15, 0));
mesh->setModel(model);
meshes.push_back(mesh);

////

mesh = shape->FilledCubeTexture(scale * 40.8, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(-25.8, -3.35, +121.7), v3(0, 9.29, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 16.8, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(58.2, -3.35, +107.7), v3(0, 9.29, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 4.5, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(106.43, -3.35, +99.9), v3(0, 9.29, 0));
mesh->setModel(model);
meshes.push_back(mesh);

////

mesh = shape->FilledCubeTexture(scale * 64, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(108.45, -3.35, -63.5), v3(0, 90.7, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 37.2, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(110.1, -3.35, 62.6), v3(0, 90.7, 0));
mesh->setModel(model);
meshes.push_back(mesh);

////


mesh = shape->FilledCubeTexture(scale * 59.1, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(-98, -3.35, -21.7), v3(0, 102, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 35.7, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(-72.7, -3.35, 93), v3(0, 101.4, 0));
mesh->setModel(model);
meshes.push_back(mesh);

////

mesh = shape->FilledCubeTexture(scale * 13, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(-73, -3.35, 32.5), v3(0, 14.5, 0));
mesh->setModel(model);
meshes.push_back(mesh);

mesh = shape->FilledCubeTexture(scale * 12, scale * 1.6, scale * 0.4, 0.3);
model = fastModel(scale, positionVec3, Yrotate, v3(-68.3, -3.35, 56.2), v3(0, 10.3, 0));
mesh->setModel(model);
meshes.push_back(mesh);
}

void ShapeDesigner::Dome_of_the_Rock_Stairs(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> slslahdome_textures =
	{
	 Texture("res/textures/Dome_stairs/1.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};
	shape->setTextures(slslahdome_textures);

	mesh = shape->FilledStairs(scale * 0.9, scale * 1.7, scale * 2.6, 10);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 0, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 0.65, scale * 0.15, scale * 3, 30);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0.77, 0.555, 0), v3(30, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 0.65, scale * 0.15, scale * 3, 30);
	model = fastModel(scale, positionVec3, Yrotate, v3(+0.77, 0.555, 0), v3(30, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 0.3, scale * 0.06, scale * 2.6, 30);
	model = fastModel(scale, positionVec3, Yrotate, v3(-1, -0.1, -0.33), v3(30, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 0.3, scale * 0.06, scale * 2.6, 30);
	model = fastModel(scale, positionVec3, Yrotate, v3(1, -0.1, -0.33), v3(30, 0, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * 0.9, scale * 1.7, scale * 0.7, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 0, -3.1), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FullGate(scale * 0.89, scale * 0.8, scale * 2.7, scale * 0.6, scale * 2.2, scale * 40);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 0.68, -4.5), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .14, scale * .6, scale * .56, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0.76, 2.2, -3.15), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .14, scale * .6, scale * .56, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(+0.76, 2.2, -3.14), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//

	mesh = shape->FilledCubeTexture(scale * 1.3, scale * .1, scale * .9, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, -1.5, 2.7), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * 1.1, scale * 0.3, scale * .5, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 1.3, 3.25), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * 1.2, scale * 0.05, scale * .55, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 1.6, 3.25), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * 1, scale * 2.6, scale * .5, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 0.9, -5.8), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Parallelogram(scale * 0.6, scale * 0.5, scale * 2.2, -40);
	model = fastModel(scale, positionVec3, Yrotate, v3(1.6, -0.5, -5.8), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * 0.12, scale * 0.6, scale * 0, scale * 42, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 1.7, 3.2), v3(90, 90, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * 0.5, scale * 0.07, scale * 0, scale * 42);
	model = fastModel(scale, positionVec3, Yrotate, v3(0.9, 1.7, 3.2), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * 0.5, scale * 0.07, scale * 0, scale * 42);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0.9, 1.7, 3.2), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * 0.13, scale * 0.13, scale * 0, scale * 42);
	model = fastModel(scale, positionVec3, Yrotate, v3(0.9, 2, 3.2), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->EmptyCircle(scale * 0.13, scale * 0.13, scale * 0, scale * 42);
	model = fastModel(scale, positionVec3, Yrotate, v3(-0.9, 2, 3.2), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//c
	std::vector<v3>cs =
	{
	  v3(-5.6, 0, 34),

	  v3(5.6, 0, 34),
	};



	scale /= 10.4;
	v3 center = v3(0, -0.3, 0);
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
	scale *= 10.4;

	//c

	cs =
	{
	  v3(-5.5, 0, -34),
	  v3(-2.5, 0, -34),

	  v3(2.5, 0, -34),
	  v3(5.5, 0, -34),

	  v3(-5.5, 0, -44),
	  v3(-2.5, 0, -44),
	  v3(2.5, 0 , -44),
	  v3(5.5, 0 , -44),
	};



	scale /= 8.6;
	center = v3(0, -4.6, 0);
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
	scale *= 8.6;
}