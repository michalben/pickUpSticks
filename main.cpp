#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#else
#error "Unrecognized configuration!"
#endif

#include <sstream>
#include <iostream>
#include "MainScreen.h"
#include "Resources.h"
#include "Controller.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(1024, 567), "Jackstraws Game", sf::Style::Close);

	MainScreen mainScreen;
	Resources resources;
	Controller controller;

	sf::Event event;

	sf::Sprite background(resources.getTexture(0), sf::IntRect(0, 0, 1024, 567));

	while (window.isOpen())
	{
		window.clear();
		window.draw(background);
		mainScreen.drawButtons(window);
		window.display();
		switch (controller.eventManuHandler(mainScreen, window, event)) {

		case Controller::GameOptions::NEW_GAME:
			controller.startGame(window, resources);
			break;

		case Controller::GameOptions::HELP:
			controller.showHelpScreen(window, resources);

		case Controller::GameOptions::EXIT:
			break;

		default:
			break;

		}
	}
	return EXIT_SUCCESS;
}