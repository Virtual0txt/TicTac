#pragma once
#include "Button.h"
#include <vector>

class Game final
{
private:
	sf::RenderWindow window;
	sf::Event event;

	sf::RectangleShape lines[4];
	Button buttons[9];
	int tab[9]{};

	std::vector <sf::Sprite> arr;
	std::vector <sf::Text> tekst;

	sf::Texture tixx;
	sf::Texture toxx;

	std::string komunikat;
	sf::Font cour;

	bool turn = true;
	bool end = false;

public:
	void initializeButtons();
	void initializeLines();
	void initializeTexture();
	void initializeText();
	void initializeAll();

	void createSprite(int i);
	int checkWin();

	void drawEnd();
	void endGame();
	void drawAll();
	void running();
	

	Game(int x, int y, std::string name);
};

