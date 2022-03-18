#include "headers/Application.h"

Application::Application() : 
	m_window(sf::VideoMode(WIDTH, HEIGHT), sf::String("Snake"), sf::Style::Close),
	m_event(),
	m_snake(),
	m_apple(),
	m_score()
{
	m_window.setFramerateLimit(12);
	m_window.setVerticalSyncEnabled(true);
	this->appleHandler();
}

void Application::update()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
	m_snake.move();
	m_snake.eat(m_apple);
	this->appleHandler();
	m_score.setText(m_snake.getPoints());
}

void Application::render()
{
	m_window.clear(sf::Color::Black);
	m_score.draw(&m_window);
	m_snake.draw(&m_window);
	m_apple.draw(&m_window);
	m_window.display();
}

void Application::reset()
{
	m_window.clear();
	m_snake = Snake();
	m_apple = Apple();
}

bool Application::isAppleOnSnake() const
{
	for (sf::Vector2f pos : m_snake.getPositions())
	{
		if (pos == m_apple.getPosition())
		{
			return true;
		}
	}
	return false;
}

void Application::appleHandler()
{
	while (isAppleOnSnake()) m_apple = Apple();
}

void Application::start()
{
	while (m_window.isOpen())
	{
		if (m_snake.isDead()) this->reset();
		this->update();
		this->render();
	}
}