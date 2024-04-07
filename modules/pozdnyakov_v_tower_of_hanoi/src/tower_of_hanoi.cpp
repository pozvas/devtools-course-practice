// Copyright 2024 Pozdnyakov Vasya

#include "include/tower_of_hanoi.h"

std::vector<std::vector<int>> TowerOfHanoi::RecursiveCalculate(int numberOfRings, int fromRod, int toRod) {
    if ((fromRod < 1 && fromRod > 3) || (toRod < 1 && toRod > 3)) {
        throw std::range_error("Number of rods must be 1, 2 or 3");
    }
    if (numberOfRings == 1) {
        return std::vector<std::vector<int>>(1, {fromRod, toRod});
    }

    int unused = 6 - fromRod - toRod;

    std::vector<std::vector<int>> localResult = RecursiveCalculate(numberOfRings - 1, fromRod, unused);
    localResult.push_back({fromRod, toRod});
    std::vector<std::vector<int>> secondRecursiveResult = RecursiveCalculate(numberOfRings - 1, unused, toRod);
    localResult.insert(localResult.end(), secondRecursiveResult.begin(), secondRecursiveResult.end());

    return localResult;
}

std::vector<std::vector<int>> TowerOfHanoi::CalculateSteps(int numberOfRings) {
    if (numberOfRings <= 0) {
        throw std::range_error("Number of rings must be positive");
    }

    return RecursiveCalculate(numberOfRings, 1, 3);
}
