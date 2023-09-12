#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Collider.h"
#include "Headers/PacmanTmp.h"
#include "Headers/MovingObject.h"

Collider colider;
PacmanTmp::PacmanTmp() :
        MovingObject(),
        animation_over(0),
        dead(0),
        energizer_timer(0)
{}


bool PacmanTmp::get_animation_over()
{
    return animation_over;
}


void PacmanTmp::reset()
{
    animation_over = 0;
    dead = 0;

    direction = 0;

    animation_timer = 0;
    energizer_timer = 0;
}

unsigned short PacmanTmp::get_energizer_timer()
{
    return energizer_timer;
}

unsigned char PacmanTmp::get_direction()
{
    return direction;
}

void PacmanTmp::set_dead(bool i_dead)
{
    dead = i_dead;

    if (1 == dead)
    {
        //Making sure that the animation starts from the beginning.
        animation_timer = 0;
    }
}

void PacmanTmp::update(unsigned char i_level,std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map) {

    std::array<bool, 4> walls{};
    walls[0] = colider.map_collision(0,0,PACMAN_SPEED + position.x, position.y,i_map);
    walls[1] = colider.map_collision(0,0,position.x, position.y - PACMAN_SPEED,i_map);
    walls[2] = colider.map_collision(0,0,position.x - PACMAN_SPEED, position.y,i_map);
    walls[3] = colider.map_collision(0,0,position.x, PACMAN_SPEED + position.y,i_map);

    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (0 == walls[0]) //You can't turn in this direction if there's a wall there.
        {
            direction = 0;
        }
    }

    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (0 == walls[1])
        {
            direction = 1;
        }
    }

    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (0 == walls[2])
        {
            direction = 2;
        }
    }

    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (0 == walls[3])
        {
            direction = 3;
        }
    }

    if (0 == walls[direction])
    {
        switch (direction)
        {
            case 0:
            {
                position.x += PACMAN_SPEED;

                break;
            }
            case 1:
            {
                position.y -= PACMAN_SPEED;

                break;
            }
            case 2:
            {
                position.x -= PACMAN_SPEED;

                break;
            }
            case 3:
            {
                position.y += PACMAN_SPEED;
            }
        }
    }
    if (-CELL_SIZE >= position.x)
    {
        position.x = CELL_SIZE * MAP_WIDTH - PACMAN_SPEED;
    }
    else if (CELL_SIZE * MAP_WIDTH <= position.x)
    {
        position.x = PACMAN_SPEED - CELL_SIZE;
    }

    if (1 == colider.map_collision(1, 0, position.x, position.y, i_map)) //When PacmanTmp eats an energizer...
    {
        //He becomes energized!
        energizer_timer = static_cast<unsigned short>(ENERGIZER_DURATION / pow(2, i_level));
    }
    else
    {
        energizer_timer = std::max(0, energizer_timer - 1);
    }
}

bool PacmanTmp::get_dead()
{
    return dead;
}






