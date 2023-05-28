#pragma once
#include "libraries.h"
class explosion
{
public:
	explosion(float ,float,sf::Texture*);
	void render(sf::RenderTarget&);

private:
	

	int time = 0;
	sf::Clock timer;
	sf::Sprite sprite;
	sf::Texture* texture;
};

