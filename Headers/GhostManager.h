#pragma once

class GhostManager
{
    std::array<Ghost, 4> ghosts;
    DrawGhost drawGhost;
    Pacman pacman;
public:
    GhostManager();

    void select_ghost_to_draw(sf::RenderWindow& i_window);
    void reset(const std::array<Position, 4>& i_ghost_positions);
    void update(unsigned char i_level,std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map, Pacman& i_pacman);
};