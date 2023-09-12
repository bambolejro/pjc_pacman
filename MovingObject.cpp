#include "Headers/MovingObject.h"

Position MovingObject::get_position(){
    return position;
}

void MovingObject::setPosition(short i_x, short i_y) {
    position = {i_x,i_y};
}