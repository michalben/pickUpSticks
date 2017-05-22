#include "Resources.h"

Resources::Resources()
{

	m_textures[0].loadFromFile("background.png", sf::IntRect(0, 0, 1024, 567));
	m_textures[1].loadFromFile("gameScreen.png", sf::IntRect(0, 0, 1024, 567));
	m_textures[2].loadFromFile("helpS.png", sf::IntRect(0, 0, 1024, 567));

}

const sf::Texture& Resources::getTexture(int index) const
{
	return m_textures[index];
}


Resources::~Resources()
{
}
