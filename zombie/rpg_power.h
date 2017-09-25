#pragma once
#include "stdafx.h"
#include "powerup.h"
#include "player.h"

class RPGPower : public PowerUp
{
public:
	RPGPower(sf::Vector2f& pos)
		: PowerUp(pos, texture_)
	{
	}
	static sf::Texture* texture_;
	Player::BonusWeapons getBonusType() override;
};