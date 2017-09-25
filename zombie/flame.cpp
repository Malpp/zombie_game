#include "stdafx.h"
#include "flame.h"
#include "collidable.h"

sf::Texture* Flame::texture_;

void Flame::update(float delta_time_, std::vector<Collidable*>* entities)
{
	flame_live_timer_ += delta_time_;
	if(flame_live_timer_ > Consts::FLAME_DURATION)
	{
		delete_();
	}
	Moveable::update(delta_time_, entities);
}
