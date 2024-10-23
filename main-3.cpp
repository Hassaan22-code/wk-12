#include "Game.h"

int main() {
    // Create a Game object
    Game game;

    // Initialize the game with 2 ships, 2 mines, and a 10x10 grid
    std::vector<GameEntity*> entities = game.initGame(2, 2, 10, 10);

    // Print initial positions of the entities
    std::cout << "Initial Game Entities:\n";
    for (auto entity : entities) {
        std::cout << "Entity of type " << static_cast<int>(entity->getType()) 
                  << " at position (" << std::get<0>(entity->getPos()) << ", " 
                  << std::get<1>(entity->getPos()) << ")\n";
    }

    // Run the game loop for a maximum of 5 iterations and a mine detection threshold of 2.0 units
    game.gameLoop(5, 2.0);

    // Clean up dynamically allocated entities
    for (auto entity : entities) {
        delete entity;
    }

    return 0;
}
