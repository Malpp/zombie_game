#include "stdafx.h"
#include "handgun.h"
#include "game.h"
#include "bullet.h"

void Handgun::handleFire(Game* game, sf::Vector2f pos, float angle)
{
	game->addProjectile(new Bullet(pos, angle + Helper::generateRandInt(-Consts::HANDGUN_SPREAD, Consts::HANDGUN_SPREAD)) );
}
