#include <Scene.h>
// #include <irrk/include/irrKlang.h>
//	
// using namespace irrklang;
// ISoundEngine* SoundEngine = createIrrKlangDevice();

void Scene::player(float scale, v3 position, float yRotate) {
	mat4 model = mat4(1.0);
	std::vector<Texture> player =
	{
		Texture("res/textures/qibali/door1Wall.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};

	shape->setTextures(player);
	Mesh* mesh;
	mesh = shape->FilledCubeTexture(scale * 0.5, scale * 2, scale * 1, 1.0f / (scale * 8));
	mesh->setModel(model);
	this->custom_meshes["p_b"] = mesh;

	mesh = shape->FilledCubeTexture(scale * 0.5, scale * 0.5, scale * 0.5, 1.0f / (scale * 8));
	mesh->setModel(model);
	this->custom_meshes["p_h"] = mesh;
}

void Scene::MakeScene()
{
	mosqe(1, v3(-25, 2, -2 + 280));
	mosqe2(1, v3(-25, 3, -2 + 280));
	mashreb(1, v3(-27, 4, -22 + 280));


	//floor(1, v3(0, 0, 0));

	floor(5, v3(0, 0, 0));

	bstan(1, v3(30, 0, - 40 + 294), 180);

	fences(1, v3(0,0,0));
	Rock_Dome(0.75, v3(10, 2.8, 0), 0);

	util();
	trees();

	player();

	qibali(0.7, v3(80, 9, -300), 90);
};


bool CheckCollision(float onex, float onez, float onel, float twox, float twoz, float twolx, float twolz)
{
	// collision x-axis?
	bool collisionX = onex + onel >= twox &&
		twox + twolx >= onex;
	// collision z-axis?
	bool collisionZ = onez + onel >= twoz &&
		twoz + twolz >= onez;
	// collision only if on both axes
	return collisionX && collisionZ;
}

void Scene::Update()
{
	renderer->Clear();
	mat4 projection = glm::perspective(radians(camera->Zoom), (float)window->WIDTH / (float)window->HEIGHT, 0.1f, 1000.0f);
	shader->setView(camera->GetViewMatrix());


	shader->setProjection(projection);
	shader->setView(camera->GetViewMatrix());

	light_shader->setView(camera->GetViewMatrix());
	light_shader->setProjection(projection);

	light->Update(shader);

	if (light->state == "son") {
		for (auto light : this->day_meshes) {
			light->Draw(light_shader);
		}
	}

	if (light->state == "moon") {
		for (auto& light : this->night_meshes) {
			light->Draw(light_shader);
		}
	}
	sky[sky_selector]->Draw();


	if (doorOpen && doorRotate < 80.0f) {
		doorRotate += 1;
	}
	else if (!doorOpen && doorRotate > 0.0f) {
		doorRotate -= 1;
	}
	{
		Mesh* mesh = custom_meshes["d_r"];
		mat4 model = translate(mesh->base_model, v3(mesh->scale * sin(radians(doorRotate)) * 3.5, 0, -mesh->scale * cos(radians(doorRotate)) * 4));
		model = rotate(model, -radians(doorRotate), v3(0, 1, 0));
		mesh->setModel(model);
		mesh->Draw(shader);
	}
	{
		Mesh* mesh = custom_meshes["d_l"];
		mat4 model = translate(mesh->base_model, v3(mesh->scale * sin(radians(doorRotate)) * 3.5, 0, mesh->scale * cos(radians(doorRotate)) * 4));
		model = rotate(model, radians(doorRotate), v3(0, 1, 0));
		mesh->setModel(model);
		mesh->Draw(shader);
	}

	{
		mat4 model = translate(mat4(1.0f), camera->Position - v3(cos(radians(camera->Yaw)), 0, sin(radians(camera->Yaw))));
		model = rotate(model, -radians(camera->Yaw), v3(0, 1, 0));
		custom_meshes["p_b"]->setModel(model);
		custom_meshes["p_b"]->Draw(shader);

		model = translate(model, v3(0, 2.5, 0));
		custom_meshes["p_h"]->setModel(model);
		custom_meshes["p_h"]->Draw(shader);
	}

	for (auto& mesh : this->meshes) {
		mesh->Draw(shader);
	}

	//for (auto& mesh : this->player_meshes) {
		//mat4 model = translate(mesh->model, camera->Position);
		//model = rotate(model, radians(camera->Yaw), v3(0, 1, 0));
		//mesh->setModel(model);
		//mesh->Draw(shader);


	for (auto& mesh : trees_meshes) {
		mat4 model = rotate(mesh->base_model, radians(camera->Yaw + 90), v3(0, 0, 1));
		mesh->setModel(model);
		mesh->Draw(shader);
	}
};

void Scene::Input(float& deltaTime, GLFWcursorposfun mouse_callback, std::map<std::string, bool> buttons) {
	//objects input
	std::vector<v3> postions = {
		v3(-5,7,0),
		v3(80,0,-150),
		v3(-200,180,550),
	};

	if (buttons["po1"]) {
		camera->Position = postions[0];
	}else if (buttons["po2"]) {
		camera->Position = postions[1];
	}else if (buttons["po3"]) {
		camera->Position = postions[2];
	}else if (buttons["d_open"]) {
		doorOpen = true;
	}else if (buttons["d_close"]) {
		doorOpen = false;
	}else if(buttons["moon"]) {
		light->state = "moon";
		sky_selector = 1;
	}else if (buttons["son"]) {
		light->state = "son";
		sky_selector = 0;
	}
	camera->fps = buttons["fps"];

	//sitting input 
	if (window->key(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(window->m_WindowID, true);
	bool tab = window->key(GLFW_KEY_TAB);

	if (tab) {
		glfwSetInputMode(window->m_WindowID, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		glfwSetCursorPosCallback(window->m_WindowID, NULL);
	}
	else {
		glfwSetInputMode(window->m_WindowID, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetCursorPosCallback(window->m_WindowID, mouse_callback);
	}
	//camera input
	bool x1 = 0, x2 = 0, x3 = 0, x4 = 0;

	if (window->key(GLFW_KEY_W)) {
		camera->ProcessKeyboard(FORWARD, deltaTime);
		x1 = 1;
	}
	else if (window->key(GLFW_KEY_S))
	{
		camera->ProcessKeyboard(BACKWARD, deltaTime);
		x2 = 1;
	}

	if (window->key(GLFW_KEY_A))
	{
		camera->ProcessKeyboard(LEFT, deltaTime);
		x3 = 1;
	}
	else if (window->key(GLFW_KEY_D))
	{
		camera->ProcessKeyboard(RIGHT, deltaTime);
		x4 = 1;
	}
	if (window->key(GLFW_KEY_SPACE))
	{
		camera->ProcessKeyboard(UP, deltaTime);
	}
	if (window->key(GLFW_KEY_LEFT_SHIFT))
	{
		camera->ProcessKeyboard(DOWN, deltaTime);
	}

	v3 Position = camera->Position;
	bool stop = false;
	for (v4 v : colliders) {
		if (CheckCollision(Position.x, Position.z, 2, v.x, v.y, v.z, v.w)) {
			if (x1)
				camera->ProcessKeyboard(BACKWARD, deltaTime);
			else if (x2)
				camera->ProcessKeyboard(FORWARD, deltaTime);
			if (x4)
				camera->ProcessKeyboard(LEFT, deltaTime);
			else if (x3)
				camera->ProcessKeyboard(RIGHT, deltaTime);
			stop = true;
			break;
		}
	}
	if (!stop) {
		for (Stairs stair : stairs) {
			if (CheckCollision(Position.x, Position.z, 2, stair.center.x - stair.length.x, stair.center.y - stair.length.y, stair.length.x * 2, stair.length.y * 2)) {
				//if ( abs((camera->Yaw - stair.yRotate)) < 90) {
				//	if (x1) 
				//		camera->ProcessKeyboard(UP, deltaTime);
				//	else if(x2)
				//		camera->ProcessKeyboard(DOWN, deltaTime);
				//
				//else {
				//	if (x1)
				//		camera->ProcessKeyboard(DOWN, deltaTime);
				//	else if (x2)
				//		camera->ProcessKeyboard(UP, deltaTime);
				//}
			//}
				break;
			}
		}
	}

	if (window->key(GLFW_KEY_LEFT_CONTROL))
		camera->MovementSpeed++;
	if (window->key(GLFW_KEY_Q))
		camera->MovementSpeed = 12;

	 //if (window->key(GLFW_KEY_T))
	 //	SoundEngine->play2D("audio/bell.wav", true);
}


Scene::~Scene()
{

};