#pragma once
#include "stdafx.h"
#include "projectile.h"

class Flame : public Projectile
{
public:

	Flame(const sf::Vector2f& pos, float angle)
		: Projectile(pos, angle, texture_, Consts::FLAME_SPEED, Consts::FLAME_SIZE)
	{
		flame_live_timer_ = 0;
	}
	void update(float delta_time_, std::vector<Collidable*>* entities) override;
	static sf::Texture* texture_;
private:
	float flame_live_timer_;
};