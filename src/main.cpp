#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <chrono>
#include <iostream>
#include <thread>

#include "globals.h"
#include "inputs/InputHandler.h"
#include "inputs/TerminalMode.h"

int main() {
    TerminalMode::initializeTerminal();

    InputHandler handler;
    handler.startListening();

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        TerminalMode::cleanupTerminal();
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        TerminalMode::cleanupTerminal();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        TerminalMode::cleanupTerminal();
        return -1;
    }

    const std::chrono::milliseconds frameDuration(1000 / 60);
    auto lastFrame = std::chrono::steady_clock::now();
    bool running = true;

    while (running && !glfwWindowShouldClose(window)) {
        auto start = std::chrono::steady_clock::now();

        // Process input
        glfwPollEvents();  // Handle window events
        char inputKey = handler.getLastKey();
        if (inputKey != '\0') {
            world.update(inputKey);
            handler.clearKey();
        }

        // Draw world
        world.draw();

        glfwSwapBuffers(window);
        // Frame rate management
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        auto timeLeft = frameDuration - elapsed;
        if (timeLeft.count() > 0) {
            std::this_thread::sleep_for(timeLeft);
        }

        lastFrame = std::chrono::steady_clock::now();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    handler.stopListening();
    TerminalMode::cleanupTerminal();

    return 0;
}
