#include "mesh.h"

Mesh::Mesh(float vertices[])
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    VertexBuffer POS_VBO(vertices, sizeof(vertices));
    POS_VBO.Bind();

    glVertexAttribPointer(0, 3 * sizeof(float), GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
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

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &VAO);
}
