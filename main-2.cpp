#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"
#include <iostream>

int main() {
    // Create a Ship at position (2, 3)
    Ship myShip(2, 3);
    std::cout << "Ship created at position (" << std::get<0>(myShip.getPos()) << ", " << std::get<1>(myShip.getPos()) << ")\n";

    // Move the ship to a new position (by dx = 2, dy = 1)
    myShip.move(2, 1);

    // Create a Mine at position (4, 5)
    Mine myMine(4, 5);
    std::cout << "Mine created at position (" << std::get<0>(myMine.getPos()) << ", " << std::get<1>(myMine.getPos()) << ")\n";

    // Trigger the mine to explode
    Explosion explosion = myMine.explode();

    // Apply the explosion effect to the ship
    explosion.apply(myShip);

    // Print the ship's new position and type after explosion
    std::cout << "After explosion, Ship's position: (" << std::get<0>(myShip.getPos()) << ", " << std::get<1>(myShip.getPos()) << ") and type: NoneType.\n";

    return 0;
}
