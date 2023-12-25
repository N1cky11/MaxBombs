#include <iostream>
#include <vector>
#include <algorithm>
#include "BombSolverClass.h"
#include <algorithm>

void BombsSolver::detonateBombsRecursively(const std::vector<Point>& bombs, std::vector<bool>& detonated, size_t current, int& count) {
    if (current >= bombs.size() || detonated[current])
        return;

    detonated[current] = true;

    for (size_t i = 0; i < bombs.size(); ++i) {
        if (!detonated[i] && bombs[current].isInRange(bombs[i])) {
            detonateBombsRecursively(bombs, detonated, i, ++count);
        }
    }
}

int BombsSolver::findMaxDetonations(const std::vector<Point>& points) {
    int maxCount = 0;
    std::vector<bool> detonated(points.size(), false);

    for (size_t i = 0; i < points.size(); ++i) {
        int count = 1;
        std::fill(detonated.begin(), detonated.end(), false);
        detonateBombsRecursively(points, detonated, i, count);
        maxCount = std::max(count, maxCount);
    }

    return maxCount;
}
