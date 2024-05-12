#include "globals.h"

Player::Player() {
    playerX = WIDTH / 2;
    playerY = HEIGHT / 2;
}

void Player::inputKey(char direction) {
    int nextX = playerX;
    int nextY = playerY;
    switch (direction) {
        case 'w':
            nextY--;
            break;
        case 's':
            nextY++;
            break;
        case 'a':
            nextX--;
            break;
        case 'd':
            nextX++;
            break;
    }

    if (terrain.hasCollision(nextX, nextY)) return;

    movePlayer(nextX, nextY);
}

void Player::movePlayer(int x, int y) {
    playerX = x;
    playerY = y;
}

void Player::draw() { renderer.grid[playerY][playerX] = PLAYER; }