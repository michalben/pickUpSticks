
#include "BaseScreen.h"
 
/* This function get the main window of the game, and draw the buttons
    on the match bacground(screen) */
void BaseScreen::drawButtons(sf::RenderWindow& window) {

	for (int index = 0; index < m_buttons.size(); index++) {

		window.draw(m_buttons[index]);

	}
}
