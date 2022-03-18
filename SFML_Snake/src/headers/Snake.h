#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Utils.h"
#include "Apple.h"

enum Direction { UP = 0, DOWN, LEFT, RIGHT, STOP };

class Snake
{
private:
	std::vector<sf::RectangleShape> m_body;
	Direction m_direction;
	unsigned int m_point;
public:
	Snake();
	Snake(const Snake&) = delete;
private:
	void setDirection();
public:
	void draw(sf::RenderWindow* p_window) const;
	void move();
	bool isDead() const;
	void eat(Apple& apple);

	/* Getters */
	unsigned int getPoints() const;
	std::vector<sf::Vector2f> getPositions() const;
};