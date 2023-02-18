#include "headers/Application.h"

/*
* @brief constructor : initializes the window and all other objects, set FPS and vSync, change the apple position if it's on the snake
*/
Application::Application() : 
	m_window(sf::VideoMode(WIDTH, HEIGHT), sf::String("Snake"), sf::Style::Close),
	m_event(),
	m_snake(),
	m_apple(),
	m_score()
{
	m_window.setFramerateLimit(60);
	m_window.setVerticalSyncEnabled(true);
	this->appleHandler();
}

/*
* @brief game loop : moving the snake, checks if he's eating an apple, change the position of the new apple if the snake has eaten it, change the score 
* @return void
*/
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

/*
* @brief draw all SFML drawable objects
* @return void
*/
void Application::render()
{
	m_window.clear(sf::Color::Black);
	m_score.draw(&m_window);
	m_snake.draw(&m_window);
	m_apple.draw(&m_window);
	m_window.display();
}

/*
* @brief clear the window and reset the apple's and snake's postition
* @return void
*/
void Application::reset()
{
	m_window.clear();
	m_snake = Snake();
	m_apple = Apple();
}

/*
* @brief const method checking if the apple while appears on the snake
* @return true if the apple while, false if it while not
*/
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

/*
* @brief re-generate the apple position while it's on the snake
* @return void
*/
void Application::appleHandler()
{
	while (this->isAppleOnSnake()) 
		m_apple = Apple();
}

/*
* @brief start the game by creating the window loop and calling reset, update and render methods
* @return void
*/
void Application::start()
{
	sf::Clock clock;
	const float updateInterval = 1.0f / 60.0f;
	float accumulatedTime = 0.0f;

	bool shouldUpdateSnake = true; // flag to determine whether to update snake position

	while (m_window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		accumulatedTime += deltaTime;

		while (accumulatedTime >= updateInterval)
		{
			if (shouldUpdateSnake)
			{
				if (m_snake.isDead()) 
					this->reset();
				this->update(); // update snake position
			}

			shouldUpdateSnake = !shouldUpdateSnake; // flip the update flag every other frame
			accumulatedTime -= updateInterval;
		}

		this->render(); // render the game
	}
}