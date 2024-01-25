#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"


VertexArray::VertexArray()
{
	GlCall(glGenVertexArrays(1, &m_RendererID));
}
VertexArray::~VertexArray()
{
	GlCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::addBuffer(VertexBuffer* &vb,VertexBufferLayout* &layout)
{
	this->Bind();
	vb->Bind();
	const auto& elements = layout->getElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {

		const auto& el = elements[i];

		GlCall(glEnableVertexAttribArray(i));
		GlCall(glVertexAttribPointer(i, el.count, el.type, el.normalized, layout->getStride(), (const void*)offset));
		offset += el.count * VertexBufferElement::getTypeSize(el.type);
	}

}

void VertexArray::Bind()const {
	GlCall(glBindVertexArray(m_RendererID));
}
void VertexArray::UnBind()const {
	GlCall(glBindVertexArray(0));
}


