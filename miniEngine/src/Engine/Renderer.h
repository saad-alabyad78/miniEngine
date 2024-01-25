#pragma once

#include<GL\glew.h>

#include "Debug.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"




class Renderer {
private:
public:
	void Clear() const;
	void Draw(VertexArray *& va, IndexBuffer *& ib, Shader *& sh) const;
};
