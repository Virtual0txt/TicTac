#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

class Button : public sf::RectangleShape
{

public:
	Button(sf::Vector2f);
	Button();
	bool updateState(sf::Vector2i Mposition);
};
 
