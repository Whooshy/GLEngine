#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <GL/glew.h>

class Shader
{
    public:
        Shader(GLenum type, const char* source);
        virtual ~Shader();

        GLuint getShader();

    protected:

    private:
        GLuint shader;
};

#endif // SHADER_H
