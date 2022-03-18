#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Utils.h"

class Score
{
private:
	sf::RectangleShape m_textField;
	sf::Text m_text;
	sf::Font m_font;
public:
	/* constructor */
	Score(const unsigned int points = 0);
	Score(const Score&) = delete;
public:
	void draw(sf::RenderWindow* p_window) const;	// draw m_textField and m_text

	/* setter */
	void setText(const unsigned int points);		// setter on m_text string
};