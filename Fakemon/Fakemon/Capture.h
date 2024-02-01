#pragma once
#include "StateManager.h"
#include "PokemonSafari.h"
#include "Button.h"


class Capture
{
private:
	PokemonSafari pokemonEnemy; 
	sf::Font font;
	sf::Text pkmName;
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
	vector<Button*> buttons;
public:
	Capture();
	Capture(PokemonSafari _poke);
	~Capture();

	void setPokemonEnemy(PokemonSafari _poke) { pokemonEnemy = _poke; }

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

};

