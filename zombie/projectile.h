#pragma once
#include "stdafx.h"
#include "moveable.h"
#include "helper.h"

class Projectile : public Moveable
{
public:
	Projectile(sf::Vector2f pos, float angle ) : Moveable(pos, angle, texture_, Consts::PROJECTILE_SPEED, Consts::BULLET_SIZE )
	{
		projectile_direction_ = Helper::movePointByAngle( 1, angle );
	}
	static sf::Texture* texture_;
protected:
	void handleCollision(Collidable* entity) override;
	sf::Vector2f getNextMove(float delta_time_) override;
	void handleEdge() override;
private:
	sf::Vector2f projectile_direction_;
};
