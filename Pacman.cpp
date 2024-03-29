
#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Collider.h"
#include "Headers/Pacman.h"

Collider colider;

Pacman::Pacman() :
        direction(0),
        position({0, 0})
{}

void Pacman::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(CELL_SIZE / 2);
    circle.setFillColor(sf::Color(255,255,0));
    circle.setPosition(position.x,position.y);
    window.draw(circle);

}

void Pacman::setPosition( int i_x, int i_y) {
    position = {i_x,i_y};

}

void Pacman::update(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map) {

    std::array<bool, 4> walls{};
    walls[0] = colider.map_collision(PACMAN_SPEED + position.x, position.y,i_map);
    walls[1] = colider.map_collision(position.x, position.y - PACMAN_SPEED,i_map);
    walls[2] = colider.map_collision(position.x - PACMAN_SPEED, position.y,i_map);
    walls[3] = colider.map_collision(position.x, PACMAN_SPEED + position.y,i_map);

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


}




