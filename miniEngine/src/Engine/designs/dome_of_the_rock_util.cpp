#include <ShapeDesigner.h>


void ShapeDesigner::Dome_of_the_Rock_DOOR1(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> darkblue_textures =
	{
	 Texture("res/textures/general/darkblue.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/general/rock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	std::vector<Texture> mozaic_textures =
	{
	 Texture("res/textures/general/smallwall.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	shape->setTextures(darkblue_textures);

	mesh = shape->EmptyCircle(scale * 1.3, scale * 2.2, scale * 1.8, scale * 50, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 10, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(1 * scale, 1.3 * scale, 0.29 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(-2.1, 10, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCube(1 * scale, 1.3 * scale, 0.29 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(2.1, 10, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);


	shape->setTextures(lightrock_textures);

	scale /= 5.7;
	v3 center = v3(0, 40.9, -95);

	std::vector<v3>cs =
	{
		v3(12, 0,  0),
		v3(-12, 0,  0),

		v3(12, 0,  10),
		v3(-12, 0,  10),
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

void ShapeDesigner::Dome_of_the_Rock_DOOR2(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> mozaic_textures =
	{
	 Texture("res/textures/general/darkblue.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	std::vector<Texture> test_textures =
	{
	 Texture("res/textures/general/rock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	std::vector<Texture> darkblue_textures =
	{
	 Texture("res/textures/general/smallwall.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	shape->setTextures(mozaic_textures);

	mesh = shape->EmptyCircle(scale * 1.3, scale * 2.2, scale * 1.8, scale * 50, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 10, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);



	shape->setTextures(mozaic_textures);



	mesh = shape->FilledCube(1 * scale, 1.3 * scale, 0.29 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(-2.1, 10, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(mozaic_textures);

	mesh = shape->FilledCube(1 * scale, 1.3 * scale, 0.29 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(2.1, 10, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(mozaic_textures);

	mesh = shape->FilledCube(0.2 * scale, 1.3 * scale, 2.49 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(-4.8, 9.2, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(mozaic_textures);

	mesh = shape->FilledCube(0.2 * scale, 1.3 * scale, 2.49 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(4.8, 9.2, -15.6), v3(0, 90, 90));
	mesh->setModel(model);
	meshes.push_back(mesh);



	shape->setTextures(test_textures);

	scale /= 5.7;
	v3 center = v3(0, 40.9, -95);

	float d = 8, dd = 12.2;

	std::vector<v3>cs =
	{
		v3(12, 0,  0),
		v3(-12, 0,  0),

		v3(12 + d, 0,  0),
		v3(-12 - d, 0,  0),

		v3(12 + d + dd, 0,  0),
		v3(-12 - d - dd, 0,  0),

		v3(12 + d + dd + d, 0,  0),
		v3(-12 - d - dd - d, 0,  0),

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



void ShapeDesigner::Dome_of_the_Rock_GATE2(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;
	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/general/rock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(lightrock_textures);
	v3 center = v3(0, 0, -15);

	std::vector<v3>v =
	{
		v3(0 ,10,0),
		v3(6 ,10,0),
		v3(-6,10,0),
	};
	for (auto& i : v)
	{
		mesh = shape->FullGate(scale * 3, scale * 0.4, scale * 5.8, scale * 2.5, scale * 3.3, 10 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + i, v3(90, 0, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);
	}


	float w = 9.6;
	//right
	mesh = shape->FilledCubeTexture(scale * 0.6, scale * 6.47, scale * 0.6, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w, 9.3, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .8, scale * 3.55, scale * 0.75, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w - 0.3, 6.4, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 1.4, scale * 1.2, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w - 0.3, 10.1, -0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
	//left
	mesh = shape->FilledCubeTexture(scale * 0.6, scale * 6.47, scale * 0.6, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w, 9.3, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .8, scale * 3.55, scale * 0.75, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w + 0.3, 6.4, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 1.4, scale * 1.2, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w + 0.3, 10.1, -0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//c

	std::vector<v3>cs =
	{
		v3(10.45, 24.29, -37.5),
		v3(-10.45, 24.29, -37.5),
	};

	scale /= 3.5;

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

void ShapeDesigner::Dome_of_the_Rock_GATE3(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	v3 center = v3(0, 0, -15);

	std::vector<Texture> anciantstone_textures =
	{
	 Texture("res/textures/general/rock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(anciantstone_textures);
	std::vector<v3>v =
	{
		v3(9 ,10,0),
		v3(3 ,10,0),
		v3(-3 ,10,0),
		v3(-9,10,0),
	};
	for (auto& i : v)
	{
		mesh = shape->FullGate(scale * 3, scale * 0.4, scale * 5.8, scale * 2.5, scale * 3.3, 10 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + i, v3(90, 0, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);
	}


	float w = 12.2;
	//right
	mesh = shape->FilledCubeTexture(scale * 0.6, scale * 6.47, scale * 0.6, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w, 9.3, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .8, scale * 3.55, scale * 0.75, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w - 0.3, 6.4, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 1.4, scale * 1.2, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w - 0.3, 10.1, -0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
	//left
	mesh = shape->FilledCubeTexture(scale * 0.6, scale * 6.47, scale * 0.6, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w, 9.3, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .8, scale * 3.55, scale * 0.75, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w + 0.3, 6.4, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 1.4, scale * 1.2, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w + 0.3, 10.1, -0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//c

	std::vector<v3>cs =
	{
		v3(21, 24.29, -37.5),
		v3(0, 24.29, -37.5),
		v3(-21, 24.29, -37.5),

	};

	scale /= 3.5;

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

void ShapeDesigner::Dome_of_the_Rock_GATE4(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	v3 center = v3(0, 0, -15);

	std::vector<Texture> anciantstone_textures =
	{
	 Texture("res/textures/general/rock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
	 //Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	shape->setTextures(anciantstone_textures);

	std::vector<v3>v =
	{
		v3(12 ,10,0),
		v3(6 ,10,0),
		v3(0,10,0),
		v3(-6 ,10,0),
		v3(-12,10,0),
	};
	for (auto& i : v)
	{
		mesh = shape->FullGate(scale * 3, scale * 0.4, scale * 5.8, scale * 2.5, scale * 3.3, 10 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + i, v3(90, 0, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);
	}



	float w = 15.2;
	//right
	mesh = shape->FilledCubeTexture(scale * 0.6, scale * 6.47, scale * 0.6, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w, 9.3, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .8, scale * 3.55, scale * 0.75, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w - 0.3, 6.4, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 1.4, scale * 1.2, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(w - 0.3, 10.1, -0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
	//left
	mesh = shape->FilledCubeTexture(scale * 0.6, scale * 6.47, scale * 0.6, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w, 9.3, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * .8, scale * 3.55, scale * 0.75, scale);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w + 0.3, 6.4, -0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	mesh = shape->Cone(scale * 1.4, scale * 1.2, 4);
	model = fastModel(scale, positionVec3, Yrotate, center + v3(-w + 0.3, 10.1, -0), v3(180, 45, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//c

	std::vector<v3>cs =
	{
		v3(31.5, 24.29, -37.5),
		v3(10.5, 24.29, -37.5),
		v3(-10.5, 24.29, -37.5),
		v3(-31.5, 24.29, -37.5),

	};

	scale /= 3.5;

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


