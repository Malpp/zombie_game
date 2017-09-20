#include "stdafx.h"
#include "collidable.h"
#include "helper.h"

float Collidable::getCollideRadius() const
{
	return collide_radius;
}

bool Collidable::checkCollision( Collidable* entity )
{
	if (entity != nullptr && !entity->should_delete() && Helper::distanceBetweenTwoPoints( getPosition(), entity->getPosition() ) < (collide_radius + entity->getCollideRadius()))
	{
		handleCollision( entity );
		return true;
	}
	return false;
}

void Collidable::draw(sf::RenderTarget& window)
{
	debug_circle_collision.setPosition( sprite_.getPosition() );
	window.draw( debug_circle_collision );
	Drawable::draw( window );
}
