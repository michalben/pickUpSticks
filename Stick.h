#pragma once

#include <SFML/Graphics.hpp>

class Stick
{
public:
	Stick();
	const void draw(sf::RenderWindow& window)const { window.draw(m_stick); }
	sf::Vector2f getPos()const;
	~Stick() {}

private:
	sf::RectangleShape m_stick;

};

