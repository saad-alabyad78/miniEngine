#include <ShapeDesigner.h>


void ShapeDesigner::Dome_of_the_Chain(NoTextureDefaultParameters)
{
	Mesh* mesh;
	mat4 model;

	std::vector<Texture> chainWall_textures =
	{
	 Texture("res/textures/slslah/smallwall.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),

	};
	std::vector<Texture> grayer_textures =
	{
	 Texture("res/textures/slslah/grayer.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),

	};

	std::vector<Texture> gray_textures =
	{
	 Texture("res/textures/slslah/gray2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),

	};



	//small wall
	shape->setTextures(chainWall_textures);
	mesh = shape->EmptyCircle(scale * 1, scale * 3, scale * 2.3, 6);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 11, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//ring under the dome 
	shape->setTextures(grayer_textures);
	mesh = shape->EmptyCircle(scale * 0.2, scale * 3.2, scale * 2.3, 6);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 12, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//the dome
	shape->setTextures(grayer_textures);
	mesh = shape->Sphere(scale * 2.6, scale * 40, scale * 80, 4);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 12, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	//roof
	shape->setTextures(gray_textures);
	mesh = shape->EmptyCone(scale * 7.5, scale * 2.6, scale * 0.5, 12);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 9.7, 0), v3(0, -15, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	std::vector<Texture> innerroof_textures =
	{
	 Texture("res/textures/slslah/innerroof.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),

	};
	////under the main roof


	shape->setTextures(innerroof_textures);
	mesh = shape->EmptyCircle(scale * 0.01, scale * 7, scale * 2.4, 40 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 9.7, 0), v3(0, -15, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	std::vector<Texture> lightrock_textures =
	{
	 Texture("res/textures/slslah/rock.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),

	};

	//inner ring for the culomn
	shape->setTextures(lightrock_textures);
	mesh = shape->EmptyCircle(scale * 0.1, scale * 2.7, scale * 2.4, 6);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 8, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	//outer ring for the culomn
	shape->setTextures(lightrock_textures);
	mesh = shape->EmptyCircle(scale * 0.1, scale * 6.7, scale * 5.5, 12);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 8.2, 0), v3(0, -15, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	std::vector<Texture> kantra_textures =
	{
	 Texture("res/textures/slslah/kantra.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),

	};
	std::vector<Texture> iron_textures =
	{
	 Texture("res/textures/slslah/iron.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),

	};
	std::vector<Texture> oldiron_textures =
	{
	 Texture("res/textures/slslah/oldiron.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),

	};


	//top of the dome
	shape->setTextures(iron_textures);
	mesh = shape->Sphere(scale * .1, scale * 15, scale * 15);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 14.8, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(iron_textures);
	mesh = shape->Sphere(scale * .1, scale * 15, scale * 15);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 15.4, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(iron_textures);
	mesh = shape->Sphere(scale * .13, scale * 15, scale * 15);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 15.1, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(iron_textures);
	mesh = shape->Cone(scale * 0.05, scale * 1.2, 13 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 14.6, 0), v3(0, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);

	shape->setTextures(iron_textures);
	mesh = shape->EmptyCircle(scale * 0.04, scale * .3, scale * 0.24, 15 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 16, 0), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
	////end of the top of the dome

	std::vector<Texture> wallstone_textures =
	{
	 Texture("res/textures/slslah/wallstone.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),

	};

	//mohrab
	shape->setTextures(wallstone_textures);
	mesh = shape->FullGate(scale * 1.3, scale * 0.4, scale * 4.5, scale * 0.9, scale * 3.7, 15 * scale);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 3.6, 5.7), v3(90, 0, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	shape->setTextures(wallstone_textures);
	mesh = shape->EmptyCircle(scale * 1.6, scale * 0.9, 0.8, 40 * scale, 1.6);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 5.2, 5.8), v3(0, -90, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);


	shape->setTextures(wallstone_textures);
	mesh = shape->Sphere(scale * 0.9, 20 * scale, 20 * scale, 4, 2);
	model = fastModel(scale, positionVec3, Yrotate, v3(0, 6.8, 5.8), v3(0, -90, 0));
	mesh->setModel(model);
	meshes.push_back(mesh);
	//the end of the mahrab
	shape->setTextures(kantra_textures);
	//in
	v3 trans = v3(0, 8.1, 0);
	v3 rot = v3(90, 0, 0);
	std::vector<std::pair<v3, v3> >v =
	{
		{v3(-2.26, 0, 0) , v3(0, 0, 90)},
		{v3(+2.26, 0, 0) , v3(0, 0, -90)},

		{v3(-1.1, 0, +2) , v3(0, 0, 30)},
		{v3(+1.1, 0, +2) , v3(0, 0, -30)},

		{v3(+1.1, 0, -2) , v3(0, 0, 30)},
		{v3(-1.1, 0, -2) , v3(0, 0, -30)},

	};
	for (auto& i : v)
	{
		mesh = shape->FullGate(scale * 1.5, scale * 0.33, scale * 2.3, scale * 1, scale * 0.7, 30 * scale);
		model = fastModel(scale, positionVec3, Yrotate, trans + i.first, rot + i.second);
		mesh->setModel(model);
		meshes.push_back(mesh);
	}

	trans = v3(0, 8.1, 0);
	rot = v3(90, 0, 0);
	//here the z value will rotate arround the y
	v =
	{
		{v3(0., 0, 6) , v3(0, 0, 0)},
		{v3(0., 0, -6) , v3(0, 0, 0)},

		{v3(-3.15, 0, 5.15) , v3(0, 0, 30)},
		{v3(3.15, 0, 5.15) , v3(0, 0, -30)},

		{v3(-3.15, 0, -5.15) , v3(0, 0, -30)},
		{v3(3.15, 0, -5.15) , v3(0, 0, 30)},

		{v3(-5.15, 0, 3.15) , v3(0, 0, 60)},
		{v3(-5.15, 0, -3.15) , v3(0, 0, -60)},

		{v3(5.15, 0, -3.15) , v3(0, 0, 60)},
		{v3(5.15, 0, 3.15) , v3(0, 0, -60)},

		{v3(6, 0, 0) , v3(0, 0, 90)},
		{v3(-6., 0, 0) , v3(0, 0, 90)},
	};
	shape->setTextures(kantra_textures);
	for (auto& i : v)
	{
		mesh = shape->FullGate(scale * 1.81, scale * 0.4, scale * 1.5, scale * 1.3, scale * 0.9, 30 * scale);
		model = fastModel(scale, positionVec3, Yrotate, trans + i.first, rot + i.second);
		mesh->setModel(model);
		meshes.push_back(mesh);
	}






	shape->setTextures(lightrock_textures);

	scale /= 6;


	v =
	{
		//in
		{v3(0.,    34, 15) , v3(0, 0, 0)},
		{v3(0.,    34, -15) , v3(0, 0, 0)},
		{v3(-12.5, 34, -7.5) , v3(0, 0, 0)},
		{v3(+12.5, 34, -7.5) , v3(0, 0, 0)},
		{v3(-12.5, 34, +7.5) , v3(0, 0, 0)},
		{v3(+12.5, 34, +7.5) , v3(0, 0, 0)},
		//out
		{v3(9.5, 34, 34) , v3(0, 0, 0)},
		{v3(9.5, 34, -34) , v3(0, 0, 0)},

		{v3(-9.5, 34, 34) , v3(0, 0, 0)},
		{v3(-9.5, 34, -34) , v3(0, 0, 0)},

		{v3(34, 34,  9.5) , v3(0, 0, 0)},
		{v3(34, 34, -9.5) , v3(0, 0, 0)},

		{v3(-34, 34,  9.5) , v3(0, 0, 0)},
		{v3(-34, 34, -9.5) , v3(0, 0, 0)},

		{v3(25, 34, 25) , v3(0, 0, 0)},
		{v3(25, 34,  -25) , v3(0, 0, 0)},
		{v3(-25, 34, -25) , v3(0, 0, 0)},
		{v3(-25, 34, 25) , v3(0, 0, 0)},

	};
	for (auto& i : v)
	{
		i.first.y += 3.8;
		v3 center = i.first;

		mesh = shape->FilledCircle(8.5 * scale, 1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 0, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -9, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.1 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, +9, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Sphere(1.6 * scale, 10 * scale, 10 * scale, 5);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.5, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(1.8 * scale, 2.1 * scale, 1.8 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -12.5, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -10.4, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);


		mesh = shape->FilledCube(2 * scale, .6 * scale, 2 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, -14.1, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->FilledCircle(.5 * scale, 1.2 * scale, 100 * scale);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 9, 0), v3(0, i.second.y, 0));
		mesh->setModel(model);
		meshes.push_back(mesh);

		mesh = shape->Cone(1.7 * scale, 5 * scale, 8);
		model = fastModel(scale, positionVec3, Yrotate, center + v3(0, 10.6, 0), v3(0, i.second.y, 180));
		mesh->setModel(model);
		meshes.push_back(mesh);

	}


}


