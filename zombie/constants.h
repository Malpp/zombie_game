#pragma once

namespace Consts
{
	static const float FRAME_TIME = 0.01667f;

	static const int GAME_HEIGHT = 4096;
	static const int GAME_WIDTH = 4096;
	static const int CAMERA_HEIGHT = 1080 * 2;
	static const int CAMARA_WIDTH = 1920 * 2;
	static const int CAMERA_HEIGHT_HALF = CAMERA_HEIGHT / 2;
	static const int CAMARA_WIDTH_HALF = CAMARA_WIDTH / 2;
	static const int WINDOW_HEIGHT = 720;
	static const int WINDOW_WIDTH = 1280;

	static const int PLAYER_SPEED = 500;
	static const float PLAYER_SIZE = 70;
	static const float PLAYER_INVINCIBILITY_DURATION = 2.0f;
	static const int PLAYER_STARTING_LIVES = 5;

	static const int BULLET_SPEED = 1600;
	static const float BULLET_SIZE = 6;

	static const float HANDGUN_RELOAD = 0.25f;
	static const int HANDGUN_AMMO = -1;
	static const int HANDGUN_SPREAD = 2;

	static const float SHOTGUN_RELOAD = 0.35f;
	static const int SHOTGUN_AMMO = 100;
	static const int SHOTGUN_SPREAD = 4;
	static const float SHOTGUN_BULLET_ANGLE = 15;

	static const int FLAME_SPEED = 800;
	static const float FLAME_SIZE = 50;
	static const float FLAME_DURATION = 1;

	static const float FLAMETHROWER_RELOAD = 0.1f;
	static const int FLAMETHROWER_AMMO = 200;
	static const int FLAMETHROWER_SPREAD = 10;

	static const float RPG_RELOAD = 1;
	static const int RPG_AMMO = 20;
	static const int RPG_SPREAD = 1;

	static const int ROCKET_SPEED = 2000;
	static const float ROCKET_SIZE = 33 / 2;

	static const int EXPLOSION_SPEED = 0;
	static const float EXPLOSION_SIZE = 200;
	static const float EXPLOSION_DURATION = 1;

	static const int ZOMBIE_SPEED = 350;
	static const float ZOMBIE_SIZE = 90;
	static const int ZOMBIE_SPEED_RANDOM = 50;
	static const float ZOMBIE_SPAWN_LENGTH = 1000;
	static const float ZOMBIE_DEFAULT_SPAWN_RATE = 1;

	static const int DEFAULT_SCORE_MULTIPLER = 0;
	static const int ZOMBIE_SCORE = 100;
	static const int ZOMBIE_BONUS_SCORE = 10;
	static const int BONUS_LIFE_SCORE = 50000;
	static const float SCORE_BONUS_TIME = 0.5f;
	static const int MAX_SCORE_BONUS = 500;
	
	static const float POWERUP_SIZE_RADIUS = 50;
	//under a roll for 1 to 100
	static const int POWERUP_SPAWN_RATE = 500;
}