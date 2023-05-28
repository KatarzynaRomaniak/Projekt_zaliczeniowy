
#include "player.h"

#include <iostream>

player::player(float x_p, float y_p) {
	
	LoadTexture();
	LoadSprite();
	sprite.setScale(0.3f, 0.3f);
	sprite.setPosition(x_p, y_p);
	//sprite.setOrigin()
	
	
}
float player::get_currentXPosition()
{
	return sprite.getPosition().x;
}
float player::get_currentYPosition()
{
	
	return sprite.getPosition().y;
	
}

 sf::Vector2f player::bulletOrigin() 
{
	return sprite.getPosition();
}



void player::player_move(sf::Event event)
{
	//sf::Clock power_up;
	//const float time_out = 3.0f;
	 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			
				sprite.move(0.0f, -5.0f);
 
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {

					sprite.move(0.f, -12.f);

				}
			
			else {
				sprite.setPosition(sprite.getPosition());
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (sprite.getPosition().y <= WINDOW_HEIGHT-100) {
				sprite.move(0.0f, 5.0f);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					sprite.move(0.0f, 12.0f);

				}
			}
			else sprite.setPosition(sprite.getPosition());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (sprite.getPosition().x <= WINDOW_WIDTH-70.f) {
			sprite.move(5.0f, 0.0f);
			
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					sprite.move(12.0f, 0.0f);
				
			}
			}
			else sprite.setPosition(sprite.getPosition());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (sprite.getPosition().x >=25.f) {
			sprite.move(-5.0f, 0.0f);
			
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					sprite.move(-12.0f, 0.0f);
				
			}
			}
			else sprite.setPosition(sprite.getPosition());
		

	}
}



void player::render(sf::RenderTarget& target) {
	target.draw(sprite);
}

sf::FloatRect player::globalBounds() const
{
	
	return sprite.getGlobalBounds();
}

void player::set()
{
	sprite.setPosition(1000.f, 1000.f);
}

void player::HPdown()
{
	hp--;
}

bool player::isPlayerDead()
{
	
	if (hp <= 0) {
		return true;
	}
	else return false;
}

void player::resetHP()
{
	hp = 3;
}

void player::resetPosition()
{
	sprite.setPosition(WINDOW_WIDTH / 2 - 20 , WINDOW_HEIGHT/2 - 20);
}

int player::getHP()
{
	return hp;
}

void player::upHP()
{
	hp += 1;
}

void player::kill()
{
	hp = 0;
}



void player::LoadTexture()
{
	texture.loadFromFile("textures/spaceship.png");
}


void player::LoadSprite() {
	sprite.setTexture(texture);
}
