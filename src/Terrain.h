#ifndef TERRAIN_H
#define TERRAIN_H

#include <sstream>
#include <vector>

#include "Constants.h"

class Terrain {
   public:
    Terrain();
    void draw(char (&grid)[HEIGHT][WIDTH]);
    bool hasCollision(int x, int y);

   private:
    char grid[HEIGHT][WIDTH];
};

#endif