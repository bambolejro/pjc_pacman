#pragma once


class Pacman
{
    unsigned char direction;
    Position position;

public:
    Pacman();
    void draw(sf::RenderWindow& window);
    void setPosition( int i_x,  int i_y);
    void update(std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH>& i_map);
    Position get_position();
};



