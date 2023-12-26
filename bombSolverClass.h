#pragma once

#include <vector>
#include <cstddef>

class Point {
public:
    int x;
    int y;
    int r;

    Point(int x1, int y1, int r1) : x(x1), y(y1), r(r1) {}

    bool isInRange(const Point& other) const {
        return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) <= (r * r);
    }
};

class BombsSolver {
public:
    int findMaxDetonations(const std::vector<Point>& points);

private:
    void detonateBombsRecursively(const std::vector<Point>& bombs, std::vector<bool>& detonated, size_t current, int& count);
};
