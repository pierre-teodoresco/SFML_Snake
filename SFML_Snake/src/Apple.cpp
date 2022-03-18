#include "headers/Apple.h"

/*
* @brief constructor : fill the color of the shape and genearate the position
*/
Apple::Apple() : m_shape(BOX_SIZE / 2)
{
	m_shape.setFillColor(sf::Color::Red);
	this->generate();
}

/*
* @brief private methode : randomly generating the coordonates in x and y for the apple
* @return void
*/
void Apple::generate()
{
	// C++11 random library
	std::random_device dev;
	std::mt19937 rng(dev());

	/* 
	*  We need to make the window look like a grid 
	*  We have to go from 20 to 20 to create this grid 
	*  1. Randomly generates the hundreds digit for the width
	*  2. Same thing with the height
	*  3. And then generates the tens digit
	*/
	
	std::uniform_int_distribution<std::mt19937::result_type> width_divider(0, GAME_AREA_WIDTH / 100 - 2);		// the hundreds digit for the width
	std::uniform_int_distribution<std::mt19937::result_type> height_divider(0, GAME_AREA_HEIGHT / 100 - 2);		// [...] for the height
	std::uniform_int_distribution<std::mt19937::result_type> box_divider(0, 100 / BOX_SIZE);					// the tens digit

	/*
	* Assign the values to x and y coordinates 
	*/

	float x = float(box_divider(rng) * BOX_SIZE + width_divider(rng) * 100);		// float to avoid implicit conversion
	float y = float(box_divider(rng) * BOX_SIZE + height_divider(rng) * 100);		// same thing

	m_shape.setPosition(x, y);
}

/*
* @brief draw the shape of the apple on the window
* @param memory address of the window (pointer)
* @return void
*/
void Apple::draw(sf::RenderWindow* p_window) const
{
	p_window->draw(m_shape);
}

/*
* @brief getter on the apple's shape position
* @return void
*/
sf::Vector2f Apple::getPosition() const
{
	return m_shape.getPosition();
}