#include "stdafx.h"
#include "controller.h"
#include "helper.h"


Controller::Controller( sf::RenderWindow* window )
{
	window_ = window;
}

sf::Vector2f Controller::getControllerMove()
{
	sf::Vector2f final_move( 0, 0 );
	int move_by = 0;
	if (sf::Keyboard::isKeyPressed( sf::Keyboard::W ))
	{
		final_move.y -= 1;
		move_by = 1;
	}

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::A ))
	{
		final_move.x -= 1;
		move_by = 1;
	}

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
	{
		final_move.y += 1;
		move_by = 1;
	}

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::D ))
	{
		final_move.x += 1;
		move_by = 1;
	}

	float angle = Helper::angleBetweenTwoPoints( sf::Vector2f( 0, 0 ), final_move );
	return Helper::movePointByAngle( move_by, angle );
}

float Controller::getShootingAngle(sf::Vector2f player_pos) const
{
	sf::Vector2f mouse_pos = window_->mapPixelToCoords(sf::Mouse::getPosition( *window_ ));
	return Helper::angleBetweenTwoPoints( mouse_pos, player_pos );
}
