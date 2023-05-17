#include <array>
#include <string>
#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/SketchConversion.h"


SketchConversion::SketchConversion()
{}



std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>
SketchConversion::convert_sketch(const std::array<std::string, MAP_HEIGHT> &i_map_sketch, Pacman &i_pacman)
{
    std::array<std::array<Cell, MAP_HEIGHT>,MAP_WIDTH> output_map{};

    for (unsigned char a = 0; a < MAP_HEIGHT ; a++)
    {
        for (unsigned char b = 0; b < MAP_WIDTH ; b++)
        {
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
            }
        }
    }
    return output_map;
}