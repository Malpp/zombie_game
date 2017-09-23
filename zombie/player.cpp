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
	if(invincible_)
	{
		invicibility_timer_ += delta_time_;
		if(invicibility_timer_ > Consts::PLAYER_INVINCIBILITY_DURATION)
		{
			invicibility_timer_ = 0;
			invincible_ = false;
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		current_weapon_ = Handgun_;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		current_weapon_ = Rifle_;
	}
	weapons_[current_weapon_]->update( delta_time_ );

	//if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		weapons_[current_weapon_]->fire( getPosition(), getAngle(), game );
	}

	sprite_.setRotation( controller->getShootingAngle( sprite_.getPosition() ) + 180 );
	Moveable::update( delta_time_ );
}

int Player::getLives() const
{
	return lives;
}

bool Player::isDead() const
{
	return lives < 1;
}

bool Player::isInvicible() const
{
	return invincible_;
}

sf::Vector2f Player::getNextMove( float delta_time_ )
{
	return controller->getControllerMove();
}

void Player::handleCollision( Collidable* entity )
{
	lives--;
	if(!isDead())
	{
		entity->delete_();
		invincible_ = true;
	}
}
