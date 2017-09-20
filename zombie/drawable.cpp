#include "stdafx.h"
#include "drawable.h"

void Drawable::delete_()
{
	to_delete_ = true;
}

bool Drawable::should_delete()
{
	return to_delete_;
}

void Drawable::draw(sf::RenderTarget& window)
{
	window.draw( sprite_ );
}

sf::Vector2f Drawable::getPosition() const
{
	return sprite_.getPosition();
}

float Drawable::getAngle() const
{
	return sprite_.getRotation();
}
