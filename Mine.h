#ifndef MINE_H
#define MINE_H

#include "GameEntity.h"
#include "Explosion.h"
#include <iostream>

class Mine : public GameEntity {
public:
    // Constructor for Mine at (x, y)
    Mine(int x, int y)
        : GameEntity(x, y, GameEntityType::MineType) {}

    // Function to trigger an explosion and mark the mine as inactive
    Explosion explode() {
        std::cout << "Mine at (" << std::get<0>(getPos()) << ", " << std::get<1>(getPos()) << ") exploded!\n";
        *this = Mine(-1, -1); // Mark the mine as inactive by moving it out of the grid and setting type to None
        return Explosion(std::get<0>(getPos()), std::get<1>(getPos()));
    }
};

#endif // MINE_H

