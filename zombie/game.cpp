#include "stdafx.h"
#include "game.h"

void Game::init()
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
	player_texture_.loadFromFile( "Assets/player/idle.png" );
	background_texture.loadFromFile( "Assets/background.png" );
	projectile_texture_.loadFromFile( "Assets/bullet.png" );

	background = sf::Sprite( background_texture );
	controller_ = new Controller( &window );
	player_ = new Player( &player_texture_, controller_ );
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

	//Add new stuff below this
	player_->update( timeElapsed );
	sf::Vector2f cameraPos = player_->getPosition();
	cameraPos.x = std::max( (float)Consts::CAMARA_WIDTH_HALF, std::min( (float)(Consts::GAME_WIDTH - Consts::CAMARA_WIDTH_HALF), cameraPos.x ) );
	cameraPos.y = std::max( (float)Consts::CAMERA_HEIGHT_HALF, std::min( (float)(Consts::GAME_HEIGHT - Consts::CAMERA_HEIGHT_HALF), cameraPos.y ) );
	view.setCenter( cameraPos );

	if (sf::Mouse::isButtonPressed( sf::Mouse::Left ))
		addProjectile( player_->getPosition(), player_->getAngle() + 180 );
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
}


void Game::draw()
{
	window.clear();

	window.setView( view );

	//Draw code
	window.draw( background );
	player_->draw( window );
	for (Projectile* projectile : projectiles_)
	{
		projectile->draw( window );
	}

	window.display();
}


Game::Game()
{

}

Game::~Game()
{
	delete player_;
	delete controller_;
	for (Projectile* projectile : projectiles_)
	{
		delete projectile;
	}
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
	projectiles_.push_back( new Projectile( pos, angle, &projectile_texture_ ) );
}
