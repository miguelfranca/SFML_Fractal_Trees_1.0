#include <SFML/Graphics.hpp>
#include "Global.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

#define FOR1(ID,N) for(int ID=0; ID<N; ID++)

//initial x and y values
//const float initX = screenWidth / 2;
//const float initY = -200; //offset
const float initX = screenWidth / 2;
const float initY = screenHeight; //offset //250

//length of 1st branch
const float length = 500.f;//600

//smallest possible branch length
const float minLength = 8.f;//1

sf::Font font;
sf::Text text;

void drawTree(float initX, float initY, float degree, float length, sf::RenderWindow &window);
static int random(int begin, int end);
void saveWindow(sf::RenderWindow &window, std::string str);

int main() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Fractal Tree (Custom)");

	font.loadFromFile("font.ttf");
	text.setFont(font);

	srand(time(NULL));

	window.setPosition(sf::Vector2i(0, 0));

	drawTree(initX, initY, -90, length, window);

	window.display();

	//saveWindow(window,"try2.jpg");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			else {
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
					window.clear();
					drawTree(initX, initY, -90, length, window);
					window.display();
				}
			}
		}
	}

	return 0;

}

static int random(int begin, int end) {
	int num = rand() % (end - begin);
	return num + begin;
};


void drawTree(float initX, float initY, float degree, float length, sf::RenderWindow &window)
{
	if (length < minLength)
		return;

	float finalX = initX + length * cos(degree * PI / 180.f);
	float finalY = initY + length * sin(degree * PI / 180.f);

	//creates a line from initial point to final point
	sf::Color col = length < 30 ? sf::Color(0, 255, 0, 100) : sf::Color(153, 77, 0); //165,42,42
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(initX, initY), col),
		sf::Vertex(sf::Vector2f(finalX, finalY), col)
	};
	window.draw(line, 2, sf::Lines);

	//int angle1 = random(20, 45);
	int angle1 = 30;//30
	int bias = 0;//15

	//choose double or triple recursion
	int a = random(1, 5);
	//int a = 3;//2

	float newLength = (float)(random(60, 80)) / 100.f * length;
	//float newLength = (float)50 / 100.f * length;

	FOR1(i, a)
		drawTree(finalX, finalY, degree + (a == 1 ? 0 : (i / ((a - 1.) / 2.) - 1.))*angle1 + bias, newLength, window);
		//drawTree(finalX, finalY, degree + (a == 1 ? 0 : (i / ((a - 1.) / 2.) - 1.))*angle1, newLength, window);

}

void saveWindow(sf::RenderWindow &window, std::string str) {

	window.display();

	sf::Texture texture;
	texture.create(window.getSize().x, window.getSize().y);
	texture.update(window);
	texture.copyToImage().saveToFile(str);

	window.display();
}
