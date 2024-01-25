#pragma once

#include <string>
#include <vector>
#include <Shader.h>
#include <VertexBuffer.h>
#include <VertexArray.h>
#include <IndexBuffer.h>
#include <VertexBufferLayout.h>
#include <Texture.h>
#include <Camera.h>
#include<Window.h>

#include "Debug.h"
#include "renderer.h"

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

class SkyBox {

public:
	Shader* skyShader;
    unsigned int VAO, VBO , EBO;
    unsigned int cubemapTexture;
    Camera* camera;
    Window* window;

    SkyBox(Camera*& camera , Window*& window , std::string& templateName);

    void Draw();

};