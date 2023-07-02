#pragma once
#include "SFML/Graphics.hpp"
#include "Block.h"
#include <vector>
#include <iostream>
class Line
{

private:


	 int initil_x_loction = 275;
	 int initil_y_loction = 100;

	sf::Texture shapeTextur;

	

	float line_postion = 475;

	std::array < bool, 10> shapesStates;
	bool state;
	std::array<sf::RectangleShape, 10> shapes;

	static std::vector<sf::RectangleShape> line;
	sf::RectangleShape shape;

	void statesTest();

	

	void setupSize();
	void setupTexture();
	void setupPostion();
	void setupShapes();
	void setup();


public:

	Line();

	void draw(sf::RenderWindow*);
	
	void placeBlocks(Block&);
	void showSize();

	bool checkFullLine();
	void operator= (const Line& otherLine);

	std::array<sf::RectangleShape, 10>& getShapes();
	std::array < bool, 10>& getshapesStates();

	void setTexture(int);

	void setLineState(int);
	void setLineLocation(int);

};

