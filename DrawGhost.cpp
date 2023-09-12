#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/GhostTmp.h"
#include "Headers/DrawGhost.h"


DrawGhost::DrawGhost() :
direction(0)
{}

void DrawGhost::draw(sf::RenderWindow& i_window,Ghost& ghost)
{

    sf::CircleShape ghostek(CELL_SIZE / 2);
    ghostek.setPosition(ghost.get_position().x,ghost.get_position().y);

    switch (ghost.id)
    {
        case 0:
        {
            //Red color
            ghostek.setFillColor(sf::Color(255,120,100));

            break;
        }
        case 1:
        {
            //Pink color
            ghostek.setFillColor(sf::Color(0,0,255));

            break;
        }
        case 2:
        {
            //Cyan color
            ghostek.setFillColor(sf::Color(0,255,0));

            break;
        }
        case 3:
        {
            //Orange color
            ghostek.setFillColor(sf::Color(255,0,0));
        }

    }
    i_window.draw(ghostek);

}