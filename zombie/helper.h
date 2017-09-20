#pragma once
#include "stdafx.h"

namespace Helper
{

	inline float degreeToRadian( float degree )
	{
		return M_PI * degree / 180;
	}

	inline float distanceBetweenTwoPoints( sf::Vector2f& p1, sf::Vector2f& p2 )
	{
		return sqrt( pow( p2.x - p1.x, 2 ) + pow( p2.y - p1.y, 2 ) );
	}

	inline sf::Vector2f movePointByAngle( float distance, float angle )
	{
		return sf::Vector2f( cos( degreeToRadian( angle ) ) * distance, sin( degreeToRadian( angle ) ) * distance );
	}

	inline float angleBetweenTwoPoints( sf::Vector2f& p1, sf::Vector2f& p2 )
	{
		return atan2( p2.y - p1.y, p2.x - p1.x ) * 180 / M_PI;
	}

	inline int generateRandInt( int min, int max )
	{
		return rand() % (max - min + 1) + min;
	}
}