#include "shader.h"

Shader::Shader(GLenum type, const char* source)
{
    shader = glCreateShader(type);

    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Shader compilation failed : " << infoLog << std::endl;
    }
}

GLuint Shader::getShader()
{
    return shader;
}

void Shader::Clear()
{
    glDeleteShader(shader);
}

Shader::~Shader()
{

}
