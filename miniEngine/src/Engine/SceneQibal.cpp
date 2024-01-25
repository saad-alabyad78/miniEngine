#include <Scene.h>

void Scene::qibali(float scale, v3 position, float yRotate) {
	std::vector<Texture> outerwall_qibai_textures =
	{
		Texture("res/textures/qibali/outerwall_qibai.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> window =
	{
		Texture("res/textures/qibali/outerwall_qibai_window.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	std::vector<Texture> door2 =
	{
		Texture("res/textures/qibali/door2.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> door1Wall =
	{
		Texture("res/textures/qibali/door1Wall.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> roof =
	{
		Texture("res/textures/qibali/roof.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> roof2 =
	{
		Texture("res/textures/qibali/roof2.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> inner_roof =
	{
		Texture("res/textures/qibali/pattern1.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> inner_roof2 =
	{
		Texture("res/textures/qibali/pattern2.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> carpet =
	{
		Texture("res/textures/qibali/carpet.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	shape->setTextures(outerwall_qibai_textures);
	Mesh* mesh;


	//
	mat4 model = mat4(1.0);
	model = translate(model, scale * position); //x = 0 start
	model = rotate(model, radians(yRotate), v3(0, 1, 0));
	//right wall ------------------------------------------------------------------------
	/*{
		mesh = shape->FilledCubeTexture(scale * 13.4, scale * 10, scale * 2, 1.0f / (scale * 8));
		model = translate(model, v3(scale * 13.4, 0, 0));
		mesh->setModel(model);
		this->meshes.push_back(mesh);
	}*/

	//mesh = shape->FilledCubeTexture(scale * 6.7, scale * 10, scale * 2, 1.0f / (scale * 8));
	//mat4 model0 = translate(model, scale * v3(6.7, 0, 0));
	//mesh->setModel(model0);
	//this->meshes.push_back(mesh);
	model = translate(model, v3(scale * (13.4 + 6.7), 0, scale * 2));
	mat4 model_roof = translate(model, v3(scale * (-5.5), scale * 10, -scale * 19));



	shape->setTextures(outerwall_qibai_textures);
	model = translate(model, v3(-scale * (13.4 + 6), 0, - scale * 2));
	mat4 model_window = model;

	for (int i = 0; i < 7; i++) {
		model = translate(model, v3(scale * 9, 0, 0));
		model = translate(model, v3(scale * 9, 0, 0));
	}

	{
		{
			shape->setTextures(inner_roof);
			mesh = shape->FilledCubeTexture(scale * 56, 0, scale * 17, 0.4 / scale);
			mat4 model1 = translate(model_roof, v3(scale * 56, -scale * 0.05, 0));
			mesh->setModel(model1);
			this->meshes.push_back(mesh);

		}
		shape->setTextures(roof2);
		for (int i = 0; i < 7; i++) {
			model_roof = translate(model_roof, v3(scale * 8, 0, 0));
			mesh = shape->Square(scale * 8, scale * 17);
			mesh->setModel(model_roof);
			this->meshes.push_back(mesh);
			model_roof = translate(model_roof, v3(scale * 8, 0, 0));
		}
		shape->setTextures(outerwall_qibai_textures);
	}


	shape->setTextures(outerwall_qibai_textures);
	mesh = shape->FilledCubeTexture(scale * 20, scale * 10, scale * 2, 1.0f / (scale * 8));
	model = translate(model, v3(scale * 20, 0, -scale * 2));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	{
		shape->setTextures(inner_roof);
		mat4 model0 = translate(model, v3(- scale * 2, scale * 10, -scale * 17));
		mesh = shape->FilledCubeTexture(scale * 18, 0, scale * 15, 0.4 / scale);
		model0 = translate(model0, v3(scale * 0, -scale * 0.05, 0));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		shape->setTextures(roof2);
		mesh = shape->FilledCubeTexture(scale * 18, 0, scale * 15, 0.177 / scale);
		model0 = translate(model0, v3(0, scale * 0.05, 0));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);
	}
	shape->setTextures(outerwall_qibai_textures);



	{//side building
		mat4 model0 = translate(model, v3(0, -scale * 5, scale * 60));
		mesh = shape->FilledCubeTexture(scale * 19, scale * 5, scale * 60, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		model0 = translate(model0, v3(0, 0, scale * 40));
		for (int i = 0; i < 6; i++) {
			designer->idk3(meshes, scale * 3, 0, v3(- scale * (30 + i*20), - scale * 5, - scale * 20), model0);
		}
		for (int i = 0; i < 6; i++) {
			designer->idk3(meshes, scale * 3, 0, v3(- scale * (30 + i*20), -scale * 5, scale * 5), model0);
		}
		//for (int i = 0; i < 3; i++) {
		//	designer->idk3(meshes, scale * 3, 0, v3(- scale * (50 + i*40), -scale * 5, scale * 5), model0);
		//}

		model0 = translate(model0, v3(0, 0, scale * 20));
		designer->Minaret1(meshes, scale * 3, 0, v3(0,0,scale * 5), model0);


		model0 = translate(model0, v3(-scale * (70 - 19), 0, scale * 30));
		mesh = shape->FilledCubeTexture(scale * 70, scale * 5, scale * 30, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);
	}

	model = translate(model, v3(scale * 19, 0, 0));
	//back wall ------------------------------------------------------------------------
	float backLength;
	{
		//poles
		//1
		float temp = 12 + 4;
		float length1 = temp;
		mat4 model0 = translate(model, v3(0, scale * 5, -scale * temp));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 5, scale * 2, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//2
		temp = 12 + 4;
		length1 += temp;
		model0 = translate(model0, v3(0, scale * 3, -scale * temp));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 8, scale * 2, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//3
		temp = 12 + 2 + 3.5;
		float length2 = temp;
		model0 = translate(model0, v3(0, 0, -scale * temp));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 8, scale * 3.5, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//4
		temp = 14 + 3.5 + 3.5;
		length2 += temp;
		model0 = translate(model0, v3(0, 0, -scale * temp));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 8, scale * 3.5, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//5
		temp = 14 + 3.5 + 1.5;
		length2 += temp;
		model0 = translate(model0, v3(0, 0, -scale * temp));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 8, scale * 1.5, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//6
		temp = 12 + 1.5 + 1.5;
		length2 += temp;
		model0 = translate(model0, v3(0, 0, -scale * temp));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 8, scale * 1.5, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//7
		temp = 12 + 1.5 + 2;
		length2 += temp;
		model0 = translate(model0, v3(0, 0, -scale * temp));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 8, scale * 2, 1.0f / (scale * 8));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//back
		length1 /= 2;
		length1 -= 2;
		mesh = shape->FilledCubeTexture(scale * 1, scale * 10, scale * length1, 1.0f / (scale * 8));
		mat4 model1 = translate(model, v3(-scale * 2, 0, -scale * (length1 + 2)));
		mesh->setModel(model1);
		this->meshes.push_back(mesh);

		length2 /= 2;
		length2 += 2;
		mesh = shape->FilledCubeTexture(scale * 1, scale * 13, scale * length2, 1.0f / (scale * 8));
		model1 = translate(model1, v3(0, scale * 3, -scale * (length1 + length2)));
		mesh->setModel(model1);
		this->meshes.push_back(mesh);

		backLength = length1 + length2;
	}

	//bottom
	mesh = shape->FilledCubeTexture(scale * 1, scale * 5, scale * 66, 1.0f / (scale * 8));
	model = translate(model, v3(0, -scale * 5, -scale * 68));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	mesh = shape->FilledCubeTexture(scale * 1, scale * 5, scale * 25, 1.0f / (scale * 8));
	model = translate(model, v3(0, 0, -scale * (66 + 25)));
	mesh->setModel(model);
	this->meshes.push_back(mesh);

	//shape
	{
		mesh = shape->FilledCubeTexture(scale * 1, scale * 5, scale * 25, 1.0f / (scale * 8));
		mat4 model0 = translate(model, v3(-scale * 20, 0, 0));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);
		{

			mat4 model1 = translate(model0, v3(0, 0, -scale * 24));
			mesh = shape->FilledCubeTexture(scale * 9, scale * 5, scale * 1, 1.0f / (scale * 8));
			model1 = translate(model1, v3(scale * 10, 0, 0));
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
		}

		//shape
		model0 = translate(model0, v3(-scale * 16, 0, scale * 13));

		mesh = shape->FilledCubeTexture(scale * 10, scale * 7, scale * 10, 1.0f / (scale * 8));
		model0 = translate(model0, v3(scale * 10, scale * 2, scale * 15));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		{
			mesh = shape->FilledCubeTexture(scale * 3, scale * 2.5, scale * 10, 1.0f / (scale * 8));
			mat4 model1 = translate(model0, v3(scale * 7, scale * (7 + 2.5), 0));
			mesh->setModel(model1);
			this->meshes.push_back(mesh);

			mesh = shape->FilledCubeTexture(scale * 3, scale * 2.5, scale * 10, 1.0f / (scale * 8));
			model1 = translate(model1, v3(-scale * 14, 0, 0));
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
		}

		mesh = shape->FilledCubeTexture(scale * 25, scale * 13, scale * 10, 1.0f / (scale * 8));
		model0 = translate(model0, v3(-scale * 1, scale * 6, scale * 6)); //x on 10 -- move it to (6 + 10 + 8)/2 //y on 7 move it to 13
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		model0 = translate(model0, v3(-scale * (10 + 7), 0, -scale * 2)); //x 22 -> 10*2 + 8


		{
			std::vector<Texture> qibali1 =
			{
				Texture("res/textures/qibali/qibali1.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
				//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
			};

			mat4 model1 = translate(model0, v3(0, 0, -scale * 8 - 0.1));
			model1 = rotate(model1, radians(90.0f), v3(1, 0, 0));
			shape->setTextures(qibali1);
			mesh = shape->Square(scale * 8, scale * 13);
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
		}
		{
			std::vector<Texture> qibali2 =
			{
				Texture("res/textures/qibali/qibali2.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
				//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
			};

			mat4 model1 = translate(model0, v3(-scale * (8 + 7), -scale * (13 - 10), scale * 8 - 0.1));
			model1 = rotate(model1, radians(90.0f), v3(1, 0, 0));
			shape->setTextures(qibali2);
			mesh = shape->Square(scale * 7, scale * 10);
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
		}
	}


	////left wall
	//mesh = shape->FilledCubeTexture(scale * (10 + 10 + 8), scale * 13, scale * 2, 1.0f / (scale * 8));
	//model = translate(model, v3(-scale * 28, scale * 4, scale * (25 + 2)));
	//mesh->setModel(model);
	//this->meshes.push_back(mesh);
	{

		std::vector<Texture> qibali4 =
		{
			Texture("res/textures/qibali/qibali4.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
			//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
		};
		std::vector<Texture> qibali3 =
		{
			Texture("res/textures/qibali/qibali3.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
			//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
		};

		model = translate(model, v3(-scale * (2 + 50), scale * (10 - 5), scale * (16 + 25 + 1)));

		{
			mat4 model1 = translate(model, v3(-scale * (14 + 9), 0, -scale * 2 - 0.1));
			model1 = rotate(model1, radians(90.0f), v3(1, 0, 0));
			shape->setTextures(qibali4);
			for (int i = 0; i < 5; i++) {
				mesh = shape->Square(scale * 9, scale * 10);
				mesh->setModel(model1);
				this->meshes.push_back(mesh);
				model1 = translate(model1, v3(-scale * 18, 0, 0));
			}
		}

		{
			mat4 model1 = translate(model, v3(-scale * (-10.6 + 7 + 14), scale * (10 + 3), -scale * 2 - 0.1));
			model1 = rotate(model1, radians(90.0f), v3(1, 0, 0));
			shape->setTextures(qibali3);
			for (int i = 0; i < 5; i++) {
				mesh = shape->Square(scale * 10.4, scale * 3);
				mesh->setModel(model1);
				this->meshes.push_back(mesh);
				model1 = translate(model1, v3(-scale * 20.8, 0, 0));
			}
		}

		shape->setTextures(outerwall_qibai_textures);
		mesh = shape->FilledCubeTexture(scale * 52, scale * 13, scale * 2, 1.0f / (scale * 8));
		model = translate(model, v3(-scale * 52, scale * 3, 0));
		mesh->setModel(model);
		this->meshes.push_back(mesh);

		mesh = shape->FilledCubeTexture(scale * 9, scale * 10, scale * 2, 1.0f / (scale * 8));
		model = translate(model, v3(-scale * (52 + 9), scale * (10 - 13), 0));
		mesh->setModel(model);
		this->meshes.push_back(mesh);
	}
	//Front ------------------
	backLength -= 1.5;
	{//roof sides
		//side
		mat4 model0 = translate(model, v3(scale * (9 + 2), scale * 13, scale * (backLength + 2 - 16)));
		mesh = shape->FilledCubeTexture(scale * 1, scale * 3, scale * (backLength - 16), 1.0f / (scale * 4));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		//side
		mat4 model1 = translate(model0, v3(scale * (75 + 1), 0, scale * (backLength - 17)));
		mesh = shape->FilledCubeTexture(scale * 75, scale * 3, scale * 1, 1.0f / (scale * 4));
		mesh->setModel(model1);
		this->meshes.push_back(mesh);

		//carpet
		shape->setTextures(carpet);
		{
			mat4 model3 = translate(model, v3(scale * (9 + 75 + 2), -scale * (10 - 0.1), scale * (backLength + 2)));
			mesh = shape->FilledCubeTexture(scale * 75, 0, scale * (backLength), 0.4 / scale);
			//designer->column()
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
		}
		//roof roof
		shape->setTextures(roof2);
		{
			mat4 model3 = translate(model0, v3(scale * 76, scale * 3, -scale * (-10 + backLength / 2)));
			mesh = shape->FilledCubeTexture(scale * 75, 0, scale * (backLength / 2 - 5), 0.177 / scale);
			mesh->setModel(model3);
			this->meshes.push_back(mesh);

			shape->setTextures(inner_roof2);
			model3 = translate(model3, v3(0, - scale * 0.05, 0));
			mesh = shape->FilledCubeTexture(scale * 75, 0, scale * (backLength / 2 - 5), 0.177 / scale);
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
			shape->setTextures(roof2);
		}

		mat4 model2 = translate(model, v3(scale * (9 + 63 + 1 + 2), scale * (13 + 5), scale * (backLength + 2)));
		//top roof roof
		{
			mat4 model3 = translate(model2, v3(0, scale * 2, 0));
			mesh = shape->FilledCubeTexture(scale * 63, 0, scale * 9, 0.177 / scale);
			mesh->setModel(model3);
			this->meshes.push_back(mesh);

			shape->setTextures(inner_roof2);
			mat4 model4 = translate(model2, v3(0, - scale * 0.05, 0));
			mesh = shape->FilledCubeTexture(scale * 63, 0, scale * 9, 0.177 / scale);
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
			shape->setTextures(roof2);

			{
				model3 = translate(model3, v3(scale * (75 - 63), -scale * 4, scale * (10 + 8)));
				mesh = shape->FilledCubeTexture(scale * 75, 0, scale * 7, 0.177 / scale);
				mesh->setModel(model3);
				this->meshes.push_back(mesh);

				shape->setTextures(inner_roof2);
				model3 = translate(model3, v3(0, - scale * 0.05, 0));
				mesh = shape->FilledCubeTexture(scale * 75, 0, scale * 7, 0.177 / scale);
				mesh->setModel(model3);
				this->meshes.push_back(mesh);
				shape->setTextures(roof2);

			}
		}
		shape->setTextures(outerwall_qibai_textures);
		//top roof sides
		{
			mat4 model3 = translate(model2, v3(0, 0, -scale * 10));
			mesh = shape->FilledCubeTexture(scale * (63 + 1), scale * 2, scale * 1, 1.0f / (scale * 4));
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
		}
		{
			mat4 model3 = translate(model2, v3(0, 0, scale * 10));
			mesh = shape->FilledCubeTexture(scale * (63 + 1), scale * 2, scale * 1, 1.0f / (scale * 4));
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
		}
		{
			mat4 model3 = translate(model2, v3(scale * (63 + 1), 0, 0));
			mesh = shape->FilledCubeTexture(scale * 1, scale * 2, scale * 11, 1.0f / (scale * 4));
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
		}
		{
			mat4 model3 = translate(model2, v3(-scale * (63 + 1), 0, 0));
			mesh = shape->FilledCubeTexture(scale * 1, scale * 2, scale * 11, 1.0f / (scale * 4));
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
		}
		//dome
		{
			mat4 model3 = translate(model2, v3(scale * 75, -scale * 2, 0));
			designer->Qibali_Dome_for_abd(meshes, scale * 2, 0, v3(scale  * 1, scale * 7, 0), model3);

			shape->setTextures(roof2);
			mesh = shape->FilledCubeTexture(scale * (75 - 63), scale * 0.05, scale * 11, 1.0f / (scale * 4));
			mesh->setModel(model3);
			this->meshes.push_back(mesh);

			shape->setTextures(inner_roof2);
			mesh = shape->FilledCubeTexture(scale * (75 - 63), 0, scale * 11, 1.0f / (scale * 4));
			mesh->setModel(model3);
			this->meshes.push_back(mesh);
		}

	}
	shape->setTextures(door1Wall);
	{
		//top left
		mat4 model0 = translate(model, v3(scale * 3.7, scale * 9, scale * (backLength / 2 - 4.2)));
		mesh = shape->FilledCubeTexture(scale * 6.7, scale * 0.5, scale * (backLength / 2 - 4.2), 1.0f / (scale * 4));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		{//back left
			mat4 model2 = translate(model0, v3(scale * (9 - 0.1), -scale * 9, 0));
			mesh = shape->FilledCubeTexture(scale * 2, scale * 10, scale * (backLength / 2 - 3), 1.0f / (scale * 4));
			mesh->setModel(model2);
			this->meshes.push_back(mesh);
		}

		//top left side
		model0 = translate(model0, v3(0, 0, scale * (backLength / 2 - 4.2)));
		{
			mat4 model1 = translate(model0, v3(scale * 0.2, scale * 3.5, scale * 1));
			mesh = shape->FilledCubeTexture(scale * 5, scale * 3.5, scale * 0.5, 1.0f / (scale * 4));
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
		}

		//middle
		model0 = translate(model0, v3(0, 0, scale * (9 + 0.5)));
		{
			mat4 model1 = translate(model0, v3(scale * 0.4, scale * 6.5, scale * 1));
			mesh = shape->FilledCubeTexture(scale * 5.5, scale * 0.5, scale * 9, 1.0f / (scale * 4));
			mesh->setModel(model1);
			this->meshes.push_back(mesh);


			shape->setTextures(door2);
			{//open door
				mat4 model2 = translate(model0, v3(scale * (9 + 2), -scale * 11.5, scale * 7.5));
				mesh = shape->FilledCubeTexture(scale * 0.2, scale * 7.5, scale * 5, 1.0f / (scale * 4));
				mesh->setScale(scale);
				mesh->setBaseModel(model2);
				custom_meshes["d_r"]= mesh;
			}
			{//open door
				mat4 model2 = translate(model0, v3(scale * (9 + 2), -scale * 11.5, -scale * 7.5));
				mesh = shape->FilledCubeTexture(scale * 0.2, scale * 7.5, scale * 5, 1.0f / (scale * 4));
				mesh->setScale(scale);
				mesh->setBaseModel(model2);
				custom_meshes["d_l"] = mesh;
			}
			shape->setTextures(door1Wall);

			{//back middle
				mat4 model2 = translate(model0, v3(scale * (9 - 1), -scale * 2.1, 0));
				mesh = shape->FilledCubeTexture(scale * 2, scale * 2, scale * 8.1, 1.0f / (scale * 4));
				mesh->setModel(model2);
				this->meshes.push_back(mesh);
			}

			mat4 model2 = translate(model0, v3(scale * 5.5, scale * 3.5, scale * 1));
			mesh = shape->FilledCubeTexture(scale * 0.5, scale * 3.5, scale * 9, 1.0f / (scale * 4));
			mesh->setModel(model2);
			this->meshes.push_back(mesh);
		}
		model0 = translate(model0, v3(0, 0, scale * (9 + 0.5)));

		{//top right side
			mat4 model1 = translate(model0, v3(scale * 0.2, scale * 3.5, scale * 1));
			mesh = shape->FilledCubeTexture(scale * 5, scale * 3.5, scale * 0.5, 1.0f / (scale * 4));
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
		}

		//back right
		model0 = translate(model0, v3(0, 0, scale * (backLength / 2 - 4)));
		mesh = shape->FilledCubeTexture(scale * 6.7, scale * 0.5, scale * (backLength / 2 - 4), 1.0f / (scale * 4));
		mesh->setModel(model0);
		this->meshes.push_back(mesh);

		{//back right
			mat4 model2 = translate(model0, v3(scale * (9 - 0.5), -scale * 9, - 1));
			mesh = shape->FilledCubeTexture(scale * 2, scale * 10, scale * (backLength / 2 - 3 - 1), 1.0f / (scale * 4));
			mesh->setModel(model2);
			this->meshes.push_back(mesh);
		}
	}
	//gates
	{

		std::vector<Texture> door1 =
		{
			Texture("res/textures/qibali/door1.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
			//Texture("res/textures/woodSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
		};

		mat4 model0 = translate(model, v3(-scale * (9 - 3), scale * 2, scale * 2.1));
		shape->setTextures(door1);
		for (int i = 0; i < 3;i++) {
			model0 = translate(model0, v3(0, 0, scale * 8));
			designer->BigGate2(meshes, scale * 2, 90, v3(0, 0, 0), model0);

			mat4 model1 = translate(model0, v3(scale * (9 + 6) - 0.01, -scale * 4.45, 0));
			model1 = rotate(model1, radians(90.0f), v3(0, 0, 1));
			model1 = rotate(model1, -radians(90.0f), v3(0, 1, 0));
			mesh = shape->Square(scale * 6, scale * 7.5);
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
			model0 = translate(model0, v3(0, 0, scale * 8));
		}
		model0 = translate(model0, v3(0, 0, scale * 10.4));
		designer->BigGate2(meshes, scale * 2.6, 90, v3(scale * 0.9, scale * 3.7, 0), model0);
		model0 = translate(model0, v3(0, 0, scale * 10.4));
		for (int i = 0; i < 3;i++) {
			model0 = translate(model0, v3(0, 0, scale * 8));
			designer->BigGate2(meshes, scale * 2, 90, v3(0, 0, 0), model0);

			mat4 model1 = translate(model0, v3(scale * (9 + 6) - 0.01, -scale * 4.45, 0));
			model1 = rotate(model1, radians(90.0f), v3(0, 0, 1));
			model1 = rotate(model1, -radians(90.0f), v3(0, 1, 0));
			mesh = shape->Square(scale * 6, scale * 7.5);
			mesh->setModel(model1);
			this->meshes.push_back(mesh);
			model0 = translate(model0, v3(0, 0, scale * 8));
		}

		//mesh = shape->FilledCubeTexture(scale * 2, scale * 10, scale * backLength, 1.0f / (scale * 8));
		//model0 = translate(model0, v3(0, 0, scale * (backLength + 2)));
		//mesh->setModel(model0);
		//this->meshes.push_back(mesh);

		model = model_window;
		shape->setTextures(window);
		{
			mesh = shape->FilledCubeTexture(scale * 1.8, scale * 10, 0, 1.0f / (scale * 8));
			mat4 model0 = translate(model, v3(scale * (-1), 0, 0));
			mesh->setModel(model0);
			this->meshes.push_back(mesh);
		}
		for (int i = 0; i < 7; i++) {
			mesh = shape->FilledCubeTexture(scale * 9, scale * 10, 0, 1.0f / (scale * 8));
			model = translate(model, v3(scale * 9, 0, 0));
			mesh->setModel(model);
			this->meshes.push_back(mesh);
			model = translate(model, v3(scale * 9, 0, 0));
		}

	}
}