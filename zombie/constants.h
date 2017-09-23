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
	static const float PLAYER_INVINCIBILITY_DURATION = 1.0f;
	static const int PLAYER_STARTING_LIVES = 5;

	static const int PROJECTILE_SPEED = 1600;
	static const float BULLET_SIZE = 5;

	static const float HANDGUN_RELOAD = 0.25f;
	static const int HANDGUN_AMMO = 100;
	static const int HANDGUN_SPREAD = 2;
	static const float RIFLE_RELOAD = 0.1f;
	static const int RIFLE_AMMO = 300;
	static const int RIFLE_SPREAD = 1;

	static const int ZOMBIE_SPEED = 350;
	static const float ZOMBIE_SIZE = 90;
	static const int ZOMBIE_SPEED_RANDOM = 50;
	static const float ZOMBIE_SPAWN_LENGTH = 1000;
	static const float ZOMBIE_DEFAULT_SPAWN_RATE = 1;
}