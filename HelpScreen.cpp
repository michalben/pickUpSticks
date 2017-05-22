#include "HelpScreen.h"


/* Constructor:
   in this counstructor we set the position and the string of the
   help screen button */
HelpScreen::HelpScreen() {

	sf::Text text;

	if (m_font.loadFromFile("gamecuben.ttf"))
	{
		text.setPosition(512, 600);
		text.setFont(m_font);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Bold);
		text.setString("OK");

		m_buttons.push_back(text);
	}

}
