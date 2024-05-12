#ifndef RENDERER_H
#define RENDERER_H

#include <sstream>
#include <vector>

#include "constants.h"

class Renderer {
   public:
    char grid[HEIGHT][WIDTH];

    Renderer();
    void draw() const;
};

#endif