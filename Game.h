#ifndef GAME_H
#define GAME_H

#include "Ship.h"
#include "Mine.h"
#include "Utils.h"
#include <vector>
#include <iostream>

class Game {
public:
    // Getters and setters for the entities vector
    const std::vector<GameEntity*>& get_entities() const {
        return entities;
    }

    void set_entities(const std::vector<GameEntity*>& newEntities) {
        entities = newEntities;
    }

    // Initialize the game with the specified number of ships and mines
    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        for (int i = 0; i < numShips; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(std::get<0>(pos), std::get<1>(pos)));
        }

        for (int i = 0; i < numMines; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(std::get<0>(pos), std::get<1>(pos)));
        }

        return entities;
    }

    // Simulate the game loop
    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        for (int iteration = 0; iteration < maxIterations; ++iteration) {
            std::cout << "Game iteration " << iteration + 1 << "\n";

            // Move all Ship objects
            for (auto entity : entities) {
                if (auto* ship = dynamic_cast<Ship*>(entity)) {
                    ship->move(1, 0); // Move ship by (1, 0)
                }
            }

            // Check for proximity between Ship and Mine
            for (auto entity1 : entities) {
                if (auto* ship = dynamic_cast<Ship*>(entity1)) {
                    for (auto entity2 : entities) {
                        if (auto* mine = dynamic_cast<Mine*>(entity2)) {
                            double distance = Utils::calculateDistance(ship->getPos(), mine->getPos());
                            if (distance < mineDistanceThreshold) {
                                std::cout << "Ship is within distance of mine! Triggering explosion.\n";
                                Explosion explosion = mine->explode(); // Trigger mine explosion
                                explosion.apply(*ship); // Apply the explosion to the ship
                            }
                        }
                    }
                }
            }

            // Check if all ships are destroyed
            bool allShipsDestroyed = true;
            for (auto entity : entities) {
                if (auto* ship = dynamic_cast<Ship*>(entity)) {
                    if (ship->getType() != GameEntityType::NoneType) {
                        allShipsDestroyed = false;
                        break;
                    }
                }
            }

            if (allShipsDestroyed) {
                std::cout << "All ships destroyed. Ending game.\n";
                break;
            }
        }
    }

private:
    std::vector<GameEntity*> entities; // Vector to store game entities
};

#endif // GAME_H
