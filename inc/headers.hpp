#pragma once
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


const int cell_size = 32;
const int map_size_x = 10; 
const int map_size_y = 5;
const int window_size_x = map_size_y*cell_size;
const int window_size_y = map_size_x * cell_size ;



namespace map_ns {
	class Field
	{
	public:
		int map_logic[map_size_y][map_size_x];
		int map_view[map_size_y][map_size_x];
		int dementions[8][2] = { { -1, -1 },
						{ -1, 0 },
						{ -1, 1 },
						{ 0, -1 },
						{ 0, 1 },
						{ 1, -1 },
						{ 1, 0 },
						{ 1, 1 } };
		void generate_map();
		void set_numbers();
		void open_around(int x, int y);
		bool win();
		void draw(sf::RenderWindow& i_window);
	};
	
	void draw_end_of_game(sf::RenderWindow& i_window, bool won);

		

}
