#pragma once
#include"libraries.h"
#include"Obiekt.h"

class player
{
public:
	player(float x_p, float y_p);
	~player() = default;
	friend class Projectile;
	

	void player_move(sf::Event);
	float get_currentXPosition();
	float get_currentYPosition();
	 sf::Vector2f bulletOrigin();
	void render(sf::RenderTarget& target);
	sf::FloatRect globalBounds() const;
	void set();
	void HPdown();
	void drawHP();
	bool isPlayerDead();
	void resetHP();
	void resetPosition();
	int getHP();
	void upHP();
	void kill();
private:
	 
	int hp = 3;
	sf::Text health;
	sf::Font font;
	sf::Sprite sprite;
	sf::Texture texture;
	
	void LoadSprite();
	void LoadTexture();
	
};

