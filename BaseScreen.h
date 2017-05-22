#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class BaseScreen
{
public:
	BaseScreen() {}
	void drawButtons(sf::RenderWindow& window);

	// return the match button accordance to the index
	const sf::Text& getButton(int index)const { return m_buttons[index]; }
	
	// return the buttons vector
	std::vector<sf::Text> getOptions() { return m_buttons; }

	~BaseScreen() {}

protected:
	std::vector<sf::Text> m_buttons;
	sf::Font m_font;

};

