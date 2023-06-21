#include <array>
#include <SFML/Graphics.hpp>
#include "Headers/Global.h"
#include "Headers/DrawMap.h"

DrawMap :: DrawMap(){};

void DrawMap :: create_map(const std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH>& i_map, sf::RenderWindow& window)
{
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE,CELL_SIZE));
    sf::CircleShape point(CELL_SIZE/8);
    sf::RectangleShape energizer(sf::Vector2f(CELL_SIZE/4,CELL_SIZE/4));
    for (unsigned char i = 0;i<MAP_WIDTH;i++)
    {
        for(unsigned char j = 0;j<MAP_HEIGHT;j++)
        {
            cell.setPosition(CELL_SIZE*i, CELL_SIZE*j);
//            point.setPosition(static_cast<float>(CELL_SIZE * i), static_cast<float>(CELL_SIZE * j));
            switch (i_map[i][j]) {
                case Cell::Wall:
                {
                    cell.setFillColor(sf::Color(36,36,255));
                    window.draw(cell);
                    break;
                }
                case Cell::Point:
                {
                    point.setFillColor(sf::Color(255,255,0));
                    point.setPosition(CELL_SIZE*i+(CELL_SIZE/2-point.getRadius()),CELL_SIZE*j+(CELL_SIZE/2-point.getRadius()));
//                    std::cout<<CELL_SIZE*i+(CELL_SIZE/2-point.getRadius())<<std::endl;
//                    if (i_map[CELL_SIZE*i+(CELL_SIZE/2-point.getRadius())][CELL_SIZE*j+(CELL_SIZE/2-point.getRadius())]=='.'){
                    window.draw(point);
//                    }
                    break;
                }
                case Cell::Energizer:
                {
                    energizer.setFillColor(sf::Color(255,0,0));
                    energizer.setPosition(CELL_SIZE*i+(CELL_SIZE/2-point.getRadius()),CELL_SIZE*j+(CELL_SIZE/2-point.getRadius()));
                    window.draw(energizer);
                }

            }

        }

    }

}