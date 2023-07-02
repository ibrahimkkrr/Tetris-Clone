#pragma once
#include "SFML/Graphics.hpp"
#include <array>
#include <tuple>
#include <iostream>




class Block
{

public:
	
	virtual void spawn();
	virtual void despwan();

	virtual void input();
	virtual void move();

	virtual int getDirection();
	virtual int getColorNumber();
	virtual bool getSpawnState();
	virtual void deSpawnState();
	virtual void respawn();

	virtual void setSpawnState(bool);
	virtual void setInputState(bool);

	virtual void rotate();
	virtual void moveDown();
	virtual void moveRight();
	virtual void moveLeft();

	virtual std::array<sf::RectangleShape, 4>& getShapes();
	virtual std::array<sf::Vector2f, 4>& getShapesPostions();
	




	virtual void draw(sf::RenderWindow*);



};

