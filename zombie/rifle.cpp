#include "stdafx.h"
#include "rifle.h"
#include "game.h"

void Rifle::handleFire(Game* game, sf::Vector2f pos, float angle)
{
	game->addProjectile( pos, angle + Helper::generateRandInt( -Consts::RIFLE_SPREAD, Consts::RIFLE_SPREAD ) );
}
