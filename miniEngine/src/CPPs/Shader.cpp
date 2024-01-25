#include "Shader.h"
#include "Renderer.h"
#include<string>

#include <iostream>
#include<fstream>
#include<string>
#include<sstream>

#include<unordered_map>



Shader::Shader(const std::string& filepath)
	:m_FilePath(filepath) , m_RendererID(0)
{
    ShaderProgramSource src = ParseShader(filepath);

    //std::cout << src.VertexSource << std::endl;
    //std::cout << src.FragmentSource << std::endl;
    std::cout << filepath << std::endl;
    m_RendererID = CreateShader(src.VertexSource, src.FragmentSource);

}
Shader::~Shader() 
{
    GlCall(glDeleteProgram(m_RendererID));
}


ShaderProgramSource Shader::ParseShader(const std::string& filepath) {

    std::ifstream stream(filepath);

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };


    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else if (type != ShaderType::NONE) { // it should not be NONE
            ss[(int)type] << line << '\n';
        }
        else {
            std::cout << " therer is no #shader in shader file\n";
        }
    }
    return { ss[0].str() , ss[1].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str(); // same as &source[0]
    GlCall(glShaderSource(id, 1, &src, nullptr));
    GlCall(glCompileShader(id));

    int res;
    GlCall(glGetShaderiv(id, GL_COMPILE_STATUS, &res));
    if (res == GL_FALSE)
    {
        int len;
        GlCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len));
        char* message = (char*)malloc(len * sizeof(char));
        GlCall(glGetShaderInfoLog(id, len, &len, message));
        std::cout << "Failed to compile "
            << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
            << " shader! " << std::endl;
        std::cout << message << std::endl;

        GlCall(glDeleteShader(id));
        return 0;
    }

    return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GlCall(glAttachShader(program, vs));
    GlCall(glAttachShader(program, fs));
    GlCall(glLinkProgram(program));
    GlCall(glValidateProgram(program));

    GlCall(glDeleteShader(vs));
    GlCall(glDeleteShader(fs));

    return program;
}

void Shader::Bind()const {
    GlCall(glUseProgram(m_RendererID));
}
void Shader::UnBind()const {
    GlCall(glUseProgram(0));
}


//set uniforms
void Shader::setModel(const glm::mat4& model)  {
    this->setMat4f("model", model);
}

void Shader::setView(const glm::mat4& view) {
    this->setMat4f("view", view);
}

void Shader::setProjection(const glm::mat4& projection) {
    this->setMat4f("projection", projection);
}

void Shader::set4f(const std::string& name, float f0, float f1, float f2, float f3) {

    auto location = getUniformLocation(name);
    if (location != -1) {
        GlCall(glUniform4f(location, f0, f1, f2, f3));
    }
}

void Shader::set3f(const std::string& name, float f0, float f1, float f2) {

    auto location = getUniformLocation(name);
    if (location != -1) {
        GlCall(glUniform3f(location, f0, f1, f2));
    }
}

void Shader::setVec3(const std::string& name, glm::vec3 Vec3) {

    auto location = getUniformLocation(name);
    if (location != -1) {
        GlCall(glUniform3f(location, Vec3.x , Vec3.y , Vec3.z));
    }
}

void Shader::setVec4(const std::string& name, glm::vec4 Vec4) {

    auto location = getUniformLocation(name);
    if (location != -1) {
        GlCall(glUniform4f(location, Vec4.x, Vec4.y, Vec4.z , Vec4.w));
    }
}


void Shader::set1i(const std::string& name, int val) {

    auto location = getUniformLocation(name);
    if (location != -1) {
        GlCall(glUniform1i(location, val));
    }  
}

void Shader::set1f(const std::string& name, float val) {

    auto location = getUniformLocation(name);
    if (location != -1) {
        GlCall(glUniform1f(location, val));
    }
}

void Shader::setMat4f(const std::string& name, const glm::mat4& proj) {

    auto location = getUniformLocation(name);
    if (location != -1) {
        GlCall(glUniformMatrix4fv(location, 1, GL_FALSE, &proj[0][0]));
    }
}

int Shader::getUniformLocation(const std::string& name) {
    
    this->Bind();

    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) 
        return m_UniformLocationCache[name];
    
    GlCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
    if (location == -1)
        std::cout << "WARNING : uniform " << name << " doesn't exist!" << std::endl;

     return  m_UniformLocationCache[name] = location;
}