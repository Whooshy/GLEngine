#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <GL/glew.h>

#include "vertexbuffer.h"

class Mesh
{
    public:
        Mesh(float vertices[], unsigned int vLength);
        virtual ~Mesh();

        void Bind();
        void Draw();
        void Clear();

    protected:
    private:
        GLuint VAO;
        VertexBuffer POS_VBO;
};

#endif // MESH_H
