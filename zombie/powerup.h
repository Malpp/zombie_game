#pragma once
#include "stdafx.h"
#include "collidable.h"
#include "player.h"

class PowerUp : public Collidable
{
public:
	PowerUp(sf::Vector2f& pos, sf::Texture* texture)
		: Collidable(pos, 0, texture, Consts::POWERUP_SIZE_RADIUS)
	{
	}
	virtual Player::BonusWeapons getBonusType() = 0;

protected:
	void handleCollision(Collidable* entity) override;
};
