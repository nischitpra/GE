#ifndef PLAYER_H
#define PLAYER_H

#include <sstream>

#include "constants.h"
#include "globals.h"

class Player {
   public:
    int playerX, playerY;

    Player();
    void draw();
    void inputKey(char direction);

   private:
    void movePlayer(int x, int y);
};

#endif
