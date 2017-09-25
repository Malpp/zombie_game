#include "stdafx.h"
#include "weapon.h"
#include "game.h"

void Weapon::update(float delta_time)
{
	if(!ready_)
	{
		reload_timer_ += delta_time;
		if(reload_timer_ > reload_time_)
		{
			reload_timer_ = 0;
			ready_ = true;
		}
	}
}

void Weapon::addAmmo(int ammo_to_add)
{
	ammo_ += std::max( 0, ammo_to_add );
}

int Weapon::getAmmo() const
{
	return ammo_;
}

void Weapon::fire(sf::Vector2f pos, float angle, Game* game)
{
	if (ammo_ != 0 && ready_)
	{
		handleFire(game, pos, angle);
		--ammo_;
		ready_ = false;
	}
}
