#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "shader.h"

class ShaderProgram
{
    public:
        ShaderProgram(void* value);
        virtual ~ShaderProgram();

        const char* vsSource =
        "#version 330 core \n"
        "layout (location = 0) in vec3 pos; \n"
        "\n"
        "void main() \n"
        "{ \n"
        "   gl_Position = vec4(pos, 1.0); \n"
        "} \0";

        const char* fsSource =
        "#version 330 core \n"
        "out vec4 color; \n"
        "\n"
        "void main() \n"
        "{ \n"
        "   color = vec4(1.0f, 1.0f, 1.0f, 1.0f); \n"
        "} \0";

        void Bind();

    protected:

    private:
        GLuint program;
};

#endif // SHADERPROGRAM_H
