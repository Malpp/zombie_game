#pragma once
#include "stdafx.h"
#include "collidable.h"

class Moveable : public Collidable
{
public:
	virtual void update(float delta_time_, std::vector<Collidable*>* entities = {});
protected:
	Moveable( sf::Vector2f pos, float angle, sf::Texture* texture, float speed, float collision_radius ) : Collidable( pos, angle, texture, collision_radius )
	{
		this->speed = speed;
	}
	virtual sf::Vector2f getNextMove( float delta_time_ ) = 0;
	virtual bool isAtEdge();
	virtual void handleEdge();
private:
	float speed;
};
