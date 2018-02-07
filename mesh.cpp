#include "mesh.h"

Mesh::Mesh(float vertices[], unsigned int vLength)
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    POS_VBO = VertexBuffer(vertices, vLength);
    POS_VBO.Bind();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    POS_VBO.Unbind();
    glBindVertexArray(0);
}

void Mesh::Bind()
{
    glBindVertexArray(VAO);
}

void Mesh::Draw()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Mesh::Clear()
{
    POS_VBO.Clear();
    glDeleteVertexArrays(1, &VAO);
}

Mesh::~Mesh()
{

}
