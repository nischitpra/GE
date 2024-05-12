#ifndef TERRAIN_H
#define TERRAIN_H

#include <sstream>
#include <vector>

#include "constants.h"
#include "globals.h"

class Terrain {
   public:
    Terrain();
    void draw();
    bool hasCollision(int x, int y);

   private:
    char grid[HEIGHT][WIDTH];
};

#endif