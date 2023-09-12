#pragma once
#include "PacmanTmp.h"
#include "DrawMovingObject.h"

class DrawPacmanTmp: public DrawMovingObject
{
public:
    DrawPacmanTmp();
    void draw(sf::RenderWindow& i_window,MovingObject* object) override;
};



