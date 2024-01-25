#pragma once

#include "Stb_Image/stb_image.h"
#include "Renderer.h"
#include"shader.h"

class Texture
{
public:
	GLuint ID;
	const char* type;
	GLuint unit;

	Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType);

	void texUnit(Shader*& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
};
