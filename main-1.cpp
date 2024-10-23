#include "GameEntity.h"
#include "Utils.h"
#include <iostream>

int main() {
    // Define grid size
    int gridWidth = 10;
    int gridHeight = 10;

    // Generate random positions
    auto pos1 = Utils::generateRandomPos(gridWidth, gridHeight);
    auto pos2 = Utils::generateRandomPos(gridWidth, gridHeight);

    // Print positions
    std::cout << "Position 1: (" << std::get<0>(pos1) << ", " << std::get<1>(pos1) << ")\n";
    std::cout << "Position 2: (" << std::get<0>(pos2) << ", " << std::get<1>(pos2) << ")\n";

    // Calculate and print the distance between the positions
    double distance = Utils::calculateDistance(pos1, pos2);
    std::cout << "Distance between pos1 and pos2: " << distance << "\n";

    return 0;
}
