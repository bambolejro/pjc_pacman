#pragma once
#include "MovingObject.h"

class DrawMovingObject {
public:
    DrawMovingObject()=default;
    virtual void draw(sf::RenderWindow& i_window,MovingObject* object)=0;
};