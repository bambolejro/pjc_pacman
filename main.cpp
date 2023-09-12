#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Global.h"
#include "Headers/Pacman.h"
#include "Headers/GhostTmp.h"

#include "Headers/DrawMap.h"
#include "Headers/SketchConversion.h"
#include "Headers/DrawGhost.h"
#include "Headers/DrawPointsState.h"
#include "Headers/GhostManager.h"
#include "Headers/PacmanTmp.h"
#include "Headers/DrawMovingObject.h"
#include "Headers/DrawPacmanTmp.h"

#include "Headers/MovingObject.h"



int main() {
    bool game_won = 0;
    unsigned char level = 0;
    unsigned lag = 0;
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

//    MovingObject* pacman = new PacmanTmp();
    PacmanTmp pacman;
//    Ghost(0);
    GhostManager ghost_manager;
    SketchConversion sketchConversion;
    DrawMovingObject* drawPacman = new DrawPacmanTmp();
//    DrawPacmanTmp drawPacman;
    // DrawMovingObject* drawPacman = new DrawPacman;
    DrawMap drawMap;
    DrawPointsState drawPointsState;

    srand(static_cast<unsigned>(time(0)));


    sf::RenderWindow window(
            sf::VideoMode(MAP_WIDTH * CELL_SIZE * SCREEN_RESIZE, MAP_HEIGHT * CELL_SIZE * SCREEN_RESIZE), "PACMAN",
            sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
//    window.setActive(false);

    map = sketchConversion.convert_sketch(map_sketch, ghost_positions, pacman);

    ghost_manager.reset(ghost_positions);

    while (window.isOpen())
    {
        unsigned delta_time = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::steady_clock::now() - previous_time).count();
        lag += delta_time;
        previous_time += std::chrono::microseconds(delta_time);

        sf::Event evmt;
        while (FRAME_DURATION <= lag)
        {
            lag -= FRAME_DURATION;
            while (window.pollEvent(evmt))
            {
                if (evmt.type == evmt.Closed) {

                    window.close();
                }
//                window.clear();
//                drawPacman.draw(window, pacman);
//            ghost_manager.draw(GHOST_FLASH_START >= 0, window);
//                drawMap.create_map(map, window);
//                ghost_manager.select_ghost_to_draw(window);
//                ghost_manager.update(level, map, pacman);
//                pacman.update(level, map);
//                window.display();
            }
            if (0 == game_won && 0 == pacman.get_dead())
            {
                game_won = 1;

                pacman.update(level, map);

                ghost_manager.update(level, map, pacman);

                for (const std::array<Cell, MAP_HEIGHT> &column: map)
                {
                    for (const Cell &cell: column) {
                        if (Cell::Point == cell) //jeśli został chociaż jeden punkcik do zebrania
                        {
                            game_won = 0; //gra nie jest jeszcze wygrana

                            break;
                        }
                    }

                    if (0 == game_won) {
                        break;
                    }
                }

            }
            else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) //Restarting the game.
            {
                game_won = 0;

                if (1 == pacman.get_dead())
                {
                    level = 0;
                }
                else
                {
                    //Po każdej wygranej zmniejsza sie czas fal ataku i energizerów
                    level++;
                }

                map = sketchConversion.convert_sketch(map_sketch, ghost_positions, pacman);

                ghost_manager.reset(ghost_positions);

                pacman.reset();
            }

            if (FRAME_DURATION > lag)
            {
                window.clear();

                if (0 == game_won && 0 == pacman.get_dead())
                {
                    drawMap.create_map(map, window);

                    ghost_manager.select_ghost_to_draw( window);

                    drawPointsState.draw_text(0, 0, CELL_SIZE * MAP_HEIGHT, "Level: " + std::to_string(1 + level),
                                              window);
                }

                drawPacman->draw(window, &pacman);

                if (1 == pacman.get_animation_over())
                {
                    if (1 == game_won) {
                        drawPointsState.draw_text(1, 0, 0, "Next level!", window);
                    } else {
                        drawPointsState.draw_text(1, 0, 0, "Game over", window);
                    }
                }

                window.display();
            }
        }
    }
}