#pragma once



class GhostCollider
{
public:
    GhostCollider();
    bool map_collision(short i_x, short i_y,std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map);
};
