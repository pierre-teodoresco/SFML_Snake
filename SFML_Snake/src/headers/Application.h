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
	Application();
	Application(const Application&) = delete;
private:
	void update();
	void render();
	void reset();
	bool isAppleOnSnake() const;
	void appleHandler();
public:
	void start();
};