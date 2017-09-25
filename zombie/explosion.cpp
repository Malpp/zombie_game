#include "stdafx.h"
#include "explosion.h"

sf::Texture* Explosion::texture_;

void Explosion::update(float delta_time_, std::vector<Collidable*>* entities)
{
	explosion_timer_ += delta_time_;
	if(explosion_timer_ > Consts::EXPLOSION_DURATION)
	{
		delete_();
	}
	Projectile::update( delta_time_, entities );
}

void Explosion::handleCollision(Collidable* entity)
{
	entity->delete_();
}
