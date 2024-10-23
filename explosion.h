#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "GameEntity.h"
#include "Effect.h"
#include <iostream>

class Explosion : public GameEntity, public Effect {
public:
    // Constructor for Explosion at (x, y)
    Explosion(int x, int y)
        : GameEntity(x, y, GameEntityType::ExplosionType) {}

    // Apply the explosion effect to a GameEntity, marking it as destroyed
    void apply(GameEntity& entity) override {
        std::cout << "Explosion at (" << std::get<0>(getPos()) << ", " << std::get<1>(getPos()) << ") applied!\n";
        entity = GameEntity(-1, -1, GameEntityType::NoneType); // Destroy the entity
        std::cout << "The entity is destroyed and moved to (-1, -1) with type NoneType.\n";
    }
};

#endif // EXPLOSION_H
