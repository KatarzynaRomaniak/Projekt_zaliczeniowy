#pragma once
#include "libraries.h"
class circular_motion
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int angle = 1;
	int direction=0;
	int speed=5;
	int maxspeed=6;
	float posX;
	float posY;
	bool isOn=false;
	int hp = 1;
	int radius = 40;
	float size = 0.5f;
public:
	void extend();
	circular_motion() ;
	void loadTexture();
	void loadSprite();
	sf::FloatRect getGlobalBounds();
	void spawn(float,float);
	void update();
	void render(sf::RenderTarget& circleTarget);
	bool isSpawned() {
		return isOn;
	}
	void turnOff();
};

