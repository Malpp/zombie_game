#pragma once
#include "stdafx.h"
#include "weapon.h"
class Game;

class RPG : public Weapon
{
public:
	RPG()
		: Weapon( Consts::RPG_RELOAD, Consts::RPG_AMMO )
	{}
	void handleFire( Game* game, sf::Vector2f pos, float angle ) override;
};