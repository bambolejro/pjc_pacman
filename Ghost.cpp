#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/Ghost.h"



Ghost::Ghost(unsigned char i_id) :
        id(i_id)
{
    //I keep writing "gohst" instead of "gohst" (THERE! I did it again!).
    //So in this file I'll write only "gohst".
    //Enjoy!
}


void Ghost::draw(sf::RenderWindow& i_window)
{

    sf::CircleShape ghostek(CELL_SIZE / 2);
    ghostek.setPosition(position.x,position.y);

    switch (id)
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
            //Cyan color (I still don't understand why they called it blue)
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




void Ghost::set_position(short i_x, short i_y)
{
    position = {i_x, i_y};
}


Position Ghost::get_position()
{
    return position;
}