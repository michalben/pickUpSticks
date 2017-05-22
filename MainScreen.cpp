#include "MainScreen.h"

/* Constructor:
in this counstructor we set the position and the string of the
main screen button */
MainScreen::MainScreen() {

	sf::Text text;

	if (m_font.loadFromFile("gamecuben.ttf"))
	{
		for (int index = 0; index < 3; index++)
		{
			text.setPosition(100, 80 + 60 * index);
			text.setFont(m_font);
			text.setFillColor(sf::Color::Black);
			text.setStyle(sf::Text::Bold);

			m_buttons.push_back(text);
		}
		m_buttons[0].setString("New Game");
		m_buttons[1].setString("Help");
		m_buttons[2].setString("EXIT");
	}
}

