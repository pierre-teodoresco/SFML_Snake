#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "Utils.h"

class Apple
{
private:
	sf::CircleShape m_shape;
public:
	/* constructor */
	Apple();
	Apple(const Apple&) = delete;
private:
	void generate();								// randomly generating the apple's spawn position
public:
	void draw(sf::RenderWindow* p_window) const;	// makes the window draws apple m_shape

	/* getter */
	sf::Vector2f getPosition() const;				// getter on m_shape position
};