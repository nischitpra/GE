#include "globals.h"

Terrain::Terrain() {
    // let up walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 1; x < WIDTH - 1; x++) {
            if (y == 0 || y == HEIGHT - 1) {
                grid[y][x] = WALL;
            } else {
                grid[y][x] = EMPTY_SPACE;
            }
        }
        grid[y][0] = WALL;
        grid[y][WIDTH - 1] = WALL;
    }
}

void Terrain::draw() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            renderer.grid[y][x] = grid[y][x];
        }
    }
}

/**
 * x and y are next values of x and y where user is going to move
 */
bool Terrain::hasCollision(int x, int y) {
    if (x < 0 || x >= WIDTH - 1) return true;
    if (y < 0 || y >= HEIGHT - 1) return true;
    return grid[y][x] == WALL;
}