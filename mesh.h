#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderprogram.h"

#include "vertexbuffer.h"
#include "indexbuffer.h"

class Mesh
{
    public:
        Mesh(float vertices[], unsigned int vLength, float texCoords[], unsigned int tLength, int indices[], unsigned int iLength, glm::vec3 pos, glm::vec3 rot, glm::vec3 scl);
        virtual ~Mesh();

        void Bind(ShaderProgram sp);
        void Draw();
        void Clear();

        void Translate(glm::vec3 pos);
        void Rotate(glm::vec3 rot);
        void Scale(glm::vec3 scl);

        glm::mat4 GetTransformMatrix() { return transformMatrix; }

    protected:
    private:
        GLuint VAO;

        VertexBuffer POS_VBO;
        VertexBuffer TEX_VBO;

        IndexBuffer IBO;

        glm::mat4 transformMatrix = glm::mat4(1.0f);
};

#endif // MESH_H
