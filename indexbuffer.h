#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include <GL/glew.h>

class IndexBuffer
{
    public:
        IndexBuffer() {}
        IndexBuffer(int data[], int length);
        virtual ~IndexBuffer();

        void Bind();
        void Unbind();
        void Clear();

    protected:

    private:
        GLuint IBO;
};

#endif // INDEXBUFFER_H
