#include "stdafx.h"
#include "player.h"
#include "game.h"

sf::Texture* Player::idle_texture_;

Player::~Player()
{
	for (Weapon* weapon : weapons_)
	{
		delete weapon;
	}
}

void Player::update(float delta_time_, Game* game)
{
	weapons_[current_weapon_]->update( delta_time_ );

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		weapons_[current_weapon_]->fire( getPosition(), getAngle(), game );
	}

	sprite_.setRotation( controller->getShootingAngle( sprite_.getPosition() ) + 180 );
	Moveable::update( delta_time_ );
}

sf::Vector2f Player::getNextMove( float delta_time_ )
{
	return controller->getControllerMove();
}

void Player::handleCollision( Collidable* entity )
{}
