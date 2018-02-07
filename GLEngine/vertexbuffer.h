#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>

class VertexBuffer
{
    public:
        VertexBuffer(float data[], float length);
        virtual ~VertexBuffer();

        void Bind();
        void Unbind();

    protected:
    private:
        GLuint VBO;
};

#endif // VERTEXBUFFER_H
