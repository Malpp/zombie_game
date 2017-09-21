#pragma once
#include "stdafx.h"
#include "player.h"
#include "controller.h"
#include "projectile.h"
#include "resources.h"
#include "zombie.h"

class Game
{
public:
	//Template variables
	Game();
	~Game();
	void run();

	//Add new vars here
	void addProjectile(sf::Vector2f pos, float angle);
	void addZombie( sf::Vector2f pos, float angle );
	void addZombie();
	sf::Vector2f generateSpawnPos( sf::Vector2f pos, sf::Vector2f size );
private:
	//Template variables
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	sf::View view;
	void init();
	void input();
	void update();
	void draw();
	void resetGame();
	float frameTime = 0;
	int frameCounter = 0;

	//Add new vars here
	enum gameState
	{
		Alive,
		Dead
	};

	sf::Sprite background;
	Player* player_;
	Controller* controller_;
	std::vector<Projectile*> projectiles_;
	std::vector<Zombie*> zombies_;
	sf::Texture background_texture;
	gameState current_state_;
	float death_screen_rotation;
	sf::Vector2f player_death_location;
	float zombie_spawn_time_;
	float zombie_spawn_timer_;
};
