#pragma once
#include "StateManager.h"
#include "PokemonSafari.h"


class Capture
{
private:
	PokemonSafari pokemonEnemy;
	Sprite fondSpr;
	Texture fondTxt;
	Sprite trainerSpr;
	Texture trainerTxt;
	IntRect trainerRect;
	Sprite pokeBarSpr;
	Texture pokeBarTxt;
	Sprite actionBarSpr;
	Texture actionBarTxt;
	float catchChance;
	float fleeChance;
public:
	Capture();
	Capture(PokemonSafari _poke);
	~Capture();

	void setPokemonEnemy(PokemonSafari _poke) { pokemonEnemy = _poke; }

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

};

