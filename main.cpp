#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/create_map.h"
#include "Headers/SketchConversion.h"

int main()
{
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

    unsigned lag = 0;

    unsigned char level = 0;

    //Similar to lag, used to make the game framerate-independent.
    std::chrono::time_point<std::chrono::steady_clock> previous_time;


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
    SketchConversion sketchConversion;
    srand(static_cast<unsigned>(time(0)));


    sf::RenderWindow window(sf::VideoMode(MAP_WIDTH*CELL_SIZE*SCREEN_RESIZE,MAP_HEIGHT*CELL_SIZE*SCREEN_RESIZE),"PACMAN",sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
    window.setActive(false);
    map = sketchConversion.convert_sketch(map_sketch, pacman);

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
            pacman.draw(window);
            create_map(map,window);


            pacman.update(map);



            window.display();

        }

    }


    return 0;
}
