#pragma once
#include "PacmanTmp.h"
class Ghost
{
    bool movement_mode;
    bool use_door;
    unsigned char direction;
    unsigned char frightened_mode;
    unsigned char frightened_speed_timer;

    unsigned short animation_timer;

    Position position;
    Position home;
    Position home_exit;
    Position target;
public:
    unsigned char id;//private
    Ghost(unsigned char i_id);
    void set_position(short i_x, short i_y);
    void update(unsigned char i_level, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map, Ghost& i_ghost_0, PacmanTmp& i_pacman);
    float get_target_distance(unsigned char i_direction);
    void reset(const Position& i_home, const Position& i_home_exit);
    bool pacman_collision(const Position& i_pacman_position);
    void update_target(unsigned char i_pacman_direction, const Position& i_ghost_0_position, const Position& i_pacman_position);
    void switch_mode();
    int getId();
    void setId(int newId);
    Position get_position();
};

