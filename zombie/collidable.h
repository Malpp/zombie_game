#pragma once
#include "stdafx.h"
#include "drawable.h"

class Collidable : public Drawable
{
public:
	Collidable(sf::Vector2f& pos, float angle, sf::Texture* texture, float collide_size_radius)
		: Drawable(pos, angle, texture)
	{
		collide_radius = collide_size_radius;
		debug_circle_collision = sf::CircleShape( collide_size_radius );
		debug_circle_collision.setFillColor( sf::Color::Transparent );
		debug_circle_collision.setOutlineColor( sf::Color::Red );
		debug_circle_collision.setOutlineThickness( 3 );
		debug_circle_collision.setOrigin( collide_size_radius, collide_size_radius );
	}
	float getCollideRadius() const;
	bool checkCollision(Collidable* collidable);
	void draw(sf::RenderTarget& window) override;
protected:
	virtual void handleCollision( Collidable* entity ) = 0;
private:
	float collide_radius;
	sf::CircleShape debug_circle_collision;
};
