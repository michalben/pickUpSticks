#pragma once

#include <SFML/Graphics.hpp>

class Resources
{
public:
	Resources();
	const sf::Texture& getTexture(int index)const;

	~Resources();

private:
	sf::Texture m_textures[8];
	sf::Font m_font;

};

