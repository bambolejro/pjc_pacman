#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/Ghost.h"

#include "Headers/create_map.h"
#include "Headers/SketchConversion.h"
#include "Headers/DrawPacman.h"
#include "Headers/DrawGhost.h"
#include "Headers/GhostManager.h"


int main()
{
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

    std::chrono::time_point<std::chrono::steady_clock> previous_time;

    std::array<Position, 4> ghost_positions;
    std::array<std::string, MAP_HEIGHT> map_sketch = {
            " ################### ",
            " #........#........# ",
            " #o##.###.#.###.##o# ",
            " #.................# ",
            " #.##.#.#####.#.##.# ",
            " #....#...#...#....# ",
            " ####.### # ###.#### ",
            "    #.#   0   #.#    ",
            "#####.# ##=## #.#####",
            "     .  #123#  .     ",
            "#####.# ##### #.#####",
            "    #.#       #.#    ",
            " ####.# ##### #.#### ",
            " #........#........# ",
            " #.##.###.#.###.##.# ",
            " #o.#.....P.....#.o# ",
            " ##.#.#.#####.#.#.## ",
            " #....#...#...#....# ",
            " #.######.#.######.# ",
            " #.................# ",
            " ################### "
    };

    Pacman pacman;
    GhostManager ghost_manager;
    SketchConversion sketchConversion;
    DrawPacman drawPacman;
    DrawMap drawMap;
//    DrawGhost drawGhost;
    srand(static_cast<unsigned>(time(0)));


    sf::RenderWindow window(sf::VideoMode(MAP_WIDTH*CELL_SIZE*SCREEN_RESIZE,MAP_HEIGHT*CELL_SIZE*SCREEN_RESIZE),"PACMAN",sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
    window.setActive(false);

    map = sketchConversion.convert_sketch(map_sketch,ghost_positions, pacman);
    ghost_manager.reset(ghost_positions);

    while (window.isOpen())
    {
        sf::Event evmt;
        while (window.pollEvent(evmt))
        {
            if(evmt.type == evmt.Closed)
            {

                window.close();
            }
            window.clear();
            drawPacman.draw(window,pacman);
//            ghost_manager.draw(GHOST_FLASH_START >= 0, window);
            drawMap.create_map(map,window);
            ghost_manager.draw(window);
            pacman.update(map);
//            ghost_manager.reset(0, ghost_positions);
            window.display();

        }

    }


    return 0;
}
