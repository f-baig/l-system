#include <SFML/Graphics.hpp>
#include <math.h>
#include "turtle.h"

using namespace::std;

Turtle::Turtle(sf::Vector2f startpos, float startang, float l)
{
    this->turtle_stats = stack<pair<sf::Vector2f, float>>();
    this->turtle_stats.push(make_pair(startpos, startang));
    this->pos = startpos;
    this->ang = startang;
    this->len = l;
}


sf::Vector2f Turtle::draw_turtle(float length, sf::RenderWindow &window) {
    sf::Vector2f start = this->pos;
    float angle = this->ang;

    float ator = angle * ((2 * M_PI) / 360);

    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(start.x, start.y);
    lines[1].position = sf::Vector2f(start.x + length * cos(ator), start.y - length * sin(ator));

    window.draw(lines);

    return lines[1].position;
}

string Turtle::create_production(string s, int generations) {
    string n;
    for (int j = 0; j < generations; j++) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                n += "1[0]0";
            }
            if (s[i] == '1') {
                n += "11";
            }
            if (s[i] == '[') {
                n += '[';
            }
            if (s[i] == ']') {
                n += ']';
            }
        }
        s = n;
        n = "";
    }
    return s;
}

void Turtle::move_turtle(string s, sf::RenderWindow &window) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            this->pos = draw_turtle(this->len, window);
        }
        if (s[i] == '0') {
            this->pos = draw_turtle(this->len / 2, window);
        }
        if (s[i] == '[') {
            this->turtle_stats.push(make_pair(this->pos, this->ang));
            this->ang += 45;
        }
        if (s[i] == ']') {
            this->pos = this->turtle_stats.top().first;
            this->ang = this->turtle_stats.top().second;
            this->ang -= 45;
            this->turtle_stats.pop();
        }
    }
}