#pragma once
#include "stdafx.h"
#include "weapon.h"
class Game;

class Shotgun : public Weapon
{
public:
	Shotgun()
		: Weapon(Consts::SHOTGUN_RELOAD, Consts::SHOTGUN_AMMO)
	{
	}
	void handleFire(Game* game, sf::Vector2f pos, float angle) override;
};