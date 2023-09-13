#pragma once

#include "DrawGhostTmp.h"
#include "DrawMovingObject.h"

class DrawGhostTmp: public DrawMovingObject
{
public:
    DrawGhostTmp()=default;
    void draw(sf::RenderWindow& i_window,MovingObject* object) override;
};



