#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

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

    //Initialize and test GLFW
    glm::vec3 position(1.0f, 1.0f, 1.0f);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    std::cout << "GLM initialized successfully!\n";
    std::cout << "Position: " << position.x << ", " << position.y << ", " << position.z << "\n";

    //Initialize and test Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 430");

    std::cout << "Dear ImGui initialized successfully!\n";

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        //Test imgui code
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();
        ImGui::Render();

        int displayWidth, displayHeight;
        glfwGetFramebufferSize(window, &displayWidth, &displayHeight);

        glViewport(0, 0, displayWidth, displayHeight);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    //Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}