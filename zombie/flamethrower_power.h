#pragma once
#include "stdafx.h"
#include "powerup.h"
#include "player.h"

class FlameThrowerPower : public PowerUp
{
public:
	FlameThrowerPower(sf::Vector2f& pos)
		: PowerUp(pos, texture_)
	{
	}
	static sf::Texture* texture_;
	Player::BonusWeapons getBonusType() override;
};