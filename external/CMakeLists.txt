#GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw-3.5.1)

#GLAD
add_library(glad STATIC
    glad/src/glad.c
)

target_include_directories(glad PUBLIC
    glad/include
)

#GLM
add_subdirectory(glm)


#Dear ImGui
add_library(imgui STATIC
    imgui-docking/imgui.cpp
    imgui-docking/imgui_draw.cpp
    imgui-docking/imgui_tables.cpp
    imgui-docking/imgui_widgets.cpp
    imgui-docking/imgui_demo.cpp

    imgui-docking/backends/imgui_impl_glfw.cpp
    imgui-docking/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    imgui-docking
    imgui-docking/backends
)

target_link_libraries(imgui PUBLIC
    glfw
    OpenGL::GL
)
