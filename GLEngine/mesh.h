#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>

#include "vertexbuffer.h"

class Mesh
{
    public:
        Mesh(float vertices[]);
        virtual ~Mesh();

        void Bind();
        void Draw();

    protected:
    private:
        GLuint VAO;
};

#endif // MESH_H
