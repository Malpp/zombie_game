#include "stdafx.h"
#include "rpg.h"
#include "game.h"
#include "rocket.h"

void RPG::handleFire(Game* game, sf::Vector2f pos, float angle)
{
	game->addProjectile( new Rocket( pos, angle + Helper::generateRandInt(-Consts::RPG_SPREAD, Consts::RPG_SPREAD), game ) );
}
