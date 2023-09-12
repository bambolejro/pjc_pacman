#pragma once
#include "Global.h"

class MovingObject
{
protected:
    unsigned char direction;
    unsigned short animation_timer;

public:
    Position position;
    MovingObject()=default;
    ~MovingObject()=default;
    virtual void setPosition(short i_x, short i_y);
    virtual Position get_position();
};
