#include <array>
#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/create_map.h"


void create_map(const std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH>& i_map, sf::RenderWindow& window)
{
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE,CELL_SIZE));
    sf::CircleShape point(4);
    for (unsigned char i = 0;i<MAP_WIDTH;i++)
    {
        for(unsigned char j = 0;j<MAP_HEIGHT;j++)
        {
            cell.setPosition(CELL_SIZE*i, CELL_SIZE*j);
            point.setPosition(CELL_SIZE*i, CELL_SIZE*j);
            switch (i_map[i][j]) {
                case Cell::Wall:
                {
                    cell.setFillColor(sf::Color(36,36,255));
                    window.draw(cell);
                }
                case Cell::Point:
                {
                    point.setFillColor(sf::Color(36,36,255));
                    window.draw(point);
                    break;
                }

            }

        }

    }

}