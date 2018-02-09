#include "engine.h"
#include "mesh.h"
#include "shaderprogram.h"
#include "texture.h"

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

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwSetFramebufferSizeCallback(window, ResizeCallback);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
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

    float texCoords[] = {
        0.0f, 0.0f,
        0.5f, 1.0f,
        1.0f, 0.0f,
    };

    int indices[] = {
        0, 1, 2
    };

    ShaderProgram shaderProgram;
    Texture texture((std::string) ("./res/textures/brick.png"), GL_LINEAR);
    shaderProgram.SetTexture("texture_", texture.GetTexture());
    Mesh mesh(vertices, sizeof(vertices), texCoords, sizeof(texCoords), indices, sizeof(indices), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0.25f, 0.25f, 0.25f));
    Mesh mesh2(vertices, sizeof(vertices), texCoords, sizeof(texCoords), indices, sizeof(indices), glm::vec3(0, 0.5f, 0), glm::vec3(0, 0, 0), glm::vec3(0.25f, 0.25f, 0.25f));

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.05f, 0.2f, 0.3f, 1.0f);

        shaderProgram.Bind();
        texture.Bind();

        mesh.Bind(shaderProgram);
        mesh.Draw();

        mesh2.Bind(shaderProgram);
        mesh2.Draw();

        mesh.Translate(glm::vec3(0.0001f, 0, 0));
        mesh2.Translate(glm::vec3(-0.0001f, 0, 0));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    mesh.Clear();
    shaderProgram.Clear();

    GLenum glErr = glGetError();

    if(glErr != GL_NO_ERROR)
    {
        std::cout << "Shutdown Error : " << glGetString(glErr) << std::endl;
    }

    std::cout << "Terminating..." << std::endl;

    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "Terminated" << std::endl;
}

Engine::~Engine()
{

}

void ResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
