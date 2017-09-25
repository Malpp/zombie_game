#include "stdafx.h"
#include "rpg_power.h"

sf::Texture* RPGPower::texture_;

Player::BonusWeapons RPGPower::getBonusType()
{
	return Player::BonusWeapons::RPG_;
}
