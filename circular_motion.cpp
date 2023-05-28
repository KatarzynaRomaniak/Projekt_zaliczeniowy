#include "circular_motion.h"

void circular_motion::extend()
{
	size += 0.1f;
}

circular_motion::circular_motion() {
	isOn = false;
}

void circular_motion::loadTexture()
{
	texture.loadFromFile("textures/moon.png");
}

void circular_motion::loadSprite()
{
	sprite.setTexture(texture);
}

sf::FloatRect circular_motion::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void circular_motion::spawn(float _x, float _y)
{
	loadTexture();
	loadSprite();
	sprite.setScale(size,size);
	posX = _x;
	posY = _y;
	
	sprite.setPosition(-40, -40);
	isOn = true;
	
	
}

void circular_motion::update()
{
	//if (circle.getPosition().y > WINDOW_HEIGHT) circle.setPosition(posX,-100);
		//circle.setPosition(posX+(sin(angle * π /180.0)*100),posY+(cos(angle * π / 180.0) * 100));
		//circle.setPosition(posX+sin(circle.getPosition().y/350)*100,circle.getPosition().y+3.5);
	//if(circle.getPosition().y>WINDOW_HEIGHT) circle.setPosition(circle.getPosition().x + 1, -1.5 * circle.getPosition().x - 18 * sin(3.14 * 2 * circle.getPosition().x / 180));
	//circle.setPosition(circle.getPosition().x + 1, -1.5 * circle.getPosition().x - 50 * sin(3.14 * 2 * circle.getPosition().x / 180));
	/*if (direction) {
		if (circle.getPosition().y >= WINDOW_HEIGHT) { 
			direction = 0;
			circle.setPosition(0,WINDOW_HEIGHT/2);
			if(speed<maxspeed) speed++;
			
			return;
		}
		circle.setPosition(circle.getPosition().x + 1, WINDOW_HEIGHT/2 + (0.3 * circle.getPosition().x + 180 * sin(3.14 * speed * circle.getPosition().x / 180)));
		
	}
	else {
		if (circle.getPosition().y <= 0) { 
			direction = 1; 
		circle.setPosition(0, 0);
		return;
		}
		circle.setPosition(circle.getPosition().x + 1, WINDOW_HEIGHT/2 - (0.3 * circle.getPosition().x + 180 * sin(3.14 * speed * circle.getPosition().x / 180)));
		

	}*/
	
	if (!direction) {
		if (sprite.getPosition().y < WINDOW_HEIGHT)
			sprite.setPosition(sprite.getPosition().x + 1, (angle* sprite.getPosition().x + 180 * sin(pi * speed * sprite.getPosition().x / 180)));
		else {
			direction = 1; 
			posX = sprite.getPosition().x;
		}
	}
	if (direction == 1) {
		if(sprite.getPosition().y>0)
			sprite.setPosition(posX + sin(sprite.getPosition().y / 100) * 100, sprite.getPosition().y - 1);
		else {
			direction = 2;
			posX = sprite.getPosition().x;
		}
	}
	if (direction == 2) {
		if (sprite.getPosition().y < WINDOW_HEIGHT)
			sprite.setPosition(sprite.getPosition().x + 1, (angle *(sprite.getPosition().x - posX )+ 180 * sin(pi * speed * (-sprite.getPosition().x ) / 180)));
		else {
			direction = 0;
			sprite.setPosition(0,0);
		}
	}
	
}

void circular_motion::render(sf::RenderTarget& circleTarget)
{
	
	circleTarget.draw(sprite);
}

void circular_motion::turnOff()
{
	sprite.setPosition(-10,-10);
	isOn = false;
}
