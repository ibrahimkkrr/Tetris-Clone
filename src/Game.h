#pragma once
#include "SFML/Graphics.hpp"
#include "Line.h"
#include "Grid.h"
#include "Map.h"
#include "Blocks.h"
#include "SqauerBlock.h"
#include "Collison.h"
#include <vector>
#include <iostream>

class Game
{
private:

	Blocks blocks;
	Iblock iblock;
	Grid grid;
	
	Line line;
	Map map;
	Collison collison;

	static const float VIEW_WEDITH;
	static const float VIEW_HIEGHT;


	sf::RectangleShape floor;

	static sf::RenderWindow window;
	static sf::View view;

	sf::Event evnt;
	sf::Clock clock;


	float time = 0.0f;
	float delay = 0.2f;

	void input();
	void update();
	void render();
	void eventRecorder();
	void resize();



	public:
		Game();
		void startGame();

	

};

