#include "stdafx.h"
#include "collidable.h"
#include "helper.h"

float Collidable::getCollideRadius() const
{
	return collide_radius;
}

bool Collidable::checkCollision( Collidable* collidable, bool should_handle )
{
	if (collidable != nullptr && !collidable->should_delete() && Helper::distanceBetweenTwoPoints( getPosition(), collidable->getPosition() ) < (collide_radius + collidable->getCollideRadius()))
	{
		if (should_handle)
		{
			handleCollision( collidable );
		}
		return true;
	}
	return false;
}

void Collidable::draw( sf::RenderTarget& window )
{
	debug_circle_collision.setPosition( sprite_.getPosition() );
	window.draw( debug_circle_collision );
	Drawable::draw( window );
}
