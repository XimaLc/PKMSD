#pragma once
#include "StateManager.h"
#include "Player.h"
#include "PokemonSafari.h"
#include "DB.h"

class Overworld
{
private:
	sf::Sprite fondSpr;
	sf::Texture fondTxt;
	sf::View viewOverworld;
	Player player;
	vector<PokemonSafari> wildPokemons;
	float spawnTimer;
public:
	Overworld();
	~Overworld();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

	sf::Vector2f seek(PokemonSafari* agent, sf::Vector2f _targetPos);
	sf::Vector2f flee(PokemonSafari* agent, sf::Vector2f _targetPos);
	sf::Vector2f pursuit(PokemonSafari* agent, sf::Vector2f _targetPos, sf::Vector2f _targetVel);
	sf::Vector2f evasion(PokemonSafari* agent, sf::Vector2f _targetPos, sf::Vector2f _targetVel);
	sf::Vector2f arrival(PokemonSafari* agent, sf::Vector2f _targetPos);
};

