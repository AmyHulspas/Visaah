#include <GLFW/glfw3.h>
#include <VisaahFramework/main.h>

void test() {
    if (!glfwInit()) {
        return;
    }

    glfwTerminate();
}