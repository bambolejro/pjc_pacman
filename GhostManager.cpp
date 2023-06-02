#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/Ghost.h"
#include "Headers/DrawGhost.h"
#include "Headers/GhostManager.h"


GhostManager::GhostManager() :
        ghosts({Ghost(0), Ghost(1), Ghost(2), Ghost(3)})
{

}

void GhostManager::select_ghost_to_draw(sf::RenderWindow& i_window)
{
    for (Ghost& ghost : ghosts)
    {
        drawGhost.draw(i_window,ghost);
    }
}

void GhostManager::reset(const std::array<Position, 4>& i_ghost_positions)
{

    for (unsigned char a = 0; a < 4; a++)
    {
        ghosts[a].set_position(i_ghost_positions[a].x, i_ghost_positions[a].y);
        std::cout<<i_ghost_positions[a].y<<std::endl;
    }


    for (Ghost& ghost : ghosts)
    {
        //We use the blue ghost to get the location of the house and the red ghost to get the location of the exit.
        ghost.reset(ghosts[2].get_position(), ghosts[0].get_position());
    }
}

void GhostManager::update(unsigned char i_level,std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map,Pacman& i_pacman )
{
//    if (0 == i_pacman.get_energizer_timer()) //We won't update the wave timer when Pacman is energized.
//    {
//        if (0 == wave_timer)
//        {
//            if (7 > current_wave)
//            {
//                current_wave++;
//
//                for (Ghost& ghost : ghosts)
//                {
//                    ghost.switch_mode();
//                }
//            }
//
//            //I took the rules from the website.
//            if (1 == current_wave % 2)
//            {
//                wave_timer = CHASE_DURATION;
//            }
//            else if (2 == current_wave)
//            {
//                wave_timer = static_cast<unsigned short>(LONG_SCATTER_DURATION / pow(2, i_level));
//            }
//            else
//            {
//                wave_timer = static_cast<unsigned short>(SHORT_SCATTER_DURATION / pow(2, i_level));
//            }
//        }
//        else
//        {
//            wave_timer--;
//        }
//    }

    for (Ghost& ghost : ghosts)
    {
        ghost.update(i_level, i_map, ghosts[0], i_pacman);
    }
}