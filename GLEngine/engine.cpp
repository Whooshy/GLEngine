#include "engine.h"
#include "mesh.h"
#include "shaderprogram.h"

void ResizeCallback(GLFWwindow* window, int width, int height);

Engine::Engine(int width, int height, const std::string title, bool useVersion33)
{
    if(!glfwInit())
    {
        std::cerr << "GLFW failed to initialize" << std::endl;
    }

    if(useVersion33)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    }

    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_TRUE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwSetFramebufferSizeCallback(window, ResizeCallback);

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();

    if(err != GLEW_OK)
    {
        std::cerr << "GLEW failed to initialize : " << glewGetErrorString(err) << std::endl;
    }

    Loop();
}

void Engine::Loop()
{
    float vertices[] = {
        -0.5f, -0.5f, 0,
        0, 0.5f, 0,
        0.5f, -0.5f, 0
    };

    ShaderProgram sp(0);
    Mesh mesh(vertices);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.05f, 0.2f, 0.3f, 1.0f);

        sp.Bind();
        mesh.Bind();
        mesh.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

Engine::~Engine()
{

}

void ResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
