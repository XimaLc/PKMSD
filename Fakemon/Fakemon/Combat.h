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
	
	sf::Texture trainerBackTexture;
	sf::Sprite trainerBackSprite;

	sf::IntRect trainerBackRect;


	Client& client;
	sf::Packet sendPacket;
	sf::Packet receivePacket;
	bool matchmaking = false;

public:
	Combat(Client& _client);

	inline void loadTeam() { team.load(); }

	void update(sf::RenderWindow * _window);
	void draw(sf::RenderWindow * _window);
};

