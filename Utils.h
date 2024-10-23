#ifndef UTILS_H
#define UTILS_H

#include <tuple>
#include <random>
#include <cmath>

class Utils {
public:
    // Generate a random position within a grid
    static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distX(0, gridWidth - 1);
        std::uniform_int_distribution<> distY(0, gridHeight - 1);

        return std::make_tuple(distX(gen), distY(gen));
    }

    // Calculate the Euclidean distance between two positions
    static double calculateDistance(const std::tuple<int, int>& pos1, const std::tuple<int, int>& pos2) {
        int x1, y1, x2, y2;
        std::tie(x1, y1) = pos1;
        std::tie(x2, y2) = pos2;

        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }
};

#endif // UTILS_H
