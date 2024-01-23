#pragma once
#include "StateManager.h"
#include "Player.h"
#include "PokemonSafari.h"
#include "DB.h"


class Obstacle
{
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Sprite spr;

public:
	Obstacle();
	Obstacle(sf::Vector2f _pos, sf::Vector2f _size, sf::Texture _txt);
	~Obstacle();

	sf::Vector2f getPos() { return pos; }
	sf::Vector2f getSize() { return size; }
	sf::Sprite getSpr() { return spr; }
};

class Overworld
{
private:
	sf::Sprite fondSpr;
	sf::Texture fondTxt;
	sf::Texture obstacleTxt;
	sf::View viewOverworld;
	Player player;
	vector<PokemonSafari> wildPokemons;
	vector<Obstacle> obstacles;
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

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(sf::Vector2f _pos, sf::Vector2f _size, sf::Texture _txt) : pos(_pos), size(_size)
{
	spr.setPosition(pos);
	spr.setTexture(_txt);
}

Obstacle::~Obstacle()
{
}