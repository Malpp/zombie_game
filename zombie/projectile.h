#pragma once
#include "stdafx.h"
#include "moveable.h"
#include "helper.h"

class Projectile : public Moveable
{
public:
	Projectile(sf::Vector2f pos, float angle, sf::Texture* texture) : Moveable(pos, angle, texture, Consts::PROJECTILE_SPEED)
	{
		projectile_direction_ = Helper::movePointByAngle( 1, angle );
	}

protected:
	sf::Vector2f getNextMove(float delta_time_) override;
	void handleEdge() override;
private:
	sf::Vector2f projectile_direction_;
};