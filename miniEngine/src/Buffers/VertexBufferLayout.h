#pragma once
#include <vector>
#include<GL\glew.h>
#include "Renderer.h"


struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int getTypeSize(unsigned int type) {
		switch (type)
		{
			case GL_FLOAT:			return sizeof(GLfloat);
			case GL_UNSIGNED_INT:	return sizeof(GLuint);
			case GL_UNSIGNED_BYTE:	return sizeof(GLbyte);
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_Elelments;
	unsigned int m_Stride;
public:
	VertexBufferLayout()
		:m_Stride(0) {}


	template<typename T>
	void Push(unsigned int count)
	{
		//static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Elelments.push_back({ GL_FLOAT , count , GL_TRUE });
		m_Stride += count * sizeof(GLfloat);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_Elelments.push_back({ GL_UNSIGNED_INT , count , GL_FALSE });
		m_Stride += count * sizeof(GLuint);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Elelments.push_back({ GL_UNSIGNED_BYTE , count , GL_TRUE });
		m_Stride += count * sizeof(GLbyte) ;
	}

	inline const auto getStride() const { return m_Stride; }
	inline const auto getElements()const { return m_Elelments; }
};