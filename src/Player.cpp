#include "Player.h"

Player::Player() {
    playerX = WIDTH / 2;
    playerY = HEIGHT / 2;
}

void Player::inputKey(char direction) {
    nextX = playerX;
    nextY = playerY;
    switch (direction) {
        case 'w':  // Up
            nextY--;
            break;
        case 's':  // Down
            nextY++;
            break;
        case 'a':  // Left
            nextX--;
            break;
        case 'd':  // Right
            nextX++;
            break;
    }
}

void Player::commit() { movePlayer(); }

void Player::movePlayer() {
    playerX = nextX;
    playerY = nextY;
}

void Player::draw(char (&renderGrid)[HEIGHT][WIDTH]) { renderGrid[playerY][playerX] = PLAYER; }