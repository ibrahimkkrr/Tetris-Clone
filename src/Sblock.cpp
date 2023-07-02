#include "Sblock.h"



int Sblock::direction = 0;
bool Sblock::isSpawned = false;

std::array<sf::RectangleShape, 4> Sblock::shapes;
std::array<sf::Vector2f, 4>  Sblock::shapesPostions;


Sblock::Sblock()
{


	shapes[0] = block1;
	shapes[1] = block2;
	shapes[2] = block3;
	shapes[3] = block4;

	shapesPostions[0] = block1Postion;
	shapesPostions[1] = block2Postion;
	shapesPostions[2] = block3Postion;
	shapesPostions[3] = block4Postion;

	setupShapeSize();


	blockTextur.loadFromFile("green.png");

	setupShapesTexture();

	setupShapesGlobalBounds();






	spawn();
}


void Sblock::spawn()
{

	shapes[2].setPosition(sf::Vector2f(375.0f, 125.0f));

	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));
	shapes[1].setPosition(sf::Vector2f(shapes[2].getPosition().x, shapes[2].getPosition().y - blockBounds.height));
	shapes[0].setPosition(sf::Vector2f(shapes[1].getPosition().x + blockBounds.width, shapes[1].getPosition().y));
	
	shapesPostions[0].x = 6,
	shapesPostions[0].y = 1;

	shapesPostions[1].x = 5;
	shapesPostions[1].y = 1;

	shapesPostions[2].x = 5;
	shapesPostions[2].y = 2;

	shapesPostions[3].x = 4;
	shapesPostions[3].y = 2;


	direction = 4;


}


void Sblock::respawn()
{
	shapes[2].setPosition(sf::Vector2f(375, 125.0f));//place holder postion

	shapesPostions[0].x = 6,
		shapesPostions[0].y = 1;

	shapesPostions[1].x = 6;
	shapesPostions[1].y = 2;

	shapesPostions[2].x = 5;
	shapesPostions[2].y = 2;

	shapesPostions[3].x = 4;
	shapesPostions[3].y = 2;

}


void Sblock::despwan()
{
	shapes[2].setPosition(sf::Vector2f(200.0f, 125.0f));

	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x + blockBounds.width, shapes[2].getPosition().y));
	shapes[1].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));
	shapes[0].setPosition(sf::Vector2f(shapes[1].getPosition().x, shapes[2].getPosition().y - blockBounds.height));
	shapesPostions[0].x = 4,
		shapesPostions[0].y = 1;

	shapesPostions[1].x = 4;
	shapesPostions[1].y = 2;

	shapesPostions[2].x = 5;
	shapesPostions[2].y = 2;

	shapesPostions[3].x = 6;
	shapesPostions[3].y = 2;


}


void Sblock::deSpawnState()
{
	isSpawned = false;
}





void Sblock::eastDirection()
{
	if (shapesPostions[2].x == 1)
	{
		shapes[2].setPosition(sf::Vector2f(shapes[2].getPosition().x + blockBounds.width, shapes[2].getPosition().y));
		shapes[1].setPosition(sf::Vector2f(shapes[1].getPosition().x + blockBounds.width, shapes[1].getPosition().y));


		incrementX();
	}


	shapes[2].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));

	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));

	shapes[1].setPosition(sf::Vector2f(shapes[1].getPosition().x, shapes[1].getPosition().y - blockBounds.height));

	shapes[0].setPosition(sf::Vector2f(shapes[1].getPosition().x + blockBounds.width, shapes[1].getPosition().y));



	direction = east;

}

void Sblock::westDirection()
{

	if (shapesPostions[2].x == 10)
	{
		shapes[2].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));
		shapes[1].setPosition(sf::Vector2f(shapes[1].getPosition().x - blockBounds.width, shapes[1].getPosition().y));

		decrementX();

	}

	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));

	shapes[1].setPosition(sf::Vector2f(shapes[1].getPosition().x +blockBounds.width, shapes[1].getPosition().y - blockBounds.height));

	shapes[0].setPosition(sf::Vector2f(shapes[1].getPosition().x + blockBounds.width, shapes[1].getPosition().y));



	direction = west;
}

void Sblock::southDirection()
{



	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x, shapes[2].getPosition().y + blockBounds.height));

	shapes[1].setPosition(sf::Vector2f(shapes[1].getPosition().x - blockBounds.width, shapes[1].getPosition().y + blockBounds.height));

	shapes[0].setPosition(sf::Vector2f(shapes[1].getPosition().x, shapes[0].getPosition().y));


	direction = south;
}



void Sblock::northDirection()
{



	shapes[2].setPosition(sf::Vector2f(shapes[2].getPosition().x + blockBounds.width, shapes[2].getPosition().y));


	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x, shapes[2].getPosition().y + blockBounds.height));

	shapes[1].setPosition(sf::Vector2f(shapes[1].getPosition().x, shapes[1].getPosition().y + blockBounds.height));

	shapes[0].setPosition(sf::Vector2f(shapes[1].getPosition().x , shapes[0].getPosition().y));



	direction = north;

}


void Sblock::input()
{
	rotate();

	int first_block_number_right = check_block_limite_right();
	int first_block_number_left = check_block_limite_left();


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shapes[first_block_number_right].getPosition().x < 500)
	{

		incrementX();
		for (int i = 0; i < shapes.size(); i++)
			shapes[i].move(25.0f, 0.0f);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shapes[first_block_number_left].getPosition().x > 275)
	{


		decrementX();

		for (int i = 0; i < shapes.size(); i++)
			shapes[i].move(-25.0f, 0.0f);


	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{


		incrementY();

		for (int i = 0; i < shapes.size(); i++)
			shapes[i].move(0.0f, 25.0f);
	}






}

void Sblock::rotate()
{



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{


		if (direction == north)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock3Postion();
			updateBlock4Postion();

			eastDirection();
		}
		else if (direction == east)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock3Postion();
			updateBlock4Postion();

			southDirection();
		}
		else if (direction == south)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock3Postion();
			updateBlock4Postion();

			westDirection();
		}
		else if (direction == west)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock3Postion();
			updateBlock4Postion();

			northDirection();
		}
		

	}



}


void Sblock::move()
{


	sf::Time elapsedTime = clock.restart();
	timeSinceLastUpdate += elapsedTime;
	while (timeSinceLastUpdate > TimePerFrame)
	{
		timeSinceLastUpdate -= TimePerFrame;

		incrementY();

		shapes[0].move(0.0f, 25.0f);
		shapes[1].move(0.0f, 25.0f);
		shapes[2].move(0.0f, 25.0f);
		shapes[3].move(0.0f, 25.0f);

	}






}


void Sblock::draw(sf::RenderWindow* window)
{




	for (int i = 0; i < shapes.size(); i++)	
		window->draw(shapes[i]);


}


int Sblock::randomDirectionSpawn()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(1, 5);

	return dis(gen);


}


int Sblock::getColorNumber()
{
	return colorNumber;

}

std::array<sf::RectangleShape, 4>& Sblock::getShapes()
{
	return shapes;
}

std::array<sf::Vector2f, 4>& Sblock::getShapesPostions()
{
	return shapesPostions;
}

int Sblock::getDirection()
{
	return direction;
}

bool Sblock::getSpawnState()
{
	return isSpawned;
}


void Sblock::setSpawnState(bool spawn)
{
	isSpawned = spawn;
}

void Sblock::setupShapeSize()
{
	for (int i = 0; i < shapes.size(); i++)
		shapes[i].setSize(sf::Vector2f(25.0f, 25.0f));
}


void Sblock::setupShapesTexture()
{
	for (int i = 0; i < shapes.size(); i++)
		shapes[i].setTexture(&blockTextur);
}


void Sblock::setupShapesGlobalBounds()
{

	blockBounds = shapes[1].getGlobalBounds();

}

void Sblock::collisonPostion()
{
}

//this function to check who  hit the right wall first so it can decide when stop
int Sblock::check_block_limite_right()
{
	switch (direction)
	{
	case 1:
		return 2;
		break;
	case 2:
		return 0;
		break;
	case 3:
		return 2;
		break;
	case 4:
		return 0;
		break;
	default:
		break;
	}

}
//this function to check who  hit the left wall first so it can decide when stop

int Sblock::check_block_limite_left()
{
	switch (direction)
	{
	case 1:
		return 0;
		break;
	case 2:
		return 3;
		break;
	case 3:
		return 0;
		break;
	case 4:
		return 3;
		break;
	default:
		break;
	}

}


void Sblock::updateBlock1Postion()
{
	if (direction == north)
	{
		shapesPostions[0].x++;

	}
	else if (direction == east)
	{
		shapesPostions[0].x -= 2;
	}
	else if (direction == south)
	{
		shapesPostions[0].x += 2;

	}
	else if (direction == west)
	{
		shapesPostions[0].x--;

	}
}

void Sblock::updateBlock2Postion()
{
	if (direction == north)
	{

		shapesPostions[1].y--;

	}
	else if (direction == east)
	{
		shapesPostions[1].x--;
		shapesPostions[1].y++;
	}
	else if (direction == south)
	{
		shapesPostions[1].x++;

		shapesPostions[1].y--;
	}
	else if (direction == west)
	{
		shapesPostions[1].y++;
	}
}


void Sblock::updateBlock3Postion()
{
	if (direction == north)
	{
		shapesPostions[2].x--;


	}else if (direction == west)
	{
		shapesPostions[2].x++;
	}


}




void Sblock::updateBlock4Postion()
{
	if (direction == north)
	{

		shapesPostions[3].x -= 2;
		shapesPostions[3].y--;


	}
	else if (direction == east)
	{
		shapesPostions[3].x++;
		shapesPostions[3].y++;

	}
	else if (direction == south)
	{
		shapesPostions[3].x--;

		shapesPostions[3].y--;
	}
	else if (direction == west)
	{
		shapesPostions[3].x += 2;
		shapesPostions[3].y++;
	}
}



void Sblock::incrementX()
{
	shapesPostions[0].x += 1;
	shapesPostions[1].x += 1;
	shapesPostions[2].x += 1;
	shapesPostions[3].x += 1;

}

void Sblock::incrementY()
{
	shapesPostions[0].y += 1;
	shapesPostions[1].y += 1;
	shapesPostions[2].y += 1;
	shapesPostions[3].y += 1;

}

void Sblock::decrementX()
{
	shapesPostions[0].x -= 1;
	shapesPostions[1].x -= 1;
	shapesPostions[2].x -= 1;
	shapesPostions[3].x -= 1;

}