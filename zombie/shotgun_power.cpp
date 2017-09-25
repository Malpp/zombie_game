#include "stdafx.h"
#include "shotgun_power.h"

sf::Texture* ShotgunPower::texture_;

Player::BonusWeapons ShotgunPower::getBonusType()
{
	return Player::BonusWeapons::Shotgun_;
}
