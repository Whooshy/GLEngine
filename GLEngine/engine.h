#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Engine
{
    public:
        Engine(int width, int height, const std::string title, bool useVersion33);
        virtual ~Engine();

        void Loop();

    protected:

    private:
        GLFWwindow* window;
};

#endif // ENGINE_H
