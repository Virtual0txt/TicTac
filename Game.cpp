#include "pch.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include "Button.h"

using namespace std;
using namespace sf;

Game::Game(int x,int y,string name = "Void")
{
	window.create(VideoMode(x, y), name);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
}

void Game::initializeButtons()
{
	Vector2f size(96, 96);
	Button sample(size);
	sample.setFillColor(Color::Black);

	for (int i = 0; i < 9; i++)
	{

		if (i < 3)
		{
			sample.setPosition(i * 103, 0);
		}
		else
			if (i < 6)
			{
				sample.setPosition((i - 3) * 103, 103);
			}
			else
			{
				sample.setPosition((i - 6) * 103, 206);
			}
		buttons[i] = sample;
	}
}

void Game::initializeLines()
{
	Vector2f wie(3, 300);
	Vector2f ww(300, 3);
	RectangleShape line;
	line.setFillColor(Color::Green);

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			line.setSize(ww);
		else
			line.setSize(wie);
		switch (i) {
		case 0:
			line.setPosition(0, 100);
			break;
		case 1:
			line.setPosition(0, 200);
			break;
		case 2:
			line.setPosition(100, 0);
			break;
		case 3:
			line.setPosition(200, 0);
			break;
		}
		lines[i] = line;
	}
}

void Game::initializeTexture()
{
	tixx.loadFromFile("tic.png");
	toxx.loadFromFile("toe.png");

	tixx.setSmooth(true);
	toxx.setSmooth(true);
}

void Game::initializeText()
{
	komunikat = "Wygraly: ";	
	cour.loadFromFile("cour.ttf");

	if (checkWin() > 0)
	{
		if (turn)
		{
			komunikat += "kolka";
		}
		else
		{
			komunikat += "krzyzyki";
		}
	}
	else
		komunikat = "Remis";

	for (int i = 0; i < komunikat.size(); i++)
	{
		Text literka;
		literka.setFont(cour);
		//literka.setColor(Color(0,0,255));
		literka.setPosition(Vector2f( 50 + (i*20), 100 ));


	}

	//TODO
}

void Game::initializeAll()
{
	initializeButtons();
	initializeLines();
	initializeTexture();
	//initializeText();
}

void Game::createSprite(int i)
{
	Sprite sp;

	if (turn)
	{
		sp.setTexture(tixx);
	}
	else
	{
		sp.setTexture(toxx);
	}

	switch (i)
	{
	case 0:
		sp.setPosition(Vector2f(0, 0));
		break;
	case 1:
		sp.setPosition(Vector2f(103, 0));
		break;
	case 2:
		sp.setPosition(Vector2f(206, 0));
		break;
	case 3:
		sp.setPosition(Vector2f(0, 103));
		break;
	case 4:
		sp.setPosition(Vector2f(103, 103));
		break;
	case 5:
		sp.setPosition(Vector2f(206, 103));
		break;
	case 6:
		sp.setPosition(Vector2f(0, 206));
		break;
	case 7:
		sp.setPosition(Vector2f(103, 206));
		break;
	case 8:
		sp.setPosition(Vector2f(206, 206));
		break;
	}

	arr.push_back(sp);
}

int Game::checkWin()
{
	for (int i = 0; i < 3; i++ )
	{
		if (tab[i*3] == tab[i * 3 + 1] && tab[i * 3] == tab[i * 3 + 2] && tab[i * 3] != 0)
		{
			return tab[i * 3];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (tab[i] == tab[i + 3] && tab[i] == tab[i + 6] && tab[i] != 0)
		{
			return tab[i];
		}
	}

	if (tab[0] == tab[4] && tab[0] == tab[8] && tab[0] != 0)
		return tab[0];
	if (tab[2] == tab[4] && tab[2] == tab[6] && tab[2] != 0)
		return tab[0];

	return 0;
}

void Game::drawEnd()
{
	window.clear(Color::White);
	//TODO
}

void Game::endGame()
{
	initializeText();
	
	//TODO
}

void Game::drawAll()
{
	window.clear();
	for (int i = 0; i < 9; i++)
		window.draw(buttons[i]);
	for (int i = 0; i < 4; i++)
		window.draw(lines[i]);
	for (int i = 0; i < arr.size(); i++)
		window.draw(arr[i]);
	window.display();
}

void Game::running() // main method
{
	while (window.isOpen())
	{
		if (arr.size() == 9) end = true;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if(end == false)
				if (event.type == Event::MouseButtonPressed) //Works well
				{
					do
					{
					} while (event.type == Event::MouseButtonReleased);
					for (int i = 0; i < 9; i++)
						if (buttons[i].updateState(sf::Mouse::getPosition(window)))
						{
							//cout << "button number: " << i << ".  \n";
							if (tab[i] == 0)
							{
								if (turn)
								{
									tab[i] = 1;
									//cout << "1 \n";
									createSprite(i);
									turn = false;
								}
								else
								{
									tab[i] = 2;
								//	cout << "2 \n";
									createSprite(i);
									turn = true;
								}
								if (checkWin() != 0)
								{
									cout << "end of game \n";
									cout << "win team: " << checkWin();
									end = true;
									endGame();
									break;
								}
							}
						
						}
				}
		} 
		drawAll();
	}
}
