#pragma once
#include "stdafx.h"
#include "moveable.h"
#include "helper.h"

class Game;

class Zombie : public Moveable
{
public:
	Zombie( sf::Vector2f pos, float angle ) : Moveable( pos, angle, texture_, Consts::ZOMBIE_SPEED + Helper::generateRandInt( -Consts::ZOMBIE_SPEED_RANDOM, Consts::ZOMBIE_SPEED_RANDOM ), Consts::ZOMBIE_SIZE )
	{

	}
	void update(float delta_time_, sf::Vector2f& pos_to_go, bool is_player_invincible, std::vector<Collidable*>* entities = {});
	static sf::Texture* texture_;
protected:
	void handleCollision(Collidable* entity) override;
	sf::Vector2f getNextMove(float delta_time_) override;
private:
	sf::Vector2f next_pos;
	bool is_player_invincible_;
};
