#pragma once
#include "stdafx.h"
#include "moveable.h"
#include "controller.h"

class Player : public Moveable
{
public:
	Player( sf::Texture* player_idle, Controller* controller ) : Moveable( sf::Vector2f( Consts::GAME_WIDTH, Consts::GAME_HEIGHT ) * 0.5f, 0, player_idle, Consts::PLAYER_SPEED )
	{
		this->controller = controller;
	}
	void update(float delta_time_) override;
protected:
	sf::Vector2f getNextMove( float delta_time_ ) override;
private:
	Controller* controller;
};