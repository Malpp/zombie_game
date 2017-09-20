#pragma once
#include "stdafx.h"
#include "moveable.h"

class Zombie : public Moveable
{
public:
	Zombie( sf::Vector2f pos, float angle ) : Moveable( pos, angle, texture_, Consts::ZOMBIE_SPEED, Consts::ZOMBIE_SIZE )
	{

	}
	void update(float delta_time_, sf::Vector2f& pos_to_go);
	static sf::Texture* texture_;
protected:
	void handleCollision(Collidable* entity) override;
	sf::Vector2f getNextMove(float delta_time_) override;
private:
	sf::Vector2f next_pos;
};
