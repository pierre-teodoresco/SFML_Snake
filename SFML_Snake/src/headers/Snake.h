#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Utils.h"
#include "Apple.h"

enum Direction { UP = 0, DOWN, LEFT, RIGHT, STOP };	// all snake's possible direction

class Snake
{
private:
	std::vector<sf::RectangleShape> m_body;
	Direction m_direction;
	unsigned int m_point;
public:
	/* constructor */
	Snake();	
	Snake(const Snake&) = delete;
private:
	void setDirection();							// setter on m_direction using user input
public:
	void draw(sf::RenderWindow* p_window) const;	// makes the window draw all m_body RectangleShapes
	void move();									// moves the snake using switching on m_direction
	bool isDead() const;							// checks if the snake has hitten a collision or himself
	void eat(Apple& apple);							// makes the snake growth and regenerate the apple if he eat it

	/* getters */
	unsigned int getPoints() const;					// getter on m_point
	std::vector<sf::Vector2f> getPositions() const;	// returns a vector of all m_body RectangleShapes positions
};