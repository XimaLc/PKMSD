#pragma once
#include "Client.h"
#include "DB.h"

#include <SFML/Graphics.hpp>
enum Actions {ATTAQUER, POKEMON};

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

	sf::Texture* pokemonTexture;
	sf::Sprite pokemonSprite;

	sf::Texture* pokemonTexture2;
	sf::Sprite pokemonSprite2;

	sf::IntRect trainerBackRect;
	
	sf::Text pokemonName;
	sf::Text pokemonName2;

	sf::Text pokemonHp;
	sf::Text pokemonHp2;
	
	sf::Text attaquerText;
	sf::Text pokemonText;

	int actionChoice;

	std::vector<int> actualHp;

	bool isChoosingAction;
	bool isChoosingMove;

	std::vector<sf::Text> moves;
	int currentMove;

	float timer;

	Client& client;
	sf::Packet sendPacket;
	sf::Packet receivePacket;
public:
	Combat(Client& _client);

	void update(sf::RenderWindow * _window);
	void draw(sf::RenderWindow * _window);
};

