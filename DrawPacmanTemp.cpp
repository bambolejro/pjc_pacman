#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/DrawPacmanTmp.h"



void DrawPacmanTmp::draw(sf::RenderWindow& i_window,MovingObject* object) {
    sf::CircleShape circle(CELL_SIZE / 2);
    circle.setFillColor(sf::Color(255,255,0));
    circle.setPosition(object->position.x,object->position.y);
    i_window.draw(circle);
};
