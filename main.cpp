#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
//#include <string>
#include "windows.h"
#include <headers.hpp>

int main()
{
    map_ns::Field field;
    field.generate_map();

    sf::RenderWindow window(sf::VideoMode(window_size_x, window_size_y), "Minesweeper", sf::Style::Close);
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i position = sf::Mouse::getPosition(window);   
                int y = position.x / cell_size;
                int x = position.y / cell_size;

                if (x < map_size_x && x >= 0 && y < map_size_y && y >= 0)
                {
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        if (field.map_view[y][x] != 11 && field.map_view[y][x] == 10) // 11 - flag 10 - close_cell
                        {
                            field.map_view[y][x] = 11;
                        }
                        else if (field.map_view[y][x] == 11)
                        {
                            field.map_view[y][x] = 10;
                        }
                    }

                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        field.map_view[y][x] = field.map_logic[y][x];
                        if (field.map_logic[y][x] == 0)
                        {
                            field.open_around(x, y);
                        }
                        if (field.map_logic[y][x] == 9)
                        {                           
                            for (int y = 0; y < map_size_y; y++)
                            {
                                for (int x = 0; x < map_size_x; x++)
                                {
                                    field.map_view[y][x] = field.map_logic[y][x];      
                                }
                            }
                            
                            field.draw(window);
                            Sleep(1000);
                            map_ns::draw_end_of_game(window, 0);
                           
                            while (window.waitEvent(event))
                            {
                                if (event.type == sf::Event::Closed) { window.close(); }
                                if (event.type == sf::Event::KeyPressed)
                                {
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                                    {
                                        window.close();
                                        main();
                                    }
                                }
                            }
                        }
                      
                    }
                }
            }
        }
        if (field.win())
        {
            while (window.waitEvent(event))
            {
                map_ns::draw_end_of_game(window, 1);
               
                if (event.type == sf::Event::Closed) { window.close(); }

                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        window.close();
                        main();
                    }
                }
            }
        }
        field.draw(window);
    }
}