#pragma once

#include <string>
#include <vector>
#include <Material\Shader.h>

#include <Buffers\VertexBuffer.h>
#include <Buffers\VertexArray.h>
#include <Buffers\IndexBuffer.h>
#include <Buffers\VertexBufferLayout.h>
#include <Material\Texture.h>
#include <Camera.h>


#include "Debug.h"
#include "renderer.h"

#define GLM_ENABLE_EXPERIMENTAL
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

struct Vertex {
	glm::vec3 positions;
	glm::vec3 normals;
	glm::vec2 texCoords;
};

class Mesh
{
public:
	glm::mat4 model;
	glm::mat4 base_model;
	float scale;

	std::vector<Vertex>			vertices;
	std::vector<unsigned int>	indices;
	std::vector <Texture> textures;

	VertexArray* m_VAO;
	IndexBuffer *m_IBO;
	
	Renderer* renderer;

	Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices , std::vector<Texture>& textures);
	~Mesh();

	void Draw(Shader*& shader);

	void Make();

	void setModel(glm::mat4 &model);
	void setBaseModel(glm::mat4& model);
	void setScale(float scale);
};
