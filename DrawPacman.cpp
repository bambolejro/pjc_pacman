#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/DrawPacman.h"


DrawPacman::DrawPacman()
{}
void DrawPacman::draw(sf::RenderWindow& window,Pacman& pacek) {
    sf::CircleShape circle(CELL_SIZE / 2);
    circle.setFillColor(sf::Color(255,255,0));
    circle.setPosition(pacek.position.x,pacek.position.y);
    window.draw(circle);
}

