#include "bombSolverClass.h"
#include <iostream>
#include <vector>


int main() {
    std::vector<Point> points{Point(2,1,3), Point(6,1,4)};
    BombsSolver bombsSolver;
    std::cout << bombsSolver.findMaxDetonations(points);
    return 0;
}
