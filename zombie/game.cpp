#include "stdafx.h"
#include "game.h"

void Game::init()
{
	controller_ = new Controller( &window );
	player_ = new Player( controller_ );
	current_state_ = Alive;
	death_screen_rotation = 0.1f;
	zombie_spawn_time_ = 1;
	zombie_spawn_timer_ = 0;
}

void Game::input()
{
	while (window.pollEvent( event ))
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
		player_->update( timeElapsed, this );
		sf::Vector2f cameraPos = player_->getPosition();
		cameraPos.x = std::max( (float)Consts::CAMARA_WIDTH_HALF, std::min( (float)(Consts::GAME_WIDTH - Consts::CAMARA_WIDTH_HALF), cameraPos.x ) );
		cameraPos.y = std::max( (float)Consts::CAMERA_HEIGHT_HALF, std::min( (float)(Consts::GAME_HEIGHT - Consts::CAMERA_HEIGHT_HALF), cameraPos.y ) );
		view.setCenter( cameraPos );

		//Check collisions
		for (Zombie* zombie : zombies_)
		{
			if (zombie->checkCollision( player_ ))
			{

			}

			for (Projectile* projectile : projectiles_)
			{
				projectile->checkCollision( zombie );
			}
		}

		size_t projectiles_size = projectiles_.size();
		for (int i = projectiles_size - 1; i >= 0; --i)
		{
			projectiles_[i]->update( timeElapsed );
			if (projectiles_[i]->should_delete())
			{
				delete projectiles_[i];
				projectiles_.erase( projectiles_.begin() + i );
			}
		}

		size_t zombie_size = zombies_.size();
		for (int i = zombie_size - 1; i >= 0; --i)
		{
			zombies_[i]->update( timeElapsed, player_->getPosition() );
			if (zombies_[i]->checkCollision( player_ ))
			{
				current_state_ = Dead;
				sf::Vector2f zombie_location = zombies_[i]->getPosition();
				sf::Vector2f player_location = player_->getPosition();
				player_death_location = (zombie_location + player_location) * 0.5f;
			}
			if (zombies_[i]->should_delete())
			{
				delete zombies_[i];
				zombies_.erase( zombies_.begin() + i );
			}
		}

		zombie_spawn_timer_ += timeElapsed;

		if(zombie_spawn_timer_ > zombie_spawn_time_)
		{
			zombie_spawn_timer_ = 0;
			addZombie();
		}
	}
	else if (current_state_ == Dead)
	{
		view.setCenter( player_death_location );
		view.rotate( death_screen_rotation );
		view.zoom( 0.9995f );
		death_screen_rotation *= 0.999f;
	}
}


void Game::draw()
{
	window.clear();

	window.setView( view );

	//Draw code
	window.draw( background );
	player_->draw( window );
	for (Zombie* zombie : zombies_)
	{
		zombie->draw( window );
	}
	for (Projectile* projectile : projectiles_)
	{
		projectile->draw( window );
	}

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
}


Game::Game()
{
	//Template variables
	window.create( sf::VideoMode( Consts::WINDOW_WIDTH, Consts::WINDOW_HEIGHT ), "SFML", sf::Style::Close );
	view.setSize( Consts::CAMARA_WIDTH, Consts::CAMERA_HEIGHT );
	view.setCenter( Consts::GAME_WIDTH * 0.5f, Consts::GAME_HEIGHT * 0.5f );
	window.setView( view );
	clock.restart();
	srand( time( nullptr ) );
	rand();

	//Add new vars here
	background_texture.loadFromFile( "Assets/background.png" );
	background = sf::Sprite( background_texture );
	Zombie::texture_ = new sf::Texture;
	Zombie::texture_->loadFromFile( "Assets/zombie/idle.png" );
	Projectile::texture_ = new sf::Texture;
	Projectile::texture_->loadFromFile( "Assets/bullet.png" );
	Player::idle_texture_ = new sf::Texture;
	Player::idle_texture_->loadFromFile( "Assets/player/idle.png" );
}

Game::~Game()
{
	resetGame();
	delete Zombie::texture_;
	delete Projectile::texture_;
	delete Player::idle_texture_;
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

void Game::addProjectile( sf::Vector2f pos, float angle )
{
	projectiles_.push_back( new Projectile( pos, angle ) );
}

void Game::addZombie( sf::Vector2f pos, float angle )
{
	zombies_.push_back( new Zombie( pos, angle ) );
}

void Game::addZombie()
{
	zombies_.push_back( new Zombie( generateSpawnPos( player_->getPosition(), static_cast<sf::Vector2f>(Zombie::texture_->getSize()) ), Helper::generateRandInt( 0, 360 ) ) );
}

sf::Vector2f Game::generateSpawnPos( sf::Vector2f pos, sf::Vector2f size )
{
	sf::Vector2f spawnLocation( 0, 0 );
	do
	{
		spawnLocation.x = Helper::generateRandInt( size.x, Consts::GAME_WIDTH - size.x );
		spawnLocation.y = Helper::generateRandInt( size.y, Consts::GAME_HEIGHT - size.y );
	} while (Helper::distanceBetweenTwoPoints( pos, spawnLocation ) < Consts::ZOMBIE_SPAWN_LENGTH);
	return spawnLocation;
}
