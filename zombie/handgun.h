#pragma once
#include "stdafx.h"
#include "weapon.h"
class Game;

class Handgun : public Weapon
{
public:
	Handgun() : Weapon( Consts::HANDGUN_RELOAD, Consts::HANDGUN_AMMO )
	{

	}

	void handleFire( Game* game, sf::Vector2f pos, float angle) override;
};
