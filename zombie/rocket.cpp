#include "stdafx.h"
#include "rocket.h"
#include "game.h"
#include "explosion.h"

sf::Texture* Rocket::texture_;

void Rocket::delete_()
{
	game_->addProjectile(new Explosion(sprite_.getPosition(), Helper::generateRandInt(0,360)));
	Projectile::delete_();
}
