#include <iostream>
#include <SFML/Graphics.hpp>

#include "turtle.h"

using namespace std;

int main() {
    sf::RenderWindow mainWindow(sf::VideoMode(500, 500), "Lindenmayer System");
    mainWindow.setFramerateLimit(60);

    while (mainWindow.isOpen()) {
        sf::Event event;

        while (mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }

        mainWindow.clear();

        int gens = 10;

        sf::Vector2f startpos(250, 500);
        float startang = 90;
        float l = 2 * mainWindow.getSize().y / (5 * (pow(2, gens - 1)));

        Turtle *t = new Turtle(startpos, startang, l);

        t->move_turtle(t->create_production("0", gens), mainWindow);

        mainWindow.display();
    }



    return 0;
}
