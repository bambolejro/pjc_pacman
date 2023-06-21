
#include <array>
#include <cmath>
#include <iostream>

#include "Headers/Global.h"
#include "Headers/GhostCollider.h"

GhostCollider::GhostCollider()
{}

bool GhostCollider::map_collision(short i_x, short i_y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map)
{
    int a = 0;

    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE);

    //A ghost/Pacman can intersect 4 cells at most.
    for (unsigned char a = 0; a < 4; a++)
    {
        short x = 0;
        short y = 0;

        switch (a)
        {
            case 0: //Top left cell
            {
                x = static_cast<short>(floor(cell_x));
                y = static_cast<short>(floor(cell_y));

                break;
            }
            case 1: //Top right cell
            {
                x = static_cast<short>(ceil(cell_x));
                y = static_cast<short>(floor(cell_y));

                break;
            }
            case 2: //Bottom left cell
            {
                x = static_cast<short>(floor(cell_x));
                y = static_cast<short>(ceil(cell_y));

                break;
            }
            case 3: //Bottom right cell
            {
                x = static_cast<short>(ceil(cell_x));
                y = static_cast<short>(ceil(cell_y));
            }
        }
        if (0 <= x && 0 <= y && MAP_HEIGHT > y && MAP_WIDTH > x)
        {
            if (Cell::Wall == i_map[x][y])
            {
                output = 1;
            }
            else if (Cell::Point == i_map[x][y])
            {
                i_map[x][y] = Cell::Empty;
                a+=1;
                std::cout<<a<<std::endl;
            }
        }
    }
    return output;

}

