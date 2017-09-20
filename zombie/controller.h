#pragma once
#include "stdafx.h"

class Controller
{
public:
	Controller( sf::RenderWindow* window );
	static sf::Vector2f getControllerMove();
	float getShootingAngle(sf::Vector2f player_pos) const;
private:
	int current_controller = 0;
	sf::RenderWindow* window_;
};