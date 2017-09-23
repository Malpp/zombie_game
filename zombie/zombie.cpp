#include "stdafx.h"
#include "zombie.h"
#include "helper.h"
#include "game.h"

sf::Texture* Zombie::texture_;

void Zombie::update(float delta_time_, sf::Vector2f& pos_to_go, bool is_player_invincible, std::vector<Collidable*>* entities)
{
	is_player_invincible_ = is_player_invincible;
	next_pos = pos_to_go;
	Moveable::update( delta_time_, entities );
}

void Zombie::handleCollision(Collidable* entity)
{
	delete_();
}

sf::Vector2f Zombie::getNextMove(float delta_time_)
{
	sf::Vector2f current_pos = sprite_.getPosition();
	float angle_to_pos = Helper::angleBetweenTwoPoints( current_pos, next_pos );
	if(is_player_invincible_)
	{
		angle_to_pos += 180;
	}
	sprite_.setRotation( angle_to_pos );
	return Helper::movePointByAngle( 1, angle_to_pos );
}
