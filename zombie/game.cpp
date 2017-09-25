#include "stdafx.h"
#include "game.h"
#include "shotgun_power.h"
#include "flamethrower_power.h"
#include "rpg_power.h"
#include "bullet.h"
#include "flame.h"

void Game::init()
{
	view = sf::View();
	view.setSize(Consts::CAMARA_WIDTH, Consts::CAMERA_HEIGHT);
	view.setCenter(Consts::GAME_WIDTH * 0.5f, Consts::GAME_HEIGHT * 0.5f);
	window.setView(view);
	controller_ = new Controller(&window);
	player_ = new Player(controller_);
	current_state_ = Alive;
	death_screen_rotation = 0.2f;
	zombie_spawn_time_ = Consts::ZOMBIE_DEFAULT_SPAWN_RATE;
	zombie_spawn_timer_ = 0;
	score_ = 0;
	score_multiplier_ = Consts::DEFAULT_SCORE_MULTIPLER;
	extra_life_counter_ = 0;
	updateLifeText();
}

void Game::input()
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				window.close();
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
		break;
	}
}

void Game::update()
{
	float timeElapsed = clock.restart().asSeconds();

	//Fps counter
	frameTime += timeElapsed;
	if (frameTime > 1)
	{
		std::cout << "FPS: " << frameCounter << "\n";
		frameTime = 0;
		frameCounter = 0;
	}
	frameCounter++;

	if (current_state_ == Alive)
	{

		//Score update
		score_timer_ += timeElapsed;

		//Player update
		player_->update(timeElapsed, this);

		if(player_->hasBonusWeapon())
		{
			ammo_text_.setString(std::to_string(player_->getAmmo()));
		}

		//Camera update
		sf::Vector2f cameraPos = player_->getPosition();
		cameraPos.x = std::max((float)Consts::CAMARA_WIDTH_HALF, std::min((float)(Consts::GAME_WIDTH - Consts::CAMARA_WIDTH_HALF), cameraPos.x));
		cameraPos.y = std::max((float)Consts::CAMERA_HEIGHT_HALF, std::min((float)(Consts::GAME_HEIGHT - Consts::CAMERA_HEIGHT_HALF), cameraPos.y));
		view.setCenter(cameraPos);

		//Projectile update
		for each (Projectile* projectile in projectiles_)
		{
			projectile->update(timeElapsed);
		}

		for (int i = power_ups_.size() - 1; i >= 0; i--)
		{
			if(power_ups_[i]->checkCollision(player_))
			{
				player_->setBonusWeapon(power_ups_[i]->getBonusType());
				delete power_ups_[i];
				power_ups_.erase(power_ups_.begin() + i);
			}
		}

		//Zombie update
		std::vector<Collidable*> collision_vector(zombies_.begin(), zombies_.end());
		for (int i = zombies_.size() - 1; i >= 0; --i)
		{

			//Player-Zombie collision
			if (player_->checkCollision(zombies_[i]) && !player_->should_delete())
			{
				updateLifeText();
				if (player_->isDead())
				{
					current_state_ = Dead;
					setupDeathScreen(zombies_[i]->getPosition());
				}
			}

			//Projectile-Zombie collision
			for (int j = projectiles_.size() - 1; j >= 0; --j)
			{
				projectiles_[j]->checkCollision(zombies_[i]);
				if (projectiles_[j]->should_delete())
				{
					delete projectiles_[j];
					projectiles_.erase(projectiles_.begin() + j);
				}
			}

			//Zombie-Zombie collision
			collision_vector.erase(collision_vector.begin() + i);
			zombies_[i]->update(timeElapsed, player_->getPosition(), player_->isInvicible(), &collision_vector);
			collision_vector.push_back(zombies_[i]);
			if (zombies_[i]->should_delete())
			{
				//Dead zombie
				int roll_for_powerup = Helper::generateRandInt(1, 100);
				if(roll_for_powerup < Consts::POWERUP_SPAWN_RATE)
				{
					power_ups_.push_back(getRandomPowerup(zombies_[i]->getPosition()));
				}
				delete zombies_[i];
				zombies_.erase(zombies_.begin() + i);
				addScore();
			}
		}

		//Zombie spawning
		zombie_spawn_timer_ += timeElapsed;
		if (zombie_spawn_timer_ > zombie_spawn_time_)
		{
			zombie_spawn_timer_ = 0;
			addZombie();
		}
	}
	else if (current_state_ == Dead)
	{
		//Reset game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			resetGame();
			init();
		}

		//Death screen animation (runs at 60 FPS)
		death_timer_ += timeElapsed;
		if (death_timer_ > Consts::FRAME_TIME)
		{
			death_timer_ = 0;
			view.rotate(death_screen_rotation);
			view.zoom(0.995f);
			death_screen_rotation *= 0.9999999f;
			if (Helper::generateRandInt(0, 1) == 1 && death_color_.a < 255)
			{
				death_color_.a += 1;
			}
			death_screen_shape_.setFillColor(death_color_);
		}
	}
}


void Game::draw()
{
	window.clear();

	window.setView(view);

	//Draw code
	window.draw(background);

	//DRAWING MAIN GAME
	for (PowerUp* power_up : power_ups_)
	{
		power_up->draw(window);
	}
	player_->draw(window);
	for (Zombie* zombie : zombies_)
	{
		zombie->draw(window);
	}
	for (Projectile* projectile : projectiles_)
	{
		projectile->draw(window);
	}

	//DRAW HUD
	window.setView(window.getDefaultView());
	
	window.draw(score_text_);
	window.draw(life_text_);

	if(player_->hasBonusWeapon())
	{
		window.draw(ammo_text_);
	}

	if (current_state_ == Dead)
	{
		window.draw(death_screen_shape_);
		window.draw(death_text_);
	}

	//Set back to game view
	window.setView(view);

	window.display();
}

void Game::resetGame()
{
	delete player_;
	delete controller_;
	for (Projectile* projectile : projectiles_)
	{
		delete projectile;
	}
	projectiles_.clear();
	for (Zombie* zombie : zombies_)
	{
		delete zombie;
	}
	zombies_.clear();
	for (PowerUp* power_up : power_ups_)
	{
		delete power_up;
	}
	power_ups_.clear();
}

void Game::setupDeathScreen(sf::Vector2f& zombie_location)
{
	sf::Vector2f player_location = player_->getPosition();
	player_death_location = (zombie_location + player_location) * 0.5f;
	view.setCenter(player_death_location);
	death_text_.setPosition(window.getDefaultView().getSize() * 0.5f);
	death_color_ = sf::Color(255, 0, 0, 0);
	death_timer_ = 1;
}

void Game::updateScoreText()
{
	score_text_.setString(std::to_string(score_));
}

void Game::updateLifeText()
{
	life_text_.setString("x" + std::to_string(player_->getLives()));
}

void Game::addScore()
{
	if(score_timer_ > Consts::SCORE_BONUS_TIME)
	{
		score_multiplier_ = Consts::DEFAULT_SCORE_MULTIPLER;
		score_timer_ = 0;
	}
	score_ += Consts::ZOMBIE_SCORE + std::min( Consts::MAX_SCORE_BONUS,Consts::ZOMBIE_BONUS_SCORE * score_multiplier_);
	score_multiplier_++;
	updateScoreText();
	if (score_ / Consts::BONUS_LIFE_SCORE > extra_life_counter_)
	{
		extra_life_counter_++;
		player_->getExtraLife();
		updateLifeText();
	}
}

bool Game::checkZombieSpawnCollision(const std::vector<sf::Vector2f>& zombies_pos, sf::Vector2f& spawn_pos)
{
	for (sf::Vector2f pos : zombies_pos)
	{
		if (Consts::ZOMBIE_SIZE * 2 > Helper::distanceBetweenTwoPoints(pos, spawn_pos))
		{
			return true;
		}
	}
	return false;
}

PowerUp* Game::getRandomPowerup(sf::Vector2f& spawn_pos)
{
	int roll = Helper::generateRandInt(1, 3);
	switch (roll)
	{
	case 1:
		return new ShotgunPower(spawn_pos);
	case 2:
		return new FlameThrowerPower(spawn_pos);
	case 3:
		return new RPGPower(spawn_pos);
	default:
		return new ShotgunPower(spawn_pos);
	}
}

Game::Game()
{
	//Template variables
	window.create(sf::VideoMode(Consts::WINDOW_WIDTH, Consts::WINDOW_HEIGHT), "SFML", sf::Style::Close);
	clock.restart();
	srand(time(nullptr));
	rand();

	//Add new vars here
	background_texture.loadFromFile("Assets/background.png");
	background = sf::Sprite(background_texture);
	Zombie::texture_ = new sf::Texture;
	Zombie::texture_->loadFromFile("Assets/zombie/idle.png");
	Bullet::texture_ = new sf::Texture;
	Bullet::texture_->loadFromFile("Assets/bullet.png");
	Player::idle_texture_ = new sf::Texture;
	Player::idle_texture_->loadFromFile("Assets/player/idle.png");
	ShotgunPower::texture_ = new sf::Texture;
	ShotgunPower::texture_->loadFromFile("Assets/weapons/shotgun.png");
	FlameThrowerPower::texture_ = new sf::Texture;
	FlameThrowerPower::texture_->loadFromFile("Assets/weapons/flamethrower.png");
	RPGPower::texture_ = new sf::Texture;
	RPGPower::texture_->loadFromFile("Assets/weapons/rocket.png");
	Flame::texture_ = new sf::Texture;
	Flame::texture_->loadFromFile("Assets/weapons/flame.png");

	game_font_.loadFromFile("Assets/emulogic.ttf");
	death_text_ = sf::Text("      You are dead\nPress [Enter] to restart", game_font_);
	death_text_.setOrigin(sf::Vector2f(12 * death_text_.getCharacterSize(), death_text_.getCharacterSize()));
	death_screen_shape_ = sf::RectangleShape(window.getDefaultView().getSize());
	death_screen_shape_.setPosition(sf::Vector2f(0, 0));
	score_text_ = sf::Text("0", game_font_);
	life_text_ = sf::Text("x0", game_font_);
	ammo_text_ = sf::Text("0", game_font_);
	score_text_.setCharacterSize(15);
	life_text_.setCharacterSize(15);
	ammo_text_.setCharacterSize(15);
	life_text_.setPosition(5, 5);
	score_text_.setPosition(5, 20);
	ammo_text_.setPosition(5, 35);
}

Game::~Game()
{
	resetGame();
	delete Zombie::texture_;
	delete Bullet::texture_;
	delete Player::idle_texture_;
	delete ShotgunPower::texture_;
	delete FlameThrowerPower::texture_;
	delete RPGPower::texture_;
	delete Flame::texture_;
}

void Game::run()
{
	init();
	while (window.isOpen())
	{
		input();
		update();
		draw();
	}
}

void Game::addProjectile(Projectile* projectile)
{
	projectiles_.push_back(projectile);
}

void Game::addZombie(sf::Vector2f& pos, float angle)
{
	zombies_.push_back(new Zombie(pos, angle));
}

void Game::addZombie()
{
	zombies_.push_back(new Zombie(generateSpawnPos(player_->getPosition(), static_cast<sf::Vector2f>(Zombie::texture_->getSize()), zombies_), Helper::generateRandInt(0, 360)));
}

sf::Vector2f Game::generateSpawnPos(sf::Vector2f& pos, sf::Vector2f& size, std::vector<Zombie*>& zombie_pos)
{
	sf::Vector2f spawnLocation(0, 0);
	std::vector<sf::Vector2f> zombie_locations;
	for (Zombie* zombie : zombie_pos)
	{
		zombie_locations.push_back(zombie->getPosition());
	}

	do
	{
		spawnLocation.x = Helper::generateRandInt(size.x, Consts::GAME_WIDTH - size.x);
		spawnLocation.y = Helper::generateRandInt(size.y, Consts::GAME_HEIGHT - size.y);
	} while (Helper::distanceBetweenTwoPoints(pos, spawnLocation) < Consts::ZOMBIE_SPAWN_LENGTH || checkZombieSpawnCollision(zombie_locations, spawnLocation));
		
	return spawnLocation;
}


