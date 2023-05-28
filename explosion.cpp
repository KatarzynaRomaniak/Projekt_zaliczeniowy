#include "explosion.h"

explosion::explosion(float x, float y, sf::Texture* boom)
{
	texture = boom;
	sprite.setTexture(*texture);
	sprite.setPosition(x,y);
}

void explosion::render(sf::RenderTarget& target)
{
	
	if (time <= 400) {
		target.draw(sprite);
		time++;
	}
	else { 
		
		time = 0; }
	
}


