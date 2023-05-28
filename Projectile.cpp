#include "Projectile.h"


Projectile::Projectile(sf::Texture* texture, sf::Vector2f xy)
{
	this->texture = texture;
	sprite.setTexture(*texture);
	sprite.setPosition(xy);
	sprite.setScale(0.2f,0.2f);

}

sf::FloatRect Projectile::getProjectileBounds()
{
	return sprite.getGlobalBounds();
}

void Projectile::update()
{
	
		sprite.move(0, -speed);
	

}

void Projectile::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

float Projectile::get_X()
{
	return sprite.getPosition().x;
}

float Projectile::get_Y()
{
	return sprite.getPosition().y;
}



void Projectile::LoadSprite()
{
	sprite.setTexture(*texture);
}

bool Projectile::ProjectileIsOut()
{
	return sprite.getPosition().y < 0;
}
