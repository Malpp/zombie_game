#include "stdafx.h"
#include "flamethrower_power.h"

sf::Texture* FlameThrowerPower::texture_;

Player::BonusWeapons FlameThrowerPower::getBonusType()
{
	return Player::BonusWeapons::Flamethrower_;
}
