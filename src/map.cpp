#include <headers.hpp>
#include <time.h>
#include <iostream>



void map_ns::Field::generate_map()
{
	srand(time(0));
	for (int y = 0; y < map_size_y; y++)
	{
		for (int x = 0; x < map_size_x; x++)
		{
			if( (rand() % 8) == 1)
			{
				map_logic[y][x] = 9;
			}
			else map_logic[y][x] = 0;
			map_view[y][x] = 10;
		}
	}
	set_numbers();
}

void map_ns::Field::set_numbers()
{
	for (int y = 0; y < map_size_y; y++)
	{
		for (int x = 0; x < map_size_x; x++)
		{
			if (map_logic[y][x] != 9)
			{
				int counter = 0;
				
				for (int i = 0; i < 8; i++)
				{
					if (x - dementions[i][0] >= 0 && x - dementions[i][0] < map_size_x && y - dementions[i][1] >= 0 && y - dementions[i][1] < map_size_y && map_logic[y - dementions[i][1]][x - dementions[i][0]] == 9)
					{
						counter++;
					}
				}
				map_logic[y][x] = counter;			
			}
		}
	}
}

void map_ns::Field::open_around(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		if (x - dementions[i][0] >= 0 && x - dementions[i][0] < map_size_x && y - dementions[i][1] >= 0 && y - dementions[i][1] < map_size_y && (map_view[y - dementions[i][1]][x - dementions[i][0]] == 10))
		{
			map_view[y - dementions[i][1]][x - dementions[i][0]] = map_logic[y - dementions[i][1]][x - dementions[i][0]];
			if (map_logic[y - dementions[i][1]][x - dementions[i][0]] == 0)
			{
				open_around(x - dementions[i][0], y - dementions[i][1]);
			}
		}
	}
} 

bool map_ns::Field::win()
{
	bool flag = 1;
	for (int x = 0; x < map_size_x; x++)
	{
		for (int y = 0; y < map_size_y; y++)
		{
			if (map_logic[x][y] == 9 && map_view[x][y] != 11) { flag = 0; }
			if (map_logic[x][y] != 9 && map_view[x][y] == 11) { flag = 0; }
		}
	}
	return flag;
}





void map_ns::Field::draw(sf::RenderWindow& i_window)
{
	i_window.clear(sf::Color::Black);
	for (int y = 0; y < map_size_y; y++)
	{
		for (int x = 0; x < map_size_x; x++)
		{
			sf::Texture t_icons;
			t_icons.loadFromFile("2.jpg");
			sf::Sprite s_icons(t_icons);
			s_icons.setTextureRect(sf::IntRect(map_view[y][x] * cell_size, 0, cell_size, cell_size));
			s_icons.setPosition(y * cell_size, x * cell_size);
			i_window.draw(s_icons);
		}
	}
	i_window.display();
}




























































































































































































































































































































































































































