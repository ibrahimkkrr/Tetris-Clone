#include "Grid.h"


sf::VertexArray Grid::grid(sf::Lines, 56);

Grid::Grid()
{
	setupGrid();
}

void Grid::setupGrid()
{
	for (int i = 0; i < 18; i = i + 2)
	{
		wideth_of_grid_box += 25;
		grid[i].position = sf::Vector2f(initial_postion_x + wideth_of_grid_box, initial_postion_y);
		grid[i + 1].position = sf::Vector2f(initial_postion_x + wideth_of_grid_box, initial_postion_y + 500);

	}
	for (int i = 18; i < 56; i = i + 2)
	{
		height_of_grid_box += 25;
		grid[i].position = sf::Vector2f(initial_postion_x, initial_postion_y + height_of_grid_box);

		grid[i + 1].position = sf::Vector2f(initial_postion_x + 250, initial_postion_y + height_of_grid_box);

	}


	

}

void Grid::setupColor()
{
	for (int i = 0; i < 57; i++)
		grid[i].color = sf::Color::Cyan;

}

void Grid::draw(sf::RenderWindow& window)
{
	window.draw(grid);
}