#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/Ghost.h"
#include "Headers/GhostManager.h"

GhostManager::GhostManager() :
        ghosts({Ghost(0), Ghost(1), Ghost(2), Ghost(3)})
{

}

void GhostManager::draw(sf::RenderWindow& i_window)
{
    for (Ghost& ghost : ghosts)
    {
        ghost.draw(i_window);
    }
}

void GhostManager::reset(const std::array<Position, 4>& i_ghost_positions)
{

    for (unsigned char a = 0; a < 4; a++)
    {
        ghosts[a].set_position(i_ghost_positions[a].x, i_ghost_positions[a].y);
        std::cout<<i_ghost_positions[a].y<<std::endl;
    }


//    for (Ghost& ghost : ghosts)
//    {
//        //We use the blue ghost to get the location of the house and the red ghost to get the location of the exit.
//        ghost.reset(ghosts[2].get_position(), ghosts[0].get_position());
//    }
}