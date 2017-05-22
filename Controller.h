#pragma once
#include "Stick.h"
#include <SFML/Graphics.hpp>

class MainScreen;
class Resources;

class Controller
{
public:
	// the options of the game
	enum GameOptions { NEW_GAME, HELP, EXIT };

	Controller() {}
	Controller::GameOptions eventManuHandler(MainScreen& manu, sf::RenderWindow& window,
		sf::Event& event);
	void startGame(sf::RenderWindow& window, Resources& resources);
	void showHelpScreen(sf::RenderWindow& window, Resources& resources);

	~Controller() {}

private:
	std::vector<Stick> m_sticks;

};

