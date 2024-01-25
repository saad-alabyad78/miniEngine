#include "Renderer.h"
#include "Debug.h"

void Renderer::Draw(VertexArray*& vertex_array, IndexBuffer*& index_buffer, Shader*& shader)const {
    
    shader->Bind();
    vertex_array->Bind();
    index_buffer->Bind();

    GlCall(glDrawElements(GL_TRIANGLES, index_buffer->GetCount() , GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear()const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClearColor(0.2f, 0.3f, 0.7f, 1.0f);
}