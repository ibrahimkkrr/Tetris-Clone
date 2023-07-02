#include "Game.h"

sf::RenderWindow Game::window(sf::VideoMode(800, 600), "Tetris", sf::Style::Default);
sf::View Game::view(sf::FloatRect(0, 0, 800, 600));

const float Game::VIEW_WEDITH = 800;
const float Game::VIEW_HIEGHT = 600;


Game::Game()
{

	
	window.setFramerateLimit(60);
	floor.setSize(sf::Vector2f(250.0f,10));
	floor.setPosition(sf::Vector2f(275.0f,595.0f));

	
}

void Game::startGame()
{
	while (window.isOpen())
	{  
		window.setView(view);
		eventRecorder();
		update();
		input();
		render();
	}
}

void Game::eventRecorder()
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window.close();
		case sf::Event::Resized:
			resize();
		default:
			break;
		}

	}
}

void Game::resize()
{
	float aspectRaito = float(window.getSize().x) / float(window.getSize().y);

	view.setSize(VIEW_WEDITH * aspectRaito, VIEW_HIEGHT);
}

void Game::input()
{
	time += clock.restart().asSeconds();
	if (time > delay) {
		time -= delay;

	blocks.input();
	}

}

void Game::update()
{

	blocks.move();
	
	blocks.checkIsSpwaned();
	for (int i = 0; i < blocks.getBlocks().size(); i++)
	{
	collison.doCollison(*blocks.getBlocks()[i], map);
	collison.doCollison(floor, *blocks.getBlocks()[i], map);

	}
	
	
	


	
	


	


	 
}

void Game::render()
{
	window.clear();
	grid.draw(window);
	map.draw(window); 
	blocks.draw(window);
	window.draw(floor);
	window.display();
}