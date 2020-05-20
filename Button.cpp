#include "pch.h"
#include "Button.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

using namespace std;

Button::Button(sf::Vector2f elo) : sf::RectangleShape(elo)
{

}

Button::Button() : sf::RectangleShape()
{

}

bool Button::updateState(sf::Vector2i Mposition) 
{
	sf::Vector2f Position = this->getPosition();
	sf::Vector2f Size = this->getSize();

	int Mx = Mposition.x, My = Mposition.y;
	int Px = Position.x, Py = Position.y;
	int Sx = Size.x, Sy = Size.y;

	if (Mx < Px + Sx && Mx > Px)
		if (My > Py && My < Py + Sy)
		{
			return true;
		}
		else
			return false;
	else
		return false;

}
