#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include "Collision.h"
#include "Player.h"
#include "Renderer.h"
#include "Terrain.h"

class World {
   public:
    Terrain terrain;
    Player player;

    World();
    void draw();
    void update(char inputKey);

   private:
    Renderer renderer;
    Collision collision;
};

#endif
