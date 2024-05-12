#include "Window.h"

Window::Window() {
    //   // Initialize GLFW
    // if (!glfwInit()) {
    //     std::cerr << "Failed to initialize GLFW\n";
    //     return -1;
    // }

    // // Create a windowed mode window and its OpenGL context
    // GLFWwindow* window = glfwCreateWindow(640, 480, "Hello OpenGL", NULL, NULL);
    // if (!window) {
    //     glfwTerminate();
    //     std::cerr << "Failed to create GLFW window\n";
    //     return -1;
    // }

    // // Make the window's context current
    // glfwMakeContextCurrent(window);

    // // Initialize GLEW
    // glewExperimental = true;  // Needed in core profile
    // if (glewInit() != GLEW_OK) {
    //     std::cerr << "Failed to initialize GLEW\n";
    //     return -1;
    // }

    // // Loop until the user closes the window
    // while (!glfwWindowShouldClose(window)) {
    //     // Render here
    //     glClear(GL_COLOR_BUFFER_BIT);

    //     // Swap front and back buffers
    //     glfwSwapBuffers(window);

    //     // Poll for and process events
    //     glfwPollEvents();
    // }

    // glfwTerminate();
    // return 0;
}

void Window::draw() {}
