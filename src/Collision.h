#ifndef COLLISION_H
#define COLLISION_H

#include "Player.h"
#include "Terrain.h"

class Collision {
   public:
    Collision();

    void checkTerrainPlayer(Terrain& t, Player& p);
};

#endif  // COLLISION_H