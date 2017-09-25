#pragma once
#include "stdafx.h"
#include "weapon.h"
class Game;

class Flamethrower : public Weapon
{
public:
	Flamethrower()
		: Weapon(Consts::FLAMETHROWER_RELOAD, Consts::FLAMETHROWER_AMMO)
	{
	}
	void handleFire(Game* game, sf::Vector2f pos, float angle) override;
};