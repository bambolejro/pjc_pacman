#pragma once


class Pacman
{
    unsigned char direction;
    bool animation_over;
    //Am I dead?
    bool dead;
    //More timers!
    unsigned short animation_timer;
    unsigned short energizer_timer;

    //Current location of this creature, commonly known as Pacman.

public:
    Pacman();
    Position position;
    void setPosition( int i_x,  int i_y);
    void update(std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH>& i_map);
    unsigned short get_energizer_timer();
    unsigned char get_direction();
    void set_dead(bool i_dead);
    Position get_position();
};


