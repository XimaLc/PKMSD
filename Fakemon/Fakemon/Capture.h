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
	std::map<std::string, Button*> buttons;
	bool catched;
	bool fleed;
	bool finished;
	bool click;
	sf::Text actionText;
public:
	Capture();
	Capture(PokemonSafari _poke);
	~Capture();

	PokemonSafari getPokemonEnemy() { return pokemonEnemy; }
	void setPokemonEnemy(PokemonSafari _poke) { pokemonEnemy = _poke; }
	bool getCatched() { return catched; }
	bool getFleed() { return fleed; }
	bool getFinished() { return finished; }

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

};

