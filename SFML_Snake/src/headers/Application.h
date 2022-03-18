#pragma once

#include <SFML/Graphics.hpp>

#include "Utils.h"
#include "Snake.h"
#include "Apple.h"
#include "Score.h"

class Application
{
private:
	sf::RenderWindow m_window;
	sf::Event m_event;
	Snake m_snake;
	Apple m_apple;
	Score m_score;
public:
	/* Constructors */
	Application();
	Application(const Application&) = delete;
private:
	void update();					// computes all the game's stuff in the game loop
	void render();					// renders object on the screen
	void reset();					// reset the game when the player loses
	bool isAppleOnSnake() const;	// check if the apple's position is on the snake
	void appleHandler();			// change the apple's position while it's on the snake 
public:
	void start();					// start the game by creating the main window loop, updating, rendering and reseting if it's necessary
};