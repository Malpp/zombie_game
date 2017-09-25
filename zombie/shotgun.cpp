#include "stdafx.h"
#include "shotgun.h"
#include "game.h"
#include "bullet.h"

void Shotgun::handleFire(Game* game, sf::Vector2f pos, float angle)
{
	game->addProjectile(new Bullet(pos, angle));
	game->addProjectile(new Bullet(pos, angle + Consts::SHOTGUN_BULLET_ANGLE));
	game->addProjectile(new Bullet(pos, angle - Consts::SHOTGUN_BULLET_ANGLE));
}
