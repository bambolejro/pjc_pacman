#pragma once
#include "MovingObject.h"

class DrawMovingObject {
public:
    DrawMovingObject();
    virtual void draw(sf::RenderWindow& i_window,MovingObject* object);
};