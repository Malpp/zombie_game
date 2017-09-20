#include "stdafx.h"
#include "projectile.h"

sf::Texture* Projectile::texture_;

void Projectile::handleCollision(Collidable* entity)
{
	delete_();
	entity->delete_();
}

sf::Vector2f Projectile::getNextMove(float delta_time_)
{
	return projectile_direction_;
}

void Projectile::handleEdge()
{
	delete_();
}
