#pragma once


class Pacman
{
    unsigned char direction;
    bool animation_over;
    bool dead;
    unsigned short animation_timer;
    unsigned short energizer_timer;


public:
    Pacman();
    Position position; // przenieś do prywatnej
    bool get_animation_over();
    void setPosition( int i_x,  int i_y);
    void update(unsigned char i_level, std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH>& i_map);
    unsigned short get_energizer_timer();
    void reset();
    unsigned char get_direction();
    void set_dead(bool i_dead);
    bool get_dead();
    Position get_position();
};


