#pragma once
#include "stdafx.h"

class Drawable
{
public:
	virtual void delete_();
	bool should_delete();
	virtual void draw(sf::RenderTarget& window);
	sf::Vector2f getPosition() const;
	float getAngle() const;
protected:
	Drawable( sf::Vector2f& pos, float angle, sf::Texture* texture )
	{
		sprite_ = sf::Sprite( *texture );
		half_texture_size_ = static_cast<sf::Vector2f>(texture->getSize()) * 0.5f;
		sprite_.setOrigin( half_texture_size_ );
		sprite_.setRotation( angle );
		sprite_.setPosition( pos );
		to_delete_ = false;
	};
	sf::Sprite sprite_;
	sf::Vector2f half_texture_size_;
private:
	bool to_delete_;
};