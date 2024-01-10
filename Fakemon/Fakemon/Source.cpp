#include "SFML/Graphics.hpp"
#include "DB.h"

int main()
{
	DB db;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "FAKEMON DE ZINZIN");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		Pokemon::getPokemons();
	}
}