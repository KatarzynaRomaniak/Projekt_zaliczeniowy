#pragma once
#include "libraries.h"

class background
{
public:
	background();
	void setTexture();
	void setSprite();
	void render(sf::RenderTarget&);
		



private:
	sf::Texture backgroundTexture;
	sf::Sprite sprite;
};

