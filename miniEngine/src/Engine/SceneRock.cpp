#include <Scene.h>


void Scene::Dome_of_the_Rock(float scaler, v3 position) {

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
	 Texture("res/textures/rock_dome/testtt.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
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




	//////////////////////dome of the rock
	shape->setTextures(neckRock_textures);
	mesh = shape->EmptyCircle(scaler * 2.5, scaler * 10, scaler * 10, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(-15, 19, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(dome_textures);
	mesh = shape->EmptyCircle(scaler * 0.75, scaler * 10.75, scaler * 10, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(-15, 17.5 + 4, 0));//17.5+4.375
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	//the dome


	shape->setTextures(dome_textures);
	mesh = shape->Sphere(scaler * 10, scaler * 15, scaler * 15, 3.5);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(-15, 19.5 + 4, 0));//19.5+4.875
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	//the jacket of dome
	shape->setTextures(wood_textures);
	mesh = shape->EmptyCircle(scaler * 1.25, scaler * 30, scaler * 10, 8);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(-15, 14 + 2., 0));//y=9+2.25
	model = rotate(model, radians(90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	//walls
	shape->setTextures(wall_textures3);
	mesh = shape->EmptyCircle(scaler * 7.5, scaler * 31.25, scaler * 30, 8);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(-15, 10, 0));//y=9+2.25
	model = rotate(model, radians(180.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	///////////////////end of the dome of the rock


}

void Scene::floorDomeRock(float scaler, v3 position) {

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
	 Texture("res/textures/rock_dome/testtt.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
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


	//floor
	shape->setTextures(wood_textures3);
	mesh = shape->FilledCube(scaler * 100, scaler * 3, scaler * 100);
	model = translate(mat4(1), position);
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	///////////////////////////////////////////////////////////////////////main steps
	shape->setTextures(wood_textures3);
	mesh = shape->Stairs(scaler * 8, scaler * 3, scaler * 8, scaler * 10);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(0, 0, 108));
	//model = rotate(model, radians(45.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->EmptyCircle(scaler * 4, scaler * 0.5, scaler * 0, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(8, 7, 100));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->EmptyCircle(scaler * 4, scaler * 0.5, scaler * 0, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(4, 7, 100));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->EmptyCircle(scaler * 4, scaler * 0.5, scaler * 0, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(0, 7, 100));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->EmptyCircle(scaler * 4, scaler * 0.5, scaler * 0, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(-4, 7, 100));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->EmptyCircle(scaler * 4, scaler * 0.5, scaler * 0, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(-8, 7, 100));
	mesh->setModel(model);
	this->meshes.push_back(mesh);








}

void Scene::chainDome(float scaler, v3 position) {
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
	 Texture("res/textures/rock_dome/testtt.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
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
	////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////dome of slsla not tested yet

	//inner column
	designer->column(this->meshes, scaler * 0.25, 0, position + 2 * scaler * v3(21 + 2, 4 / 2.0, 0));
	designer->column(this->meshes, scaler * 0.25, 0, position + 2 * scaler * v3(21 + 1, 4 / 2.0, 1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 2 * scaler * v3(21 - 1, 4 / 2.0, 1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 2 * scaler * v3(21 - 1, 4 / 2.0, -1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 2 * scaler * v3(21 + 1, 4 / 2.0, -1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 2 * scaler * v3(21 - 2, 4 / 2.0, 0));
	//outer column
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 + 2, 4 / 6.0, 0));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 + 1.732, 4 / 6.0, 1));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 + 1, 4 / 6.0, 1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 - 1, 4 / 6.0, 1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 - 1.732, 4 / 6.0, 1));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 - 1.732, 4 / 6.0, -1));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 - 1, 4 / 6.0, -1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 - 0, 4 / 6.0, -2));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 + 1, 4 / 6.0, -1.732));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 + 1.732, 4 / 6.0, -1));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 + 0, 4 / 6.0, 2));
	designer->column(this->meshes, scaler * 0.25, 0, position + 6 * scaler * v3(7 - 2, 4 / 6.0, 0));



	//neck of slsla
	shape->setTextures(lightrock_textures);
	mesh = shape->EmptyCircle(scaler * 0.1, scaler * 12.5, scaler * 11.5, 12);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(42, 6.8, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(neck_textures);
	mesh = shape->EmptyCircle(scaler * 0.1, scaler * 12.5, scaler * 7 - 1.75, 12);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(42, 8.8, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(smallWall_textures);
	mesh = shape->EmptyCircle(scaler * 1.5, scaler * 7, scaler * 5, 6);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(42, 10.3, 0));
	model = rotate(model, radians(45.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);
	//small neck
	shape->setTextures(neck_textures);
	mesh = shape->EmptyCircle(scaler * 0.1, scaler * 7, scaler * 4, scaler * 100);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(42, 11.9, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);
	////the dome
	shape->setTextures(slslahdome_textures);
	mesh = shape->Sphere(scaler * 6.2, scaler * 40, scaler * 40, 3.2);
	model = translate(mat4(1), position);
	model = translate(model, scaler * v3(42, 13.2, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);
	////////////////////////////////////////////////////////////end of dome of the chain
	////////////////////////////////////////////////////////////





}

void Scene::Rock_Dome(float scaler, v3 position, float yRotate) {
	designer->Dome_of_the_Rock(meshes, scaler, yRotate, position + scaler * v3(-5, 0, 20));
	v4 rock = v4(position.x + scaler * -5 - scaler * 30, position.z + scaler * 20 - scaler * 30, scaler * 64, scaler * 3);
	v4 rock2 = v4(position.x + scaler * -5 - scaler * 30, position.z + scaler * 20 + scaler * 30, scaler * 64, scaler * 3);
	v4 rock3 = v4(position.x + scaler * -5 + scaler * 30, position.z + scaler * 20 - scaler * 30, scaler * 3, scaler * 64);
	v4 rock4 = v4(position.x + scaler * -5 + scaler * 30, position.z + scaler * 20 + scaler * 30, scaler * 3, scaler * 64);
	colliders.push_back(rock);
	colliders.push_back(rock2);

	designer->Dome_of_the_Chain(meshes, scaler * 1.6, yRotate, position + scaler * v3(60, -1, 20));

	designer->Dome_of_the_Rock_GROUND(meshes, scaler, yRotate - 7, position + scaler * v3(0, 9.5, 0));

	designer->Dome_of_the_Rock_GATE2(meshes, scaler * 1.4, -2.6, position + scaler * v3(74.7, 0.5, -93.5));
	designer->Dome_of_the_Rock_GATE2(meshes, scaler * 1.4, -2.6, position + scaler * v3(-6, 0.5, -95.5));

	designer->Dome_of_the_Rock_GATE2(meshes, scaler * 1.35, 96, position + scaler * v3(-57, 0.5, -108));
	designer->Dome_of_the_Rock_GATE3(meshes, scaler * 1, 93, position + scaler * v3(-48, 2, 33.5));

	designer->Dome_of_the_Rock_GATE4(meshes, scaler * 0.85, 4, position + scaler * v3(15.5, 2.1, 127.5));
	designer->Dome_of_the_Rock_GATE2(meshes, scaler * 1.34, 4, position + scaler * v3(76.7, 1, 130.8));

	designer->Dome_of_the_Rock_GATE4(meshes, scaler * 0.85, -95, position + scaler * v3(94, 2.3, 25));

	designer->Dome_of_the_Rock_Stairs(meshes, scaler * 1.4, 180, position + scaler * v3(0, 6.7, 107));
	designer->idk2(meshes, scaler * 0.5, 180, position + scaler * v3(0, 9.57, 109));

	designer->Dome_of_the_Rock_DOOR2(meshes, scaler * 1.3, 180, position + scaler * v3(-5.2, -1.5, 30));
	designer->Dome_of_the_Rock_DOOR2(meshes, scaler * 1.3, 0, position + scaler * v3(-5.2, -1.5, 10));

	designer->Dome_of_the_Rock_DOOR1(meshes, scaler * 1.3, 90, position + scaler * v3(47, -1.5, 20.2));
	designer->Dome_of_the_Rock_DOOR1(meshes, scaler * 1.3, 90, position + scaler * v3(-15.5, -1.5, 20.2));

	designer->idk2(meshes, scaler * 1.3, 90, position + scaler * v3(-20, 0, -14));
	designer->idk1(meshes, scaler * 1.3, 90, position + scaler * v3(-42, 0.3, -28));

	designer->idk1(meshes, scaler * 1, 90, position + scaler * v3(-40, 1.3, -98));
}
void Scene::fences(float scale, v3 position) {
	Mesh* mesh;
	mat4 model;
	std::vector<Texture> wood_textures =
	{	
		Texture("res/textures/fence.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};

	////////////////inner fence the big gate
	for (int i = 0; i < 33; i++)
	{
		if (i > 14 && i < 18)
		{
			continue;
		}
		designer->BigGate(meshes, scale * 1.5, 0, v3(-192.2 + (i * 12), 4.5 * 1.67, 345));
		designer->BigGate(meshes, scale * 1.5, 0, v3(+192.2 - (i * 12), 4.5 * 1.67, -345));



	}
	for (int i = 0; i < 58; i++)
	{
		designer->BigGate(meshes, scale * 1.5, 90, v3(-190, 4.5 * 1.67, -340 + (i * 12)));
		designer->BigGate(meshes, scale * 1.5, 90, v3(190, 4.5 * 1.67, -340 + (i * 12)));
	}




	//////////////outer fence
	shape->setTextures(wood_textures);
	mesh = shape->FilledCubeTexture(scale * 182 / 2, scale * 4.5 * 1.67, scale * 2, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(-200 + 182 / 2, 6, 360));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->FilledCubeTexture(scale * 182 / 2, scale * 4.5 * 1.67, scale * 2, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(+200 - 182 / 2, 6, 360));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->FilledCubeTexture(scale * 2, scale * 4.5 * 1.67, scale * 362, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(-202, 6, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->FilledCubeTexture(scale * 2, scale * 4.5 * 1.67, scale * 362, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(+202, 6.4, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	/////////////////////////////////////////////////roof of the fence
	shape->setTextures(wood_textures);
	mesh = shape->Square_Repet_Textures(scale * 182 / 2, scale * 9.5, scale * 2, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(+200 - 182 / 2, 13.6, 352.5));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->Square_Repet_Textures(scale * 182 / 2, scale * 9.5, scale * 2, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(-200 + 182 / 2, 13.6, 352.5));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	shape->setTextures(wood_textures);
	mesh = shape->Square_Repet_Textures(scale * 8, scale * 362, scale * 2, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(-200 + 4.2, 13.6, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	shape->setTextures(wood_textures);
	mesh = shape->Square_Repet_Textures(scale * 8, scale * 362, scale * 2, 0.3 / scale);
	model = translate(mat4(1), position);
	model = translate(model, scale * v3(+200 - 4, 14, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	///////////////////big door
	designer->BigGate(meshes, scale * 4.5, 0, position + scale * v3(0, 25.5, 352));
	///////////////////// small rocks on the top of the fence
	for (int i = 0; i < 23; i++)
	{
		shape->setTextures(wood_textures);
		mesh = shape->FilledCube(scale * 2, scale * 2, scale * 2);
		model = translate(mat4(1), position);
		model = translate(model, scale * v3(-202 + (i * 8), 15.5, 360));
		mesh->setModel(model);
		this->meshes.push_back(mesh);

		shape->setTextures(wood_textures);
		mesh = shape->FilledCube(scale * 2, scale * 2, scale * 2);
		model = translate(mat4(1), position);
		model = translate(model, scale * v3(+202 - (i * 8), 15.5, 360));
		mesh->setModel(model);
		this->meshes.push_back(mesh);
	}
	for (int i = 0; i < 90; i++)
	{
		shape->setTextures(wood_textures);
		mesh = shape->FilledCube(scale * 2, scale * 2, scale * 2);
		model = translate(mat4(1), position);
		model = translate(model, scale * v3(+202, 15.5, 360 - (i * 8)));
		mesh->setModel(model);
		this->meshes.push_back(mesh);

		shape->setTextures(wood_textures);
		mesh = shape->FilledCube(scale * 2, scale * 2, scale * 2);
		model = translate(mat4(1), position);
		model = translate(model, scale * v3(-202, 15.5, -360 + (i * 8)));
		mesh->setModel(model);
		this->meshes.push_back(mesh);
	}




}

