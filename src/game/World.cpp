#include <sstream>

#include "globals.h"

World::World() {}

// perform physics
void World::update(char inputKey) { player.inputKey(inputKey); }

void World::draw() {
    terrain.draw();
    player.draw();

    renderer.draw();
}
