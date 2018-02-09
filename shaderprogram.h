#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram
{
    public:
        ShaderProgram();
        virtual ~ShaderProgram();

        const char* vsSource =
        "#version 330 core \n"
        "layout (location = 0) in vec3 pos; \n"
        "layout (location = 1) in vec2 tex; \n"
        "\n"
        "out vec2 tex_;"
        "\n"
        "uniform mat4 transformation; \n"
        "\n"
        "void main() \n"
        "{ \n"
        "   gl_Position = transformation * vec4(pos, 1.0); \n"
        "   tex_ = tex; \n"
        "} \0";

        const char* fsSource =
        "#version 330 core \n"
        "\n"
        "in vec2 tex_;"
        "\n"
        "out vec4 color; \n"
        "\n"
        "uniform sampler2D texture_; \n"
        "\n"
        "void main() \n"
        "{ \n"
        "   color = texture(texture_, tex_); \n"
        "} \0";

        void Bind();
        void Clear();

        void SetTexture(const std::string &name, GLuint texture);
        void SetMatrix(const std::string &name, glm::mat4 matrix);

    protected:

    private:
        GLuint program;

        Shader vs;
        Shader fs;
};

#endif // SHADERPROGRAM_H
