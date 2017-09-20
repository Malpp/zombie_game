#include "stdafx.h"
#include "projectile.h"

sf::Vector2f Projectile::getNextMove(float delta_time_)
{
	return projectile_direction_;
}

void Projectile::handleEdge()
{
	delete_();
}
