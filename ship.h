#ifndef SHIP_H
#define SHIP_H

#include "GameEntity.h"
#include <iostream>

class Ship : public GameEntity {
public:
    // Constructor for Ship at (x, y)
    Ship(int x, int y)
        : GameEntity(x, y, GameEntityType::ShipType) {}

    // Function to move the ship by dx, dy
    void move(int dx, int dy) {
        auto pos = getPos();
        int newX = std::get<0>(pos) + dx;
        int newY = std::get<1>(pos) + dy;
        std::cout << "Ship moved from (" << std::get<0>(pos) << ", " << std::get<1>(pos) << ") to (" << newX << ", " << newY << ").\n";
        *this = Ship(newX, newY); // Move the ship to the new position
    }
};

#endif // SHIP_H
