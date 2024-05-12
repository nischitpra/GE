#include "Collision.h"

Collision::Collision() {}

void Collision::checkTerrainPlayer(Terrain& t, Player& p) {
    if (t.hasCollision(p.nextX, p.nextY)) return;
    p.commit();
}