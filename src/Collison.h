#pragma once
#include "SFML/Graphics.hpp"
#include "Line.h"
#include "Block.h"
#include "Map.h"
#include <iostream>
class Collison
{
private:

	void checkGameOver(Map* map, Block* block);
	void blockOnBlockCollisonPostion(Map* map, Block* block);


	bool checkCollison(sf::RectangleShape*, Block*,Map*);
	bool checkCollison(Map*, Block*);

public:

	void doCollison(sf::RectangleShape&, Block&,Map&);

	void doCollison(Block&, Map&);

};

