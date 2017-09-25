#include "stdafx.h"
#include "flamethrower.h"
#include "game.h"
#include "flame.h"

void Flamethrower::handleFire(Game* game, sf::Vector2f pos, float angle)
{
	game->addProjectile(new Flame(pos, angle));
}
