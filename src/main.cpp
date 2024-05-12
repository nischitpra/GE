#include <chrono>
#include <iostream>
#include <thread>

#include "InputHandler.h"
#include "TerminalMode.h"
#include "World.h"

int main() {
    TerminalMode::initializeTerminal();

    InputHandler handler;
    handler.startListening();

    World world = World();

    const std::chrono::milliseconds frameDuration(1000 / 60);
    auto lastFrame = std::chrono::steady_clock::now();

    bool running = true;
    while (running) {
        auto start = std::chrono::steady_clock::now();

        char inputKey = handler.getLastKey();
        if (inputKey != '\0') {
            world.update(inputKey);
            handler.clearKey();
        }

        world.draw();

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        auto timeLeft = frameDuration - elapsed;

        if (timeLeft.count() > 0) {
            std::this_thread::sleep_for(timeLeft);
        }

        lastFrame = std::chrono::steady_clock::now();
    }

    handler.stopListening();
    TerminalMode::cleanupTerminal();

    return 0;
}
