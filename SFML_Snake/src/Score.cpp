#include "headers/Score.h"

Score::Score(unsigned int points) :
	m_textArea(sf::Vector2f(WIDTH, HEIGHT - GAME_AREA_HEIGHT)),
	m_text()
{
	m_textArea.setFillColor(sf::Color::White);
	m_textArea.setPosition(sf::Vector2f(0, GAME_AREA_HEIGHT));

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
	m_text.setPosition(sf::Vector2f(25, m_textArea.getPosition().y + 25));
}

void Score::setText(unsigned int points)
{
	m_text.setString(sf::String("Score : ") + sf::String(std::to_string(points)));
}

void Score::draw(sf::RenderWindow* p_window) const
{
	p_window->draw(m_textArea);
	p_window->draw(m_text);
}