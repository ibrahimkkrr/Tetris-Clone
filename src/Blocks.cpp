#include "Blocks.h"

std::array<Block*, 7> Blocks::blocks;

Blocks::Blocks()
{

	blocks[0] = &lblock;
	blocks[1] = &jblock;
	blocks[2] = &sqauerBlock;
	blocks[3] = &sblock;
	blocks[4] = &zblock;
	blocks[5] = &tblock;
	blocks[6] = &iblock;



	checkIsSpwaned();
}

int Blocks::randomSpawn()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(1, 8);

	return dis(gen);


}

bool Blocks::checkNextSpawn()
{
	int count = 0;
	for (int i = 0; i < blocks.size(); i++)
	{
		if (!blocks[i]->getSpawnState())
		{
			count++;
		}
	}

	if (count == blocks.size())
	{
		return true;
	}
	return false;

}


void Blocks::checkIsSpwaned()
{
	
	bool nextSpawn = checkNextSpawn();

	if (nextSpawn)
	{
	   blocks[randomSpawn()-1]->setSpawnState(true);
	   spawn();

	}
}

void Blocks::spawn()
{
	for (int i = 0; i < blocks.size(); i++)
		if (blocks[i]->getSpawnState())
			blocks[i]->spawn();
}



void Blocks::move()
{
	for (int i = 0; i < blocks.size(); i++)
		blocks[i]->move();
		

		
	
}

void Blocks::input()
{
	for (int i = 0; i < blocks.size(); i++)
	   if (blocks[i]->getSpawnState())
			blocks[i]->input();
	

}


void Blocks::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < blocks.size(); i++)
		if(blocks[i]->getSpawnState())
		 blocks[i]->draw(&window);
}


std::array<Block*, 7>& Blocks::getBlocks()
{
	return blocks;
}