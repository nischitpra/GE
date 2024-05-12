#include "World.h"

#include <sstream>

World::World() : collision(), renderer(), terrain(), player() {}

// perform physics
void World::update(char inputKey) {
    player.inputKey(inputKey);
    collision.checkTerrainPlayer(terrain, player);
}

void World::draw() {
    terrain.draw(renderer.grid);
    player.draw(renderer.grid);

    renderer.draw();
}
