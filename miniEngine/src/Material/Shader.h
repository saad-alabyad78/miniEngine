#pragma once
#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

struct ShaderProgramSource {
	std::string  VertexSource, FragmentSource;
};


class Shader {
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	//caching for s 
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind()const;
	void UnBind()const;

	//set s
	void setVec3(const std::string& name, glm::vec3 Vec3);
	void setVec4(const std::string& name, glm::vec4 Vec4);
	void set4f(const std::string& name , float f0 , float f1 , float f2 , float f3);
	void set3f(const std::string& name, float f0, float f1, float f2);
	void setMat4f(const std::string& name, const glm::mat4& mat);
	void set1i(const std::string& name, int val);
	void set1f(const std::string& name, float val);
	void setModel(const glm::mat4& model);
	void setView(const glm::mat4& view);
	void setProjection(const glm::mat4& projection);
private:
	
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int getUniformLocation(const std::string& name);
};