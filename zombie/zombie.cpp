#include "stdafx.h"
#include "zombie.h"
#include "helper.h"

sf::Texture* Zombie::texture_;

void Zombie::update(float delta_time_, sf::Vector2f& pos_to_go)
{
	next_pos = pos_to_go;
	Moveable::update( delta_time_ );
}

void Zombie::handleCollision(Collidable* entity)
{

}

sf::Vector2f Zombie::getNextMove(float delta_time_)
{
	sf::Vector2f current_pos = sprite_.getPosition();
	float angle_to_pos = Helper::angleBetweenTwoPoints( current_pos, next_pos );
	sprite_.setRotation( angle_to_pos );
	return Helper::movePointByAngle( 1, angle_to_pos );
}
