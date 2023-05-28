#pragma once
#include "libraries.h"
#include "player.h"
class Projectile
{
public:
	Projectile(sf::Texture* texture, sf::Vector2f);
	~Projectile() = default;
	
	sf::FloatRect getProjectileBounds();
	void update();
	void render(sf::RenderTarget* target);
	float get_X();
	float get_Y();
	void LoadSprite();
	bool ProjectileIsOut();
private:
	
	sf::Sprite sprite;
	sf::Texture* texture;
	const float speed = 15.f;
};

