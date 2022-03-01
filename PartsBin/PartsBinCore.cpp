#include "PartsBinCore.h"

void PartsBinApp::initWindow()
{
    glfwInit();

    //Don't use OpenGL
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //Don't allow abitrary window resizing
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "The Spare Parts Bin", nullptr, nullptr);

}

void PartsBinApp::initVulkan()
{
}

void PartsBinApp::mainLoop()
{
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void PartsBinApp::cleanup()
{
    glfwDestroyWindow(window);

    glfwTerminate();
}
