#include <Scene.h>


void Scene::floor(float scale, v3 position) {
	std::vector<Texture>G_textures =
	{
		Texture("res/textures/floor.jpg", "diffuse", 0,GL_RGB, GL_UNSIGNED_BYTE),
	};

	shape->setTextures(G_textures);
	mat4 model = mat4(1.0);


	//Mesh* mesh = shape->Square_Repet_Textures(200,360);

	Mesh* mesh = shape->Square_Repet_Textures(scale * 200, scale * 360, 0.3);
	model = translate(model, scale * position);
	model = translate(model, v3(0, -1.5, -2));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

}


void Scene::bstan(float scale, v3 position, float yRotate) {
	std::vector<Texture>G_textures =
	{
		Texture("res/textures/G.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};
	std::vector<Texture>grass_textures =
	{
		Texture("res/textures/grass2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};
	std::vector<Texture> wood_textures =
	{
		Texture("res/textures/G.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(wood_textures);
	mat4 model = mat4(1);
	mat4 model0 = translate(mat4(1), position);
	model0 = rotate(model0, radians(yRotate), v3(0, 1, 0));



	Mesh* mesh = shape->threeCubes(28, 0.3, 33, 29, 0.3, 32);
	model = model0;
	model = translate(model, v3(20, -1, 10));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	model = rotate(model, radians(-180.0f), v3(0, 0, 1));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->threeCubes(32, 0.3, 22, 31, 0.3, 21);
model = model0;
	model = translate(model, v3(31, -1, -50));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(11, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-1.5, -1, -18));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->threeCubes(58, 0.3, 53, 59, 0.3, 52);
model = model0;
	model = translate(model, v3(-85, -1, -20));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	model = rotate(model, radians(-180.0f), v3(0, 0, 1));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->threeCubes(18, 0.3, 22, 17, 0.3, 23);
model = model0;
	model = translate(model, v3(-85, -1, -40));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	model = rotate(model, radians(-180.0f), v3(0, 0, 1));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(21, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-117, -1, -78));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(21, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-54, -1, -78));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(21, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-117, -1, -58));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(21, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-54, -1, -58));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(10, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-96, -1, -68));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(10, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-75, -1, -68));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->EmptyCube(18, 0.3, 22, 17, 0.3, 23);
model = model0;
	model = translate(model, v3(-120, -1, 80));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	model = rotate(model, radians(-180.0f), v3(0, 0, 1));
	mesh->setModel(model);
	this->meshes.push_back(mesh);




	mesh = shape->EmptyCube(18, 0.3, 22, 17, 0.3, 23);
model = model0;
	model = translate(model, v3(-120, -1, 80));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	model = rotate(model, radians(-180.0f), v3(0, 0, 1));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->EmptyCube(18, 0.3, 22, 17, 0.3, 23);
model = model0;
	model = translate(model, v3(-60, -1, 80));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	model = rotate(model, radians(-180.0f), v3(0, 0, 1));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	//*****************************************
	mesh = shape->threeCubes(10, 0.3, 22, 9, 0.3, 23);
model = model0;
	model = translate(model, v3(-2, -1, 80));
	//model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(10, 0.2, 0.5);
model = model0;
	model = translate(model, v3(18, -1, 57.5));
	//	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(25, 0.2, 0.5);
model = model0;
	model = translate(model, v3(18, -1, 80));
	model = rotate(model, radians(66.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);




	//
	mesh = shape->threeCubes(28, 0.3, 22, 29, 0.3, 23);
model = model0;
	model = translate(model, v3(72, -1, 80));
	model = rotate(model, radians(-180.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(10, 0.2, 0.5);
model = model0;
	model = translate(model, v3(34, -1, 102.5));
	model = rotate(model, radians(-180.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(25, 0.2, 0.5);
model = model0;
	model = translate(model, v3(34, -1, 80));
	model = rotate(model, radians(66.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);
	//

	mesh = shape->threeCubes(18, 0.3, 62, 17, 0.3, 63);
model = model0;
	model = translate(model, v3(90, -1, -22.5));
	//model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(32, 0.2, 0.5);
model = model0;
	model = translate(model, v3(140, -1, -85));
	//	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(70, 0.2, 0.5);
model = model0;
	model = translate(model, v3(140, -1, -22.5));
	model = rotate(model, radians(63.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(32, 0.2, 0.5);
model = model0;
	model = translate(model, v3(160, -1, 40));
	//	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(70, 0.2, 0.5);
model = model0;
	model = translate(model, v3(160, -1, -22.5));
	model = rotate(model, radians(63.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(62, 0.2, 0.5);
model = model0;
	model = translate(model, v3(192, -1, -22));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->threeCubes(15, 0.3, 20, 14, 0.3, 21);
model = model0;
	model = translate(model, v3(150, -1, 72.5));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->threeCubes(12.5, 0.3, 30, 13.5, 0.3, 31);
model = model0;
	model = translate(model, v3(160, -1, 100));
	model = rotate(model, radians(90.0f), v3(0, 1, 0));

	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(10, 0.2, 0.5);
model = model0;
	model = translate(model, v3(180, -1, 88));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->EmptyCube(30, 0.1, 40, 31, 0.3, 41);
model = model0;
	model = translate(model, v3(180, -1, 200));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->EmptyCube(30, 0.1, 33, 31, 0.3, 34);
model = model0;
	model = translate(model, v3(180, -1, 300));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->EmptyCube(30, 0.1, 30, 31, 0.3, 31);
model = model0;
	model = translate(model, v3(180, -1, 380));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->EmptyCube(10, 0.1, 20, 11, 0.3, 21);
model = model0;
	model = translate(model, v3(128, -1, 210));
	model = rotate(model, radians(-1.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->EmptyCube(15, 0.1, 20, 14, 0.3, 21);
model = model0;
	model = translate(model, v3(125, -1, 290));
	model = rotate(model, radians(-1.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->threeCubes(20, 0.3, 40, 21, 0.3, 39);
model = model0;
	model = translate(model, v3(120, -1, 360));
	model = rotate(model, radians(180.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->threeCubes(15, 0.3, 5, 16, 0.3, 6);
model = model0;
	model = translate(model, v3(94, -1, 305));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(40, 0.2, 0.5);
model = model0;
	model = translate(model, v3(88.5, -1, 360));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(6, 0.2, 0.5);
model = model0;

	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->EmptyCube(7, 0.1, 28, 6, 0.3, 29);
model = model0;
	model = translate(model, v3(96, -1, 210));

	mesh->setModel(model);
	this->meshes.push_back(mesh);





	mesh = shape->FilledCube(116, 0.2, 0.5);
model = model0;
	model = translate(model, v3(59, -1, 240));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(116, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-89, -1, 240));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->EmptyCube(17, 0.1, 25, 16, 0.3, 26);
model = model0;
	model = translate(model, v3(110, -1, 440));
	mesh->setModel(model);
	this->meshes.push_back(mesh);





	mesh = shape->FilledCube(22, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-120, -1, 483));
	//	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(40, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-120, -1, 450));
	model = rotate(model, radians(123.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(32, 0.2, 0.5);
model = model0;
	model = translate(model, v3(-142, -1, 450));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->EmptyCube(11, 0.1, 13, 10, 0.3, 14);
model = model0;
	model = translate(model, v3(-70, -1, 396));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->EmptyCube(11, 0.1, 13, 10, 0.3, 14);
model = model0;
	model = translate(model, v3(-50, -1, 396));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->EmptyCube(16, 0.1, 27, 15, 0.3, 28);
model = model0;
	model = translate(model, v3(0, -1, 383));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->EmptyCube(16, 0.1, 27, 15, 0.3, 28);
model = model0;
	model = translate(model, v3(55, -1, 383));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->EmptyCube(6, 0.1, 27, 5, 0.3, 28);
model = model0;
	model = translate(model, v3(65, -1, 328));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->EmptyCube(6, 0.1, 33, 5, 0.3, 32);
model = model0;
	model = translate(model, v3(65, -1, 220));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->EmptyCube(9, 0.1, 33, 10, 0.3, 32);
model = model0;
	model = translate(model, v3(70, -1, 135));
	mesh->setModel(model);
	this->meshes.push_back(mesh);









	shape->setTextures(grass_textures);



	mesh = shape->Square_Repet_Textures2(1,0,0,10, 32);
model = model0;
	model = translate(model, v3(70, -1, 135));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->Square_Repet_Textures2(1,0,0,5, 32);
model = model0;
	model = translate(model, v3(65, -1, 220));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,6, 32);
model = model0;
	model = translate(model, v3(65, -1, 333));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,16, 27);
model = model0;
	model = translate(model, v3(55, -0.9, 383));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,16, 27);
model = model0;
	model = translate(model, v3(0, -1, 383));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,16, 26);
model = model0;
	model = translate(model, v3(110, -1, 440));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->Square_Repet_Textures2(1,0,0,20, 14);
model = model0;
	model = translate(model, v3(-60, -1, 396));
	mesh->setModel(model);
	this->meshes.push_back(mesh);




	mesh = shape->Square_Repet_Textures2(1,0,0,30, 30);
model = model0;
	model = translate(model, v3(180, -1, 380));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,30, 34);
model = model0;
	model = translate(model, v3(180, -1, 300));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,30, 40);
model = model0;
	model = translate(model, v3(180, -1, 200));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->Square_Repet_Textures2(1,0,0,14, 20);
model = model0;
	model = translate(model, v3(125, -1, 290));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,10, 20);
model = model0;
	model = translate(model, v3(128, -1, 210));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,6, 28);
model = model0;
	model = translate(model, v3(96, -1, 210));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,6, 16);
model = model0;
	model = translate(model, v3(94, -1, 306));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,26, 39);
model = model0;
	model = translate(model, v3(114, -1, 360));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,18, 62);
model = model0;
	model = translate(model, v3(90, -1, -22));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,21, 60);
model = model0;
	model = translate(model, v3(31, -1, -22));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,12, 28);
model = model0;
	model = translate(model, v3(-1, -1, 10));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,28, 22);
model = model0;
	model = translate(model, v3(72, -1, 80));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,30, 12);
model = model0;
	model = translate(model, v3(160, -1, 101));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,20, 16);
model = model0;
	model = translate(model, v3(150, -1, 74));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Square_Repet_Textures2(1,0,0,10, 22);
model = model0;
	model = translate(model, v3(-2, -1, 80));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,22, 17);
model = model0;
	model = translate(model, v3(-60, -1, 80));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,22, 17);
model = model0;
	model = translate(model, v3(-120, -1, 80));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->Square_Repet_Textures2(1,0,0,21, 10);
model = model0;
	model = translate(model, v3(-54, -1, -69));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,21, 10);
model = model0;
	model = translate(model, v3(-117, -1, -69));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->Square_Repet_Textures2(1,0,0,15, 18);
model = model0;
	model = translate(model, v3(-48, -1, -40));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,15, 18);
model = model0;
	model = translate(model, v3(-122, -1, -40));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->Square_Repet_Textures2(1,0,0,52, 30);
model = model0;
	model = translate(model, v3(-85, -1, 8));
	mesh->setModel(model);
	this->meshes.push_back(mesh);




	mesh = shape->Triangle(11, 0, 0, 11);
model = model0;
	model = translate(model, v3(8, -1, 50));
	model = rotate(model, radians(-4.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);




}


void Scene::mashreb(float scale, v3 position) {
	std::vector<Texture>G_textures =
	{
		Texture("res/textures/G.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};
	std::vector<Texture> wood_textures =
	{
		Texture("res/textures/darkrock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(wood_textures);
	mat4 model = mat4(1.0);



	Mesh* mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(model, scale * position);
	model = translate(model, v3(0, -3, -2));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, -3, -4));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, -3, -6));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, -3, -8));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, -3, -10));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, -3, -12));
	mesh->setModel(model);
	this->meshes.push_back(mesh);













	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(5, -3, -2));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(5, -3, -4));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(5, -3, -6));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(5, -3, -8));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(5, -3, -10));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(0.2, 0.2, 0.2);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(5, -3, -12));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->threeCubes(8, 1, 3.7, 8, 1, 4);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(2.5, -3, -8));
	model = rotate(model, radians(-90.0f), v3(0, 1, 0));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	colliders.push_back(v4((-1.5 + position.x) * scale, (-14.0f + position.z) * scale, 1.0f * scale, 15.0f * scale));
	colliders.push_back(v4((7 + position.x) * scale, (-14.0f + position.z) * scale, 1.0f * scale, 15.0f * scale));
	colliders.push_back(v4((-1.5 + position.x) * scale, (-16.0f + position.z) * scale, 8.0f * scale, 1.0f * scale));
}


void Scene::mosqe(float scale, v3 position) {
	std::vector<Texture>G_textures =
	{
		Texture("res/textures/G.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};
	std::vector<Texture> wood_textures =
	{
		Texture("res/textures/darkrock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(wood_textures);


	mat4 model = mat4(1.0);




	Mesh* mesh = shape->HalfGate(3, 8, 2, 11);
	model = translate(model, scale * position);
	model = translate(model, v3(0, -3, -2));
	model = rotate(model, radians(90.0f), v3(1, 0, 0));
	mesh->setModel(model);

	this->meshes.push_back(mesh);

	mesh = shape->HalfGate(3, 8, 2, 11);

	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, -3, 10));
	model = rotate(model, radians(90.0f), v3(1, 0, 0));
	mesh->setModel(model);

	this->meshes.push_back(mesh);



	mesh = shape->HalfGate(3, 5, 1, 11);

	model = translate(mat4(1), scale * position);
	model = translate(model, v3(-4, 0, 4));
	model = rotate(model, radians(90.0f), v3(0, 1, 0));
	model = rotate(model, radians(90.0f), v3(1, 0, 0));

	mesh->setModel(model);

	this->meshes.push_back(mesh);


	mesh = shape->HalfGate(3, 5, 1, 11);

	model = translate(mat4(1), scale * position);
	model = translate(model, v3(4, 0, 4));
	model = rotate(model, radians(90.0f), v3(0, 1, 0));
	model = rotate(model, radians(90.0f), v3(1, 0, 0));

	mesh->setModel(model);
	this->meshes.push_back(mesh);



	mesh = shape->FilledCube(1, 4, 2.5);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(4, 1, -1.5));
	mesh->setModel(model);
	this->meshes.push_back(mesh);
	colliders.push_back(v4((-4 + position.x) * scale, (-3.0f + position.z) * scale, 2.0f * scale, 5.0f * scale));


	mesh = shape->FilledCube(1, 4, 2.5);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(-4, 1, -1.5));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	colliders.push_back(v4((-4 + position.x) * scale, (8.0f + position.z) * scale, 2.0f * scale, 5.0f * scale));


	mesh = shape->FilledCube(1, 4, 2.5);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(4, 1, 9.5));
	mesh->setModel(model);
	this->meshes.push_back(mesh);
	colliders.push_back(v4((4 + position.x) * scale, (-3.0f + position.z) * scale, 2.0f * scale, 5.0f * scale));


	mesh = shape->FilledCube(1, 4, 2.5);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(-4, 1, 9.5));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	colliders.push_back(v4((4 + position.x) * scale, (8.0f + position.z) * scale, 2.0f * scale, 5.0f * scale));



	mesh = shape->FilledCube(5, 0.5, 8);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, 5.5, 4));
	mesh->setModel(model);
	this->meshes.push_back(mesh);





	mesh = shape->FilledCircle(1.5, 5.5, 6);

	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, 7, 4));
	mesh->setModel(model);

	this->meshes.push_back(mesh);


	mesh = shape->Sphere(2.5, 55, 5);

	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, 11, 4));
	mesh->setModel(model);

	this->meshes.push_back(mesh);

	mesh = shape->Sphere(0.2, 55, 5);

	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, 14.2, 4));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(0.2, 0.5, 0.1);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(0, 13.5, 4));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

}


void Scene::mosqe2(float scale, v3 position) {
	std::vector<Texture>G_textures =
	{
		Texture("res/textures/mshrb.jpg", "diffuse", 0,GL_RGB, GL_UNSIGNED_BYTE),
	};
	std::vector<Texture> wood_textures =
	{
		Texture("res/textures/woodSpec.png", "specular", 0, GL_RGBA, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(wood_textures);


	mat4 model = mat4(1.0);



	Mesh* mesh = shape->FilledCube(3, 7, 3);
	model = translate(model, scale * position);
	model = translate(model, v3(-125, 0, 70));
	mesh->setModel(model);
	this->meshes.push_back(mesh);


	colliders.push_back(v4((-127.0f + position.x) * scale, (68.0f + position.z) * scale, 6.0f * scale, 6.0f * scale));



	mesh = shape->Sphere(2.5, 22, 5);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(-125, 7, 70));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->Sphere(0.2, 10, 5);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(-125, 10, 70));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCube(0.2, 0.5, 0.1);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(-125, 9.5, 70));
	mesh->setModel(model);
	this->meshes.push_back(mesh);



	std::vector<Texture>grass_textures =
	{
		Texture("res/textures/floor.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};	shape->setTextures(grass_textures);


	mesh = shape->FilledCube(10, -0.5, 10);
	model = translate(mat4(1), scale * position);
	model = translate(model, v3(-125, -2.9, 70));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

}


