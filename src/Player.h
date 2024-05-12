#ifndef PLAYER_H
#define PLAYER_H

#include <sstream>

#include "Constants.h"

class Player {
   public:
    int playerX, playerY;
    int nextX, nextY;

    Player();
    void draw(char (&renderGrid)[HEIGHT][WIDTH]);
    void inputKey(char direction);
    void commit();

   private:
    void movePlayer();
};

#endif
