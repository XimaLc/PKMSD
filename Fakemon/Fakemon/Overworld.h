#pragma once
#include "StateManager.h"
#include "Player.h"
#include "PokemonSafari.h"

class Overworld
{
private:
	sf::Sprite fondSpr;
	sf::Texture fondTxt;
	sf::View viewOverworld;
	Player player;
	vector<PokemonSafari> wildPokemons;
public:
	Overworld();
	~Overworld();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

};

