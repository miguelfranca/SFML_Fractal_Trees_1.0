#pragma once
#include "Global.h"


class Button : public sf::RectangleShape {
public:
	Button() {};
	Button(float size_xx, float size_yy, sf::Color colorr, float pos_x, float pos_y, std::string str, unsigned char_size) {
		setUp(size_xx, size_yy, colorr, pos_x, pos_y, str, char_size);
	};

	void setFunction(void(*ffunc)(sf::RenderWindow &window)) { func = ffunc; }

	void setUp(float size_xx, float size_yy, sf::Color colorr, float pos_x, float pos_y, std::string str, unsigned char_size);

	bool isClicked(sf::Vector2i pos);

	void executeFunction(sf::RenderWindow &window) { if (func != NULL) func(window); }

	void draw(sf::RenderWindow &window);

private:

	void(*func)(sf::RenderWindow &window) = NULL;

	sf::Font font;
	sf::Text text;

	sf::Color color;

	void setFont(std::string str) { font.loadFromFile(str); }

	static void setUpText(sf::Text &ttext, std::string str, sf::Color color, float pos_x, float pos_y, float size_x, unsigned char_size, sf::Font &ffont);
};