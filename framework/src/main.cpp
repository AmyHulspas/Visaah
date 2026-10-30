#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <VisaahFramework/main.h>

void test() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!\n";
        return;
    }

    //Initialize and test GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Window", nullptr, nullptr);

    if (!window) {
        std::cerr << "Failed to create GLFW window!\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    //Initialize and test GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }

    if (!GLAD_GL_VERSION_4_3) {
        std::cerr << "OpenGL 4.3 is not supported!\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }

    std::cout << "GLAD initialized successfully!\n";
    std::cout << "OpenGL version: " << GLVersion.major << "." << GLVersion.minor << "\n";

    //Initialize and test GLM
    glm::vec3 position(1.0f, 1.0f, 1.0f);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    std::cout << "GLM initialized successfully!\n";
    std::cout << "Position: " << position.x << ", " << position.y << ", " << position.z << "\n";

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}