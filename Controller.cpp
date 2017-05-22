#pragma once

#include "Controller.h"
#include "MainScreen.h"
#include "Resources.h"
#include "HelpScreen.h"

Controller::GameOptions Controller::eventManuHandler(MainScreen &MainScreen, sf::RenderWindow & window,
	sf::Event & event)
{

	int index;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			return EXIT;

		case sf::Event::MouseButtonPressed:
		{
			/* if the user click on one of the buttons (start game, help or exit), we
			   move to the match option screen */
			if (MainScreen.getButton(0).getGlobalBounds().contains(
				event.mouseButton.x, event.mouseButton.y))
				return NEW_GAME;
			if (MainScreen.getButton(1).getGlobalBounds().contains(
				event.mouseButton.x, event.mouseButton.y))
				return HELP;
			if (MainScreen.getButton(2).getGlobalBounds().contains(
				event.mouseButton.x, event.mouseButton.y)) {
				window.close();
				return EXIT;
			}
			break;
		}
		//case the mouse move on one of the options
		case sf::Event::MouseMoved:
		{
			/* if the user pass over one of the buttons, we change the color
			   of the button to blue */
			for (index = 0; index < 3; index++)
			{
				if (MainScreen.getButton(index).getGlobalBounds().
					contains(event.mouseMove.x, event.mouseMove.y))
				{
					MainScreen.getOptions()[index].setFillColor(sf::Color::Blue);
				}
				else
					MainScreen.getOptions()[index].setFillColor(sf::Color::Black);
			}

			break;
		}
		default:
			break;
		}
	}
}

void Controller::startGame(sf::RenderWindow& window, Resources& resources) {

	// get random number of sticks (between 10 to 24)
	srand(time(NULL));
	int numOfSticks = (rand() % 15) + 10;

	// create the sticks of the new game
	for (int index = 0; index < numOfSticks; index++) {

		Stick stick;
		m_sticks.push_back(stick);

	}

	sf::Event event;

	// create the game screen
	sf::Sprite gameScreen(resources.getTexture(1), sf::IntRect(0, 0, 1024, 768));
	gameScreen.setPosition(0, 50);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {

			window.clear();
			window.draw(gameScreen);
			for (int index = 0; index < m_sticks.size(); index++) {
				m_sticks[index].draw(window);
			}

			window.display();

			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				break;

			default:
				break;

			}
		}
	}
}

void Controller::showHelpScreen(sf::RenderWindow& window, Resources& resources) {

	sf::Event event;
	HelpScreen helpScreen;

	//create the help screen
	sf::Sprite helpBG(resources.getTexture(2), sf::IntRect(0, 0, 1024, 768));

	while (window.isOpen()) {

		// draw the help background and the button
		window.clear();
		window.draw(helpBG);
		helpScreen.drawButtons(window);
		window.display();

		while (window.pollEvent(event)) {

			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
			{
				/* if the user click on the button, we return to the main menu */
				if (helpScreen.getButton(0).getGlobalBounds().contains(
					event.mouseButton.x, event.mouseButton.y))
					return;
				break;
			}
			//case the mouse move on the options
			case sf::Event::MouseMoved:
			{
				/* if the user pass over the button, we change the color
				of the button to blue */

				if (helpScreen.getButton(0).getGlobalBounds().
					contains(event.mouseMove.x, event.mouseMove.y))
				{
					helpScreen.getOptions()[0].setFillColor(sf::Color::Blue);
				}
				else
					helpScreen.getOptions()[0].setFillColor(sf::Color::Black);

				break;
			}

			}
		}
	}
}
