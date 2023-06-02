#pragma once



class Collider
{
public:
    Collider();
    bool map_collision(bool collect_pts,bool i_use_door,short i_x, short i_y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map);
    bool pointer(short i_x, short i_y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map,bool output);
};
