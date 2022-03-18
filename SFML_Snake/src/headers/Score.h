#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Utils.h"

class Score
{
private:
	sf::RectangleShape m_textArea;
	sf::Text m_text;
	sf::Font m_font;
public:
	Score(const unsigned int points = 0);
	Score(const Score&) = delete;
public:
	void setText(const unsigned int points);
	void draw(sf::RenderWindow* p_window) const;
};