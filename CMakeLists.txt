cmake_minimum_required(VERSION 3.20)
project(Visaah LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

add_subdirectory(external)

#Framework
add_library(Visaah
    framework/src/main.cpp
)

target_include_directories(Visaah PUBLIC
    framework/include
)

target_link_libraries(Visaah
    PUBLIC
        glfw
        glad
        OpenGL::GL
)

#Demo
add_executable(demo
    demo/main.cpp
)

target_link_libraries(demo
    Visaah
)
