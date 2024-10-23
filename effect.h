#ifndef EFFECT_H
#define EFFECT_H

#include "GameEntity.h"
#include <iostream>

// ExplosionEffect derived from Effect
class ExplosionEffect : public Effect {
public:
    // Constructor
    ExplosionEffect(int damage) : damage(damage) {}

    // Apply effect to a game entity (assumes it deals damage in some way)
    void apply(GameEntity& entity) override {
        if (entity.getType() == GameEntityType::ShipType) {
            std::cout << "Explosion effect applied! Ship took " << damage << " damage.\n";
        } else {
            std::cout << "Explosion effect applied! No significant damage to this entity type.\n";
        }
    }

private:
    int damage; // Damage dealt by the explosion
};

// MineEffect derived from Effect
class MineEffect : public Effect {
public:
    // Constructor
    MineEffect(int blastRadius) : blastRadius(blastRadius) {}

    // Apply effect to a game entity (assumes it affects entities within a radius)
    void apply(GameEntity& entity) override {
        if (entity.getType() == GameEntityType::ShipType) {
            std::cout << "Mine exploded! Ship is within a blast radius of " << blastRadius << ".\n";
        } else {
            std::cout << "Mine exploded! No impact on this entity type.\n";
        }
    }

private:
    int blastRadius; // Blast radius of the mine
};

#endif // EFFECT_H
