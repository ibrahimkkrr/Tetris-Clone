#pragma once
#include "SFML/Graphics.hpp"
class Grid
{
private:
	const float initial_postion_x = 275;
	const float initial_postion_y = 100;

	float wideth_of_grid_box = 0;
	float height_of_grid_box = 0;

	static sf::VertexArray grid;

	void setupGrid();
	void setupColor();

public:
	Grid();
	void draw(sf::RenderWindow&);

};

