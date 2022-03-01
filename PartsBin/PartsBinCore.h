#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
//#include <vulkan/vulkan.h> Replaced by GLFW

class PartsBinApp {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:

    const uint32_t WIDTH = 1920;
    const uint32_t HEIGHT = 1080;

    GLFWwindow* window;



    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
};
