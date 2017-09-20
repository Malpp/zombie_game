#include "stdafx.h"
#include "handgun.h"
#include "game.h"

void Handgun::handleFire(Game* game, sf::Vector2f pos, float angle)
{
	game->addProjectile( pos, angle );
}
