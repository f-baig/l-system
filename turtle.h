#include <SFML/Graphics.hpp>
#include <stack>

using namespace std;

#ifndef LMT_TURTLE_H
#define LMT_TURTLE_H

class Turtle {
public:

    Turtle(sf::Vector2f startpos, float startang, float l);

    sf::Vector2f draw_turtle(float length, sf::RenderWindow &window);

    string create_production(string s, int generations = 1);

    void move_turtle(string s, sf::RenderWindow &window);

private:

    stack<pair<sf::Vector2f, float>> turtle_stats;
    float len;
    float ang;
    sf::Vector2f pos;

};

#endif //LMT_TURTLE_H
