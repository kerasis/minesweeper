#include <headers.hpp>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "windows.h"


void map_ns::draw_end_of_game(sf::RenderWindow& i_window, bool won)
{
	if (won)
	{
		sf::Texture win_texture;
		win_texture.loadFromFile("win.png");
		sf::Sprite win_sprite(win_texture);

		win_sprite.setTextureRect(sf::IntRect(0, 0, 160, 160));
		win_sprite.setPosition(map_size_y * cell_size / 2 - 80, map_size_x * cell_size / 2 - 80);

		i_window.clear(sf::Color::White);
		i_window.draw(win_sprite);
		i_window.display();
	}
	else
	{
		sf::Texture lost_texture;
		lost_texture.loadFromFile("lost.png");
		sf::Sprite lost_sprite(lost_texture);

		lost_sprite.setTextureRect(sf::IntRect(0, 0, 160, 160));
		lost_sprite.setPosition(map_size_y * cell_size / 2 - 80, map_size_x * cell_size / 2 - 80);

		i_window.clear(sf::Color::Black);
		i_window.draw(lost_sprite);
		i_window.display();
	}
}




