#pragma once
#include "Line.h"
#include <vector>
#include <array>

class Map
{
private:


	static std::array<Line, 20> lines;


	int nextIndex = 0;
	bool fullLine = false;

	Line gg[1];

	Line line;

	void setupLines();
	void setupLinesPostion();

	int x_index;
	int y_index;

	

public:
	Map();
	void draw(sf::RenderWindow&);
	void located_collison_postion(sf::Vector2u,int);

	void checkFullLines(int);
	void clearLine(bool, int);


	void setStatesTest();
	std::array<Line, 20>& getLines();

};

