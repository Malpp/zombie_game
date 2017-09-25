#pragma once
#include "stdafx.h"
#include "projectile.h"

class Explosion : public Projectile
{
public:

	Explosion( const sf::Vector2f& pos, float angle )
		: Projectile( pos, angle, texture_, Consts::EXPLOSION_SPEED, Consts::EXPLOSION_SIZE )
	{
		explosion_timer_ = 0;
	}
	void update(float delta_time_, std::vector<Collidable*>* entities) override;
protected:
	void handleCollision(Collidable* entity) override;
public:
	static sf::Texture* texture_;
	float explosion_timer_;
};