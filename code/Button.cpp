#include "Global.h"


void Button::setUp(float size_xx, float size_yy, sf::Color colorr, float pos_x, float pos_y, std::string str, unsigned char_size) {
	//setOutlineColor(colorr);
	//setOutlineThickness(5);
	//setFillColor(colorr);
	setSize(sf::Vector2f(size_xx, size_yy));
	setPosition(pos_x, pos_y);
	setFont("font.ttf");
	setUpText(text, str, colorr, pos_x, pos_y, size_xx, char_size, font);
};

void Button::draw(sf::RenderWindow &window) {
	window.draw(*this);	
	window.draw(this->text);
}

bool Button::isClicked(sf::Vector2i pos) {

	if ((abs(pos.x - getPosition().x) <= getSize().x) && (abs(pos.y - getPosition().y) <= getSize().y)) {
		return true;
	}
	return false;
}

void Button::setUpText(sf::Text &ttext, std::string str, sf::Color colorr, float xx, float yy, float size_xx, unsigned char_size, sf::Font &ffont) {
	ttext.setFont(ffont);
	ttext.setString(str);
	ttext.setCharacterSize(char_size);
	ttext.setOrigin(ttext.getGlobalBounds().width / 2, ttext.getGlobalBounds().height);
	ttext.setFillColor(colorr);
	ttext.setPosition(xx + size_xx / 2, yy - ttext.getGlobalBounds().height);
}
