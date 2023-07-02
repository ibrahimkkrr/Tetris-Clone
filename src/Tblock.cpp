#include "Tblock.h"



int Tblock::direction = 0;

bool Tblock::isSpawned = false;

std::array<sf::RectangleShape, 4> Tblock::shapes;
std::array<sf::Vector2f, 4>  Tblock::shapesPostions;


Tblock::Tblock()
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


	blockTextur.loadFromFile("purple.png");

	setupShapesTexture();

	setupShapesGlobalBounds();






	spawn();
}


void Tblock::spawn()
{

	shapes[2].setPosition(sf::Vector2f(375.0f, 125.0f));

	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));
	shapes[1].setPosition(sf::Vector2f(shapes[2].getPosition().x + blockBounds.width, shapes[2].getPosition().y));
	shapes[0].setPosition(sf::Vector2f(shapes[2].getPosition().x, shapes[2].getPosition().y - blockBounds.height));
	shapesPostions[0].x = 5,
	shapesPostions[0].y = 1;

	shapesPostions[1].x = 6;
	shapesPostions[1].y = 2;

	shapesPostions[2].x = 5;
	shapesPostions[2].y = 2;

	shapesPostions[3].x = 4;
	shapesPostions[3].y = 2;


	direction = 1;


}


void Tblock::respawn()
{
	shapes[2].setPosition(sf::Vector2f(375, 125.0f));

	shapesPostions[0].x = 6,
		shapesPostions[0].y = 1;

	shapesPostions[1].x = 6;
	shapesPostions[1].y = 2;

	shapesPostions[2].x = 5;
	shapesPostions[2].y = 2;

	shapesPostions[3].x = 4;
	shapesPostions[3].y = 2;

}


void Tblock::despwan()
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


void Tblock::deSpawnState()
{
	isSpawned = false;
}





void Tblock::eastDirection()
{


	



	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x , shapes[2].getPosition().y + blockBounds.height));





	direction = east;

}

void Tblock::westDirection()
{

	

	shapes[1].setPosition(sf::Vector2f(shapes[2].getPosition().x, shapes[2].getPosition().y - blockBounds.height));


	direction = west;
}

void Tblock::southDirection()
{
	if (shapesPostions[2].x == 1)
	{
		shapes[2].setPosition(sf::Vector2f(shapes[2].getPosition().x + blockBounds.width, shapes[2].getPosition().y));
		shapes[1].setPosition(sf::Vector2f(shapes[2].getPosition().x + blockBounds.width, shapes[2].getPosition().y));


		incrementX();
	}

	
	shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));


	shapes[0].setPosition(sf::Vector2f(shapes[2].getPosition().x, shapes[2].getPosition().y + blockBounds.height));

	direction = south;
}



void Tblock::northDirection()
{


	if (shapesPostions[2].x == 10)
	{
		shapes[2].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));
		shapes[3].setPosition(sf::Vector2f(shapes[2].getPosition().x - blockBounds.width, shapes[2].getPosition().y));


		decrementX();

	}



	shapes[1].setPosition(sf::Vector2f(shapes[2].getPosition().x + blockBounds.width, shapes[2].getPosition().y ));

	shapes[0].setPosition(sf::Vector2f(shapes[2].getPosition().x, shapes[2].getPosition().y - blockBounds.height));



	direction = north;

}


void Tblock::input()
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

void Tblock::rotate()
{



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{


		if (direction == north)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock4Postion();

			eastDirection();
		}
		else if (direction == east)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock4Postion();

			southDirection();
		}
		else if (direction == south)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock4Postion();

			westDirection();
		}
		else if (direction == west)
		{
			updateBlock1Postion();
			updateBlock2Postion();
			updateBlock4Postion();

			northDirection();
		}


	}



}


void Tblock::move()
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


void Tblock::draw(sf::RenderWindow* window)
{



	for (int i = 0; i < shapes.size(); i++)
		window->draw(shapes[i]);


}


int Tblock::randomDirectionSpawn()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(1, 5);

	return dis(gen);


}


int Tblock::getColorNumber()
{
	return colorNumber;

}

std::array<sf::RectangleShape, 4>& Tblock::getShapes()
{
	return shapes;
}

std::array<sf::Vector2f, 4>& Tblock::getShapesPostions()
{
	return shapesPostions;
}

int Tblock::getDirection()
{
	return direction;
}

bool Tblock::getSpawnState()
{
	return isSpawned;
}


void Tblock::setSpawnState(bool spawn)
{
	isSpawned = spawn;
}

void Tblock::setInputState(bool)
{

}

void Tblock::setupShapeSize()
{
	for (int i = 0; i < shapes.size(); i++)
		shapes[i].setSize(sf::Vector2f(25.0f, 25.0f));
}


void Tblock::setupShapesTexture()
{
	for (int i = 0; i < shapes.size(); i++)
		shapes[i].setTexture(&blockTextur);
}


void Tblock::setupShapesGlobalBounds()
{

	blockBounds = shapes[1].getGlobalBounds();

}

void Tblock::collisonPostion()
{
}

//this function to check who  hit the right wall first so it can decide when stop
int Tblock::check_block_limite_right()
{
	switch (direction)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 1;
		break;
	case 3:
		return 1;
		break;
	case 4:
		return 1;
		break;
	default:
		break;
	}

}
//this function to check who  hit the left wall first so it can decide when stop

int Tblock::check_block_limite_left()
{
	switch (direction)
	{
	case 1:
		return 3;
		break;
	case 2:
		return 3;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 3;
		break;
	default:
		break;
	}

}



void Tblock::updateBlock1Postion()
{
    if (direction == east)
	{
		shapesPostions[0].y += 2;
	}else if (direction == west)
	{
		shapesPostions[0].y -= 2;

	}
}

void Tblock::updateBlock2Postion()
{  
	if (direction == south)
	{
		shapesPostions[1].x--;
		shapesPostions[1].y--;
	}
	else if (direction == west)
	{
		shapesPostions[1].x++;
		shapesPostions[1].y++;
	}
}







void Tblock::updateBlock4Postion()
{
	if (direction == north)
	{

		shapesPostions[3].x++;
		shapesPostions[3].y++;


	}
	else if (direction == east)
	{
		shapesPostions[3].x--;
		shapesPostions[3].y--;

	}
}



void Tblock::incrementX()
{
	shapesPostions[0].x += 1;
	shapesPostions[1].x += 1;
	shapesPostions[2].x += 1;
	shapesPostions[3].x += 1;

}

void Tblock::incrementY()
{
	shapesPostions[0].y += 1;
	shapesPostions[1].y += 1;
	shapesPostions[2].y += 1;
	shapesPostions[3].y += 1;

}

void Tblock::decrementX()
{
	shapesPostions[0].x -= 1;
	shapesPostions[1].x -= 1;
	shapesPostions[2].x -= 1;
	shapesPostions[3].x -= 1;

}