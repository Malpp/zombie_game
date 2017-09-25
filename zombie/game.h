#pragma once
#include "stdafx.h"
#include "player.h"
#include "controller.h"
#include "projectile.h"
#include "zombie.h"
#include "powerup.h"

class Game
{
public:
	//Template variables
	Game();
	~Game();
	void run();

	//Add new vars here
	void addProjectile(Projectile* projectile);
	void addZombie(sf::Vector2f& pos, float angle);
	void addZombie();
	sf::Vector2f generateSpawnPos(sf::Vector2f& pos, sf::Vector2f& size, std::vector<Zombie*>& zombie_pos);
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
	void setupDeathScreen(sf::Vector2f& zombie_location);
	void updateScoreText();
	void updateLifeText();
	void addScore();
	bool checkZombieSpawnCollision(const std::vector<sf::Vector2f>& zombies_pos, sf::Vector2f& spawn_pos);
	PowerUp* getRandomPowerup(sf::Vector2f& spawn_pos);
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

	sf::Font game_font_;
	sf::Text death_text_;
	sf::RectangleShape death_screen_shape_;
	sf::Color death_color_;
	float death_timer_;
	sf::Text score_text_;
	sf::Text life_text_;
	sf::Text ammo_text_;
	unsigned int score_;
	int score_multiplier_;
	float score_timer_;
	int extra_life_counter_;
	std::vector<PowerUp*> power_ups_;
};
