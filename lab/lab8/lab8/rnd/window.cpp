#include "shapes.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Random window");
    Shapes shapes;
    shapes.generate();

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        };
        window.clear();
        shapes.update();
        shapes.render(window);
        window.display();
    }

    return 0;
}