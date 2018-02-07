#include "shaderprogram.h"

ShaderProgram::ShaderProgram()
{
    program = glCreateProgram();

    vs = Shader(GL_VERTEX_SHADER, vsSource);
    fs = Shader(GL_FRAGMENT_SHADER, fsSource);

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

void ShaderProgram::Clear()
{
    glDetachShader(program, vs.getShader());
    glDetachShader(program, fs.getShader());

    vs.Clear();
    fs.Clear();

    glDeleteProgram(program);
}

ShaderProgram::~ShaderProgram()
{

}
