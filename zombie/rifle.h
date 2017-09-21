#pragma once
#include "stdafx.h"
#include "weapon.h"
class Game;

class Rifle : public Weapon
{
public:
	Rifle() : Weapon( Consts::RIFLE_RELOAD, Consts::RIFLE_AMMO )
	{}

	void handleFire( Game* game, sf::Vector2f pos, float angle ) override;
};