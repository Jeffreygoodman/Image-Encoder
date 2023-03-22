#pragma once
#include <iostream>
#include <cmath>
#include <bitset>
class FibLFSR {
public:
    FibLFSR(std::string seed);
    int step();
    int generate(int k);
    std::string get_seed();
    friend std::ostream &operator<<(std::ostream &os, const FibLFSR &lfsr);
private:
    std::string seed;
};
