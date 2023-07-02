#pragma once
#include "Block.h"
#include <array>
#include <random>

class Lblock:public Block
{
private:

	static bool isSpawned;

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(0.5f);

	sf::RectangleShape block1;
	sf::RectangleShape block2;
	sf::RectangleShape block3;
	sf::RectangleShape block4;
	sf::Texture blockTextur;

	sf::FloatRect blockBounds;

	static std::array<sf::RectangleShape, 4> shapes;
	static std::array<sf::Vector2f, 4> shapesPostions;


	sf::Vector2f block1Postion;
	sf::Vector2f block2Postion;
	sf::Vector2f block3Postion;
	sf::Vector2f block4Postion;

	void incrementX();
	void incrementY();
	void decrementX();


	void updateBlock1Postion();
	void updateBlock2Postion();
	void updateBlock3Postion();
	void updateBlock4Postion();

	 
	void eastDirection();
	void southDirection();
	void westDirection();
	void northDirection();

	void setupShapeSize();
	void setupShapesTexture();
	void setupShapesGlobalBounds();
	
	int check_block_limite_right();
	int check_block_limite_left();

	void collisonPostion();

	int randomDirectionSpawn();


	const int north = 1;
	const int east = 2;
	const int south = 3;
	const int west = 4;

	static int direction;

	int colorNumber = 1;

	void rotate();
public:

	Lblock();
	void input();
	void move();
	std::array<sf::RectangleShape, 4>& getShapes();
	std::array<sf::Vector2f, 4>& getShapesPostions();

	void draw(sf::RenderWindow* window);

	void spawn();
	void respawn();

	void deSpawnState();
	void despwan();

	int getDirection();
	int getColorNumber();


	bool getSpawnState();
	void setSpawnState(bool);
	sf::Vector2f getBlock1Postion();



};

