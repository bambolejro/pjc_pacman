#pragma once


class DrawGhost
{
    int direction;
public:
    DrawGhost();
    void draw(sf::RenderWindow& i_window,Ghost& ghost);
};



