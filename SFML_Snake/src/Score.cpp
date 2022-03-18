#include "headers/Score.h"

/*
* @brief constructor : creates the textfield and setup the text with his font, his size, etc...
*/
Score::Score(unsigned int points) :
	m_textField(sf::Vector2f(WIDTH, HEIGHT - GAME_AREA_HEIGHT)),
	m_text()
{
	m_textField.setFillColor(sf::Color::White);
	m_textField.setPosition(sf::Vector2f(0, GAME_AREA_HEIGHT));

	if (!m_font.loadFromFile("assets\\fonts\\arial.ttf"))
	{
		std::cerr << "ERROR : cannot open the font file" << std::endl;
		return;
	}
	m_text.setFont(m_font);
	m_text.setString(sf::String("Score : ") + sf::String(std::to_string(points)));
	m_text.setFillColor(sf::Color::Green);
	m_text.setCharacterSize(32);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(sf::Vector2f(25, m_textField.getPosition().y + 25));
}

/*
* @brief draw the textfield and the text
* @param memory address of the window
* @return void
*/
void Score::draw(sf::RenderWindow* p_window) const
{
	p_window->draw(m_textField);
	p_window->draw(m_text);
}

/*
* @brief setter on the text which only changes the points
* @return void
*/
void Score::setText(unsigned int points)
{
	m_text.setString(sf::String("Score : ") + sf::String(std::to_string(points)));
}