#include "mesh.h"

Mesh::Mesh(float vertices[], unsigned int vLength, float texCoords[], unsigned int tLength, int indices[], unsigned int iLength, glm::vec3 pos, glm::vec3 rot, glm::vec3 scl)
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    POS_VBO = VertexBuffer(vertices, vLength);
    POS_VBO.Bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
    POS_VBO.Unbind();

    TEX_VBO = VertexBuffer(texCoords, tLength);
    TEX_VBO.Bind();
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    TEX_VBO.Unbind();

    IBO = IndexBuffer(indices, iLength);
    IBO.Bind();

    transformMatrix = glm::translate(transformMatrix, pos);

    transformMatrix = glm::rotate(transformMatrix, rot.x, glm::vec3(1, 0, 0));
    transformMatrix = glm::rotate(transformMatrix, rot.y, glm::vec3(0, 1, 0));
    transformMatrix = glm::rotate(transformMatrix, rot.z, glm::vec3(0, 0, 1));

    transformMatrix = glm::scale(transformMatrix, scl);

    glBindVertexArray(0);
}

void Mesh::Bind(ShaderProgram sp)
{
    glBindVertexArray(VAO);
    sp.SetMatrix("transformation", transformMatrix);
}

void Mesh::Draw()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Mesh::Clear()
{
    POS_VBO.Clear();
    TEX_VBO.Clear();
    IBO.Clear();
    glDeleteVertexArrays(1, &VAO);
}

void Mesh::Translate(glm::vec3 pos)
{
    transformMatrix = glm::translate(transformMatrix, pos);
}

void Mesh::Rotate(glm::vec3 rot)
{
    transformMatrix = glm::rotate(transformMatrix, rot.x, glm::vec3(1, 0, 0));
    transformMatrix = glm::rotate(transformMatrix, rot.y, glm::vec3(0, 1, 0));
    transformMatrix = glm::rotate(transformMatrix, rot.z, glm::vec3(0, 0, 1));
}

void Mesh::Scale(glm::vec3 scl)
{
    transformMatrix = glm::translate(transformMatrix, scl);
}

Mesh::~Mesh()
{

}
