#include "FibLFSR.hpp"

// string seed;
//  Constructor to create LFSR with the given initial seed
FibLFSR::FibLFSR(std::string seed)
{
    this->seed = seed;
}
std::string FibLFSR::get_seed()
{
return seed;
}
// Simulate one step and return the new bit as 0 or 1
int FibLFSR::step()
{
    int result = seed[0] ^ seed[2] ^ seed[3] ^ seed[5];
    int temp = std::stoi(this->seed, 0, 2);
    temp <<= 1;
    std::string binaryRepr = std::bitset<16>(temp).to_string();
    binaryRepr[15] = result + '0';
    this->seed = binaryRepr;
    return result;
}


// Simulate k steps and return a k-bit integer
int FibLFSR::generate(int k)
{
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        result += step() * pow(2, k-i-1);
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const FibLFSR &lfsr)
{
    os << lfsr.seed;
    return os;
}
