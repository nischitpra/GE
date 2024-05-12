#include <iostream>

#include "globals.h"

Renderer::Renderer() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = EMPTY_SPACE;
        }
    }
}

void Renderer::draw() const {
    std::ostringstream buffer;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            buffer << grid[y][x];
        }
        buffer << '\n';
    }

    // Clear the screen and move the cursor to the top-left corner
    std::cout << "\x1B[2J\x1B[H";
    std::cout << buffer.str();
}