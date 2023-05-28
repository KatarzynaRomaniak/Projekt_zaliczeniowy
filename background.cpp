#include "background.h"

background::background()
{
	setTexture();
	setSprite();
	
}

void background::setTexture()
{
	backgroundTexture.loadFromFile("Textures/backgrounddd.jpg");
}

void background::setSprite()
{
	sprite.setTexture(backgroundTexture);
}
void background::render(sf::RenderTarget& target) {
	target.draw(sprite);
}
