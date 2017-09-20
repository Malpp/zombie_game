#include "stdafx.h"
#include "player.h"

void Player::update(float delta_time_)
{
	sprite_.setRotation( controller->getShootingAngle(sprite_.getPosition()) );
	Moveable::update( delta_time_ );
}

sf::Vector2f Player::getNextMove( float delta_time_ )
{
	return controller->getControllerMove();
}
