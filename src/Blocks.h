#pragma once
#include "Lblock.h"
#include "Jblock.h"
#include "SqauerBlock.h"
#include "Sblock.h"
#include "Zblock.h"
#include "Tblock.h"
#include "Iblock.h"

class Blocks
{
private:
static std::array<Block*, 7> blocks;
int randomSpawn();
bool checkNextSpawn();

	Lblock lblock;
	Jblock jblock;
	SqauerBlock sqauerBlock;
	Sblock sblock;
	Zblock zblock;
	Tblock tblock;
	Iblock iblock;

enum Action {rotate,moveLeft,moveRight,moveDown,natural};

Action actionToDo;

int getActiveBlock();

std::vector<Action> inputRecorder;

void clearInput();

public:

	Blocks();

	void spawn();
	void move();
	void input();
    void checkIsSpwaned();
	void draw(sf::RenderWindow&);


	std::array<Block*, 7>& getBlocks();
};

