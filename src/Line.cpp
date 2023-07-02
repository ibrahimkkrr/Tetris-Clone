#include "Line.h"


std::vector<sf::RectangleShape> Line::line;



Line::Line()
{
	state = false;
	statesTest();
	setup();



}


bool Line::checkFullLine()
{
	for (int i = 0; i < 10; i++)
	{
		if (shapesStates[i] == false)
		{
			std::cout << "Not FULL" << std::endl;
			return false;
		}
	}

	std::cout << "FULL" << std::endl;
	return true;
}

void Line::statesTest()
{
	for (int i = 0; i < 10; i++)
		shapesStates[i] = state;

}


void Line::setupSize()
{
	for (int i = 0; i < 10; i++)
	{
		shapes[i].setSize(sf::Vector2f(25.0f,25.0f));
	}
}

void Line::setupTexture()
{
	shapeTextur.loadFromFile("blue.png");
	for (int i = 0; i < 10; i++)
		shapes[i].setTexture(&shapeTextur);
}

void Line::setTexture(int colorNumber)
{
	if (colorNumber == 1)
	{
		shapeTextur.loadFromFile("blue.png");
		for (int i = 0; i < 10; i++)
			shapes[i].setTexture(&shapeTextur);

	}
	else if (colorNumber == 2)
	{
		shapeTextur.loadFromFile("orange.png");
		for (int i = 0; i < 10; i++)
			shapes[i].setTexture(&shapeTextur);
	}
	else if (colorNumber == 3)
	{
		shapeTextur.loadFromFile("white.png");
		for (int i = 0; i < 10; i++)
			shapes[i].setTexture(&shapeTextur);
	}
	else if (colorNumber == 4)
	{
		shapeTextur.loadFromFile("green.png");
		for (int i = 0; i < 10; i++)
			shapes[i].setTexture(&shapeTextur);
	}
	else if (colorNumber == 5)
	{
		shapeTextur.loadFromFile("red.png");
		for (int i = 0; i < 10; i++)
			shapes[i].setTexture(&shapeTextur);
	}
	else if (colorNumber == 6)
	{
		shapeTextur.loadFromFile("purple.png");
		for (int i = 0; i < 10; i++)
			shapes[i].setTexture(&shapeTextur);
	}
	else if (colorNumber == 7)
	{
		shapeTextur.loadFromFile("lightblue.png");
		for (int i = 0; i < 10; i++)
			shapes[i].setTexture(&shapeTextur);
	}


}

void Line::setupPostion()
{
	float nextXPostion = 0;

	for (int i = 0; i < 10; i++)
	{
		shapes[i].setPosition(sf::Vector2f(initil_x_loction + nextXPostion, initil_y_loction));
		nextXPostion += 25;
	}

}

void Line::setupShapes()
{
	for (int i = 0; i < 10; i++)
		shapes[i] = shape;

	
}

void Line::setup()
{
	setupShapes();
	setupSize();
	setupTexture();
}

void Line::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < 10; i++)
	{
		if (shapesStates[i])
		{

		window->draw(shapes[i]);
		}
		
   }
}

std::array<sf::RectangleShape, 10>& Line::getShapes()
{
	return shapes;
}

std::array < bool, 10>& Line::getshapesStates()
{
	return shapesStates;
}
void Line::setLineState(int postion)
{
	int index = postion - 1;

	shapesStates[index] = true;

	


}


void Line::setLineLocation(int y)
{
	initil_y_loction += y;

	setupPostion();

}



void Line::operator= (const Line& otherLine)
{
	for (int i = 0; i < 10; i++)
		this->shapesStates[i] = otherLine.shapesStates[i];
	
}
