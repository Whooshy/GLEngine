#include "shaderprogram.h"

ShaderProgram::ShaderProgram(void* value)
{
    program = glCreateProgram();

    Shader vs(GL_VERTEX_SHADER, vsSource);
    Shader fs(GL_FRAGMENT_SHADER, fsSource);

    GLuint vertexShader = vs.getShader();
    GLuint fragmentShader = fs.getShader();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr << "Program link failed : " << infoLog << std::endl;
    }

    glValidateProgram(program);

    glGetProgramiv(program, GL_VALIDATE_STATUS, &success);

    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr << "Program validation failed : " << infoLog << std::endl;
    }
}

void ShaderProgram::Bind()
{
    glUseProgram(program);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(program);
}
