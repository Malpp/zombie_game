#pragma once
#include "stdafx.h"
#include "projectile.h"

class Bullet : public Projectile
{
public:

	Bullet(const sf::Vector2f& pos, float angle)
		: Projectile(pos, angle, texture_, Consts::BULLET_SPEED, Consts::BULLET_SIZE)
	{
	}
	static sf::Texture* texture_;
};