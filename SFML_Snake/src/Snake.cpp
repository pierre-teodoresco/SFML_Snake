#include "headers/Snake.h"

/*
* @brief constructor : creates 3 boxes for the snake
*/
Snake::Snake() : m_direction(STOP), m_point(0)
{
	m_body.reserve(3);
	for (unsigned int i = 0; i <= 3; ++i)
	{
		sf::RectangleShape rect(sf::Vector2f(BOX_SIZE, BOX_SIZE));	// each parts of the snake has the size of a box
		rect.setPosition(float(GAME_AREA_WIDTH / 2 + i * BOX_SIZE), float(GAME_AREA_HEIGHT / 2));
		if (i == 0)
		{
			rect.setFillColor(sf::Color::Green);
		}
		else
		{
			rect.setFillColor(sf::Color(150, 255, 20));
		}
		m_body.emplace_back(rect);
	}
}

/*
* @brief change the value of the direction using player inputs
* @return void
*/
void Snake::setDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_direction != DOWN)
	{
		m_direction = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_direction != UP)
	{
		m_direction = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_direction != RIGHT)
	{
		m_direction = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (m_direction != LEFT && m_direction != STOP))
	{
		m_direction = RIGHT;
	}
}

/*
* @brief draw all the body of the snake
* @param memory address of the window
* @return void
*/
void Snake::draw(sf::RenderWindow* p_window) const
{
	for (sf::RectangleShape rect : m_body)
	{
		p_window->draw(rect);
	}
}

/*
* @brief uses the direction and move the snake changing the values of his positions
* @return void
*/
void Snake::move()
{
	this->setDirection();
	switch (m_direction)
	{
	case UP:
	{
		sf::Vector2f pos = m_body[0].getPosition();
		m_body[0].setPosition(m_body[0].getPosition().x, m_body[0].getPosition().y - BOX_SIZE);
		for (unsigned int i = 1; i < m_body.size(); ++i)
		{
			sf::Vector2f posi = m_body[i].getPosition();
			m_body[i].setPosition(pos);
			pos = posi;
		}
		break;
	}
	case DOWN:
	{
		sf::Vector2f pos = m_body[0].getPosition();
		m_body[0].setPosition(m_body[0].getPosition().x, m_body[0].getPosition().y + BOX_SIZE);
		for (unsigned int i = 1; i < m_body.size(); ++i)
		{
			sf::Vector2f posi = m_body[i].getPosition();
			m_body[i].setPosition(pos);
			pos = posi;
		}
		break;
	}
	case LEFT:
	{
		sf::Vector2f pos = m_body[0].getPosition();
		m_body[0].setPosition(m_body[0].getPosition().x - BOX_SIZE, m_body[0].getPosition().y);
		for (unsigned int i = 1; i < m_body.size(); ++i)
		{
			sf::Vector2f posi = m_body[i].getPosition();
			m_body[i].setPosition(pos);
			pos = posi;
		}
		break;
	}
	case RIGHT:
	{
		sf::Vector2f pos = m_body[0].getPosition();
		m_body[0].setPosition(m_body[0].getPosition().x + BOX_SIZE, m_body[0].getPosition().y);
		for (unsigned int i = 1; i < m_body.size(); ++i)
		{
			sf::Vector2f posi = m_body[i].getPosition();
			m_body[i].setPosition(pos);
			pos = posi;
		}
		break;
	}
	default:
	{
		break;
	}
	}
}

/*
*	@brief const method checking if the snake should be consider dead
*	@return true if the snake is dead, neither false
*/
bool Snake::isDead() const
{
	for (unsigned int i = 1; i < m_body.size(); ++i)
	{
		if (m_body[0].getPosition() == m_body[i].getPosition())
		{
			return true;
		}
	}

	if (m_body[0].getPosition().x < 0 || m_body[0].getPosition().x >= GAME_AREA_WIDTH)
	{
		return true;
	}

	if (m_body[0].getPosition().y < 0 || m_body[0].getPosition().y >= GAME_AREA_HEIGHT)
	{
		return true;
	}

	return false;
}

/*
* @brief if the head of the snake touch an apple, the snake eat the apple and c
* @param the apple which is currently displaying on the screen
* @return void
*/
void Snake::eat(Apple& apple)
{
	if (apple.getPosition() != m_body[0].getPosition()) return;

	sf::RectangleShape rect(sf::Vector2f(BOX_SIZE, BOX_SIZE));
	rect.setPosition(m_body[m_body.size() - 1].getPosition());
	rect.setFillColor(sf::Color(150, 255, 20));
	m_body.emplace_back(rect);

	++m_point;

	apple = Apple();
}

/*
* @brief const getter on points
* @return number of point of the player
*/
unsigned int Snake::getPoints() const
{
	return m_point;
}

/*
* @brief const getter on positions of the snake body
* @return a std::vector<sf::Vector2f> fill of positions of all the snake boxes
*/
std::vector<sf::Vector2f> Snake::getPositions() const
{
	std::vector<sf::Vector2f> positions;
	positions.reserve(m_body.size());

	for (sf::RectangleShape rect : m_body)
	{
		positions.emplace_back(rect.getPosition());
	}

	return positions;
}