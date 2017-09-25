#pragma once
#include "stdafx.h"
#include "moveable.h"
#include "controller.h"
#include "weapon.h"
#include "handgun.h"
class Game;

class Player : public Moveable
{
public:
	Player( Controller* controller ) : Moveable( sf::Vector2f( Consts::GAME_WIDTH, Consts::GAME_HEIGHT ) * 0.5f, 0, idle_texture_, Consts::PLAYER_SPEED, Consts::PLAYER_SIZE )
	{
		this->controller = controller;
		lives = Consts::PLAYER_STARTING_LIVES;
		invincible_ = false;
	}
	~Player();
	void update( float delta_time_, Game* game );
	static sf::Texture* idle_texture_;
	enum BonusWeapons
	{
		Shotgun_,
		Flamethrower_,
		RPG_
	};
	int getLives() const;
	bool isDead() const;
	bool isInvicible() const;
	void getExtraLife();
	void setBonusWeapon(BonusWeapons type);
	bool hasBonusWeapon();
	int getAmmo();
protected:
	sf::Vector2f getNextMove( float delta_time_ ) override;
	void handleCollision( Collidable* entity ) override;
private:
	Controller* controller;
	Weapon* default_gun_ = new Handgun;
	Weapon* bonus_weapon = nullptr;
	int lives;
	bool invincible_;
	float invicibility_timer_;
};
