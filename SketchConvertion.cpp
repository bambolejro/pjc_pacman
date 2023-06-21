#include <array>
#include <string>
#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/SketchConversion.h"


SketchConversion::SketchConversion()
{}



std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>
SketchConversion::convert_sketch(const std::array<std::string, MAP_HEIGHT>& i_map_sketch, std::array<Position, 4>& i_ghost_positions, Pacman &i_pacman)
{
    std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH> output_map{};

    for (unsigned char a = 0; a < MAP_HEIGHT ; a++)
    {
        for (unsigned char b = 0; b < MAP_WIDTH ; b++)
        {
            output_map[b][a] = Cell::Empty;
            switch (i_map_sketch[a][b])
            {
                case ' ':
                {
                    output_map[b][a] = Cell::Empty;
                    break;
                }
                case '#':
                {
                    output_map[b][a] = Cell::Wall;
                    break;
                }
                case 'P':
                {
                    i_pacman.setPosition(CELL_SIZE*b,CELL_SIZE*a);
                    break;
                }
                case '.':
                {
                    output_map[b][a] = Cell::Point;
                    break;
                }
                case 'o':
                {
                    output_map[b][a] = Cell::Energizer;
                }
                    //Red ghost
                case '0':
                {
                    i_ghost_positions[0].x = CELL_SIZE * b;
                    i_ghost_positions[0].y = CELL_SIZE * a;

                    break;
                }
                    //Pink ghost
                case '1':
                {
                    i_ghost_positions[1].x = CELL_SIZE * b;
                    i_ghost_positions[1].y = CELL_SIZE * a;

                    break;
                }
                    //Blue (cyan) ghost
                case '2':
                {
                    i_ghost_positions[2].x = CELL_SIZE * b;
                    i_ghost_positions[2].y = CELL_SIZE * a;

                    break;
                }
                    //Orange ghost
                case '3':
                {
                    i_ghost_positions[3].x = CELL_SIZE * b;
                    i_ghost_positions[3].y = CELL_SIZE * a;

                    break;
                }
            }
        }
    }
    return output_map;
}