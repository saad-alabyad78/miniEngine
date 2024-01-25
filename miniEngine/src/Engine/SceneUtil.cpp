#include <Scene.h>

void Scene::util(float scale, v3 position) {
	designer->idk1(meshes, scale, 0, v3(130, -5, 0));
	designer->idk1(meshes, scale, 0, v3(0, -5, 130));
	designer->idk1(meshes, scale, 0, v3(40, -5, -170));
	designer->idk1(meshes, scale, 0, v3(-40, -5, -170));
	designer->idk1(meshes, scale, 0, v3(100, -5, 100));
	designer->idk1(meshes, scale, 0, v3(20, -5, 340));
	designer->idk1(meshes, scale, 0, v3(-100, -5, 00));
	designer->idk1(meshes, scale, 0, v3(-150, -5, -320));


	designer->idk2(meshes, scale, 0, v3(-20, -5, -320));
	designer->idk2(meshes, scale, 0, v3(0, -5, -130));
	designer->idk2(meshes, scale, 0, v3(+40, -5, +200));
	designer->idk2(meshes, scale, 0, v3(-100, -5, -100));
	designer->idk2(meshes, scale, 0, v3(-20, -5, -340));
	designer->idk2(meshes, scale, 0, v3(+100, -5, 00));
	designer->idk2(meshes, scale, 0, v3(+150, -5, +320));


	//designer->idk1(meshes, scale, 0, v3(0,scale * 50, 0));

	//float idk1 = - scale * 5;
	//float idk2 = - scale * 6;
	//designer->idk1(meshes, scale, 0, v3(120, idk1, 0));
	//designer->idk2(meshes, scale, 0, v3(110, idk2, 20));
	//designer->idk1(meshes, scale, 0, v3(90, idk1, 50));
	//designer->idk2(meshes, scale, 0, v3(-80, idk2, 100));
	//designer->idk1(meshes, scale, 0, v3(50, idk1, 150));
	//designer->idk2(meshes, scale, 0, v3(-40, idk2, 120));
	//designer->idk1(meshes, scale, 0, v3(20, idk1, 180));
	//designer->idk2(meshes, scale, 0, v3(-130, idk2, 230));
	//designer->idk3(meshes, scale, 0, v3(50, scale * 2, 40));
	//designer->idk4(meshes, scale, 0, v3(100,scale * 2, 40));
}

void Scene::trees(float scale, v3 position) {
	mat4 model = translate(mat4(1), position);
	std::vector<v3> trees = {
		v3(-140,0,160),
		v3(40  ,0,170),
		v3(10  ,0,175),
		v3(20  ,0,160),

		v3(10 ,0,190),
		v3(60 ,0,180),
		v3(-70,0,190),
		v3(50 ,0,200),


		v3(40 , 0,240),
		v3(20 , 0,262),

		v3(90 , 0,220),
		v3(80 , 0,250),
		v3(130 , 0,250),
		v3(170 , 0,200),
		v3(-30, 0,150),


		v3(-20,0,180),
		v3(-70,0,270),
		v3(-50,0,280),
		v3(-50,0,-180),

		v3(-90,0,-210),
		v3(-50,0,-240),
		v3(90 ,0,-95),
		v3(-92,0, 70),

		v3(-85,2, -0),
		v3(83 ,4, 10),
	};
	std::vector<Texture> tree =
	{
		Texture("res/textures/tree.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};
	shape->setTextures(tree);
	Mesh* mesh;
	for (v3 pos : trees) {
		mesh = shape->Square(3, 5);
		mat4 model0 = translate(model, scale * (pos + v3(0,3,0)));
		model0 = rotate(model0, radians(90.0f), v3(1, 0, 0));
		mesh->setBaseModel(model0);
		trees_meshes.push_back(mesh);
	}
}