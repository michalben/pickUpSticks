#include "Stick.h"

#define WIDTH_SCREEN 1024
#define HEIGHT_SCREEN 768 

Stick::Stick() {

	srand(time(NULL));

	// set the size of the stick
	m_stick.setSize(sf::Vector2f(100, 50));
	// set the thickness outline of the stick
	m_stick.setOutlineThickness(5);
	// set the color of the stick
	m_stick.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	// set the position of the stick
	m_stick.setPosition(sf::Vector2f(rand() % (WIDTH_SCREEN - 100), rand() % (HEIGHT_SCREEN - 50)));
	//set the angle of the stick
	m_stick.setRotation(rand() % 180);

}
