#pragma once
#include "Team.h"
#include "Client.h"
#include <SFML/Graphics.hpp>
class Combat
{
private:
	Team team;
	Team opponent;

	sf::Font font;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture actionBarTexture;
	sf::Sprite actionBarSprite;

	sf::Texture pokeBarTexture;
	sf::Sprite pokeBarSprite;
	sf::Sprite pokeBarSprite2;
	
	sf::Texture trainerBackTexture;
	sf::Sprite trainerBackSprite;

	sf::IntRect trainerBackRect;

	sf::Text pokemonName;
	sf::Text pokemonName2;

	sf::Text pokemonHp;
	sf::Text pokemonHp2;

	std::vector<int> actualHp;
public:
	Combat();

	void update(sf::RenderWindow * _window);
	void draw(sf::RenderWindow * _window);
};

