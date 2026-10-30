#include <iostream>
#include <GLFW/glfw3.h>

#include <VisaahFramework/main.h>

void test() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!\n";
        return;
    }

    std::cout << "GLFW initialized successfully!\n";
    glfwTerminate();
}