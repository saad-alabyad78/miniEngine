#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>&vertices, std::vector<unsigned int>&indices, std::vector<Texture>& textures)
	:vertices(vertices) , indices(indices) , textures(textures)
{
	renderer = new Renderer(); 
	Make();
}

void Mesh::Make()
{
	//layout 
	VertexBufferLayout *layout = new VertexBufferLayout();
	//3 for position
	layout->Push<float>(3);
	//3 for normals
	layout->Push<float>(3);
	//2 fot texture coordinates
	layout->Push<float>(2);

	//vbo
	VertexBuffer *vbo = new VertexBuffer(vertices.data() , vertices.size() * sizeof(Vertex));
	//ibo
	m_IBO = new IndexBuffer(indices.data() , indices.size());
	//vao
	m_VAO = new VertexArray();

	m_VAO->addBuffer(vbo, layout);
}

void Mesh::Draw(Shader*& shader)
{
	// Bind shader to be able to access uniforms
	shader->Bind();

	// Keep track of how many of each type of textures we have
	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string num;
		std::string type = textures[i].type;
		if (type == "diffuse")
		{
			num = std::to_string(numDiffuse++);
		}
		else if (type == "specular")
		{
			num = std::to_string(numSpecular++);
		}
		textures[i].texUnit(shader, (type + num).c_str(), i);
		textures[i].Bind();
	}

	shader->setModel(this->model);

	renderer->Draw(m_VAO, m_IBO, shader);
}

void Mesh::setModel(glm::mat4& model) {
	this->model = model;
};
void Mesh::setBaseModel(glm::mat4& model) {
	this->base_model = model;
	setModel(model);
}
void Mesh::setScale(float scale)
{
	this->scale = scale;
}
;

Mesh::~Mesh()
{

}