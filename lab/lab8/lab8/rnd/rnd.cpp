#include "rnd.h"

#include <random>

float rnd()
{
    static std::random_device seed_gen;
    static std::mt19937 engine(seed_gen());
    static std::uniform_real_distribution<float> dist(0, 1.0f);

    return dist(engine);
}