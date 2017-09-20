#pragma once
#include "stdafx.h"

class Resources
{
public:
	sf::Texture player_texture_;
	sf::Texture background_texture;
	sf::Texture projectile_texture_;
	Resources()
	{
		player_texture_.loadFromFile( "Assets/player/idle.png" );
		background_texture.loadFromFile( "Assets/background.png" );
		projectile_texture_.loadFromFile( "Assets/bullet.png" );
	}
};