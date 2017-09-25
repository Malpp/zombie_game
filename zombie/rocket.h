#pragma once
#include "stdafx.h"
#include "projectile.h"
class Game;

class Rocket : public Projectile
{
public:

	Rocket( const sf::Vector2f& pos, float angle, Game* game )
		: Projectile( pos, angle, texture_, Consts::ROCKET_SPEED, Consts::ROCKET_SIZE )
	{
		game_ = game;
	}
	static sf::Texture* texture_;
	void delete_() override;
private:
	Game* game_;
};