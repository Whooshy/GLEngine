#include "vertexbuffer.h"

VertexBuffer::VertexBuffer()
{

}

VertexBuffer::VertexBuffer(float data[], float length)
{
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, length, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Clear()
{
    glDeleteBuffers(1, &VBO);
}

VertexBuffer::~VertexBuffer()
{

}
