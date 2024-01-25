#pragma once
#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray {
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();

	void addBuffer(VertexBuffer* &vb,VertexBufferLayout* &layout);

	void Bind() const;
	void UnBind() const;
};
