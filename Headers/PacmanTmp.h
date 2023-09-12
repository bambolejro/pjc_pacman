#pragma once
#include "MovingObject.h"
#include "Global.h"

class PacmanTmp : public MovingObject
{
    bool animation_over;
    bool dead;
    unsigned short energizer_timer;


public:
    PacmanTmp();
    bool get_animation_over();
    void update(unsigned char i_level, std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH>& i_map);
    unsigned short get_energizer_timer();
    void reset();
    unsigned char get_direction();
    void set_dead(bool i_dead);
    bool get_dead();
};


