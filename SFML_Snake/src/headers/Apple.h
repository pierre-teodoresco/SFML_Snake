#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "Utils.h"

class Apple
{
private:
	sf::CircleShape m_shape;
public:
	Apple();
private:
	void generate();
public:
	void draw(sf::RenderWindow* p_window) const;
	sf::Vector2f getPosition() const;
};