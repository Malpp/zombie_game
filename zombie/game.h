#pragma once
#include "stdafx.h"
#include "player.h"
#include "controller.h"
#include "projectile.h"
#include "resources.h"

class Game
{
public:
	//Template variables
	Game();
	~Game();
	void run();

	//Add new vars here
	void addProjectile(sf::Vector2f pos, float angle);
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
	float frameTime = 0;
	int frameCounter = 0;

	//Add new vars here
	sf::Sprite background;
	Player* player_;
	Controller* controller_;
	std::vector<Projectile*> projectiles_;
	sf::Texture player_texture_;
	sf::Texture background_texture;
	sf::Texture projectile_texture_;
};
