#pragma once

#include "rnd.h"

#include <SFML/Graphics.hpp>
#include <vector>

sf::Shape *create(char type);

class Shapes
{
public:
    Shapes(size_t nums = 500) : nums_{nums} {}
    ~Shapes();

    // no copy
    Shapes(Shapes const &) = delete;
    Shapes &operator=(Shapes const &) = delete;
    // no move
    Shapes(Shapes &&) = delete;
    Shapes &operator=(Shapes &&) = delete;
    
    void generate();

    void update();

    void render(sf::RenderWindow &window);

private:
    size_t nums_{100};
    std::vector<sf::Shape *> items_;
};