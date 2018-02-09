#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>

#include "GL/glew.h"

class Texture
{
    public:
        Texture(const std::string filename, GLenum filter);
        virtual ~Texture();

        GLuint GetTexture();

        void Bind();
        void Clear();

    protected:

    private:
        GLuint texture;
};

#endif // TEXTURE_H
