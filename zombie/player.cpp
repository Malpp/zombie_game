#include "stdafx.h"
#include "player.h"
#include "game.h"
#include "shotgun.h"
#include "flamethrower.h"

sf::Texture* Player::idle_texture_;

Player::~Player()
{
	delete default_gun_;
	if(bonus_weapon != nullptr)
	{
		delete bonus_weapon;
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

	if(bonus_weapon != nullptr)
	{
		bonus_weapon->update(delta_time_);
	}
	else
	{
		default_gun_->update(delta_time_);
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (bonus_weapon != nullptr)
		{
			bonus_weapon->fire(getPosition(), getAngle(), game);
		}
		else
		{
			default_gun_->fire(getPosition(), getAngle(), game);
		}
	}

	if(bonus_weapon != nullptr && bonus_weapon->getAmmo() < 1)
	{
		delete bonus_weapon;
		bonus_weapon = nullptr;
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

void Player::getExtraLife()
{
	lives++;
}

void Player::setBonusWeapon(BonusWeapons type)
{
	if(bonus_weapon != nullptr)
	{
		delete bonus_weapon;
		bonus_weapon = nullptr;
	}

	switch (type)
	{
	case Shotgun_:
		bonus_weapon = new Shotgun;
		break;
	case Flamethrower_:
		bonus_weapon = new Flamethrower;
		break;
	}
}

bool Player::hasBonusWeapon()
{
	return bonus_weapon != nullptr;
}

int Player::getAmmo()
{
	if(bonus_weapon != nullptr)
	{
		return bonus_weapon->getAmmo();
	}
	return -1;
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
