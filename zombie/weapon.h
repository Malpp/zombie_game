#pragma once
#include "stdafx.h"
class Game;

class Weapon
{
public:
	virtual ~Weapon() = default;
	Weapon(float reload_time, int ammo)
	{
		ready_ = true;
		this->ammo_ = ammo;
		this->reload_time_ = reload_time;
		reload_timer_ = 0;
	}
	void update( float delta_time );
	void addAmmo( int ammo_to_add );
	int getAmmo() const;
	void fire(sf::Vector2f pos, float angle, Game* game);
	virtual void handleFire( Game* game, sf::Vector2f pos, float angle ) = 0;
private:
	int ammo_;
	bool ready_;
	float reload_timer_;
	float reload_time_;
};