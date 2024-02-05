#include "Combat.h"

Combat::Combat(Client& _client) : client(_client)
{
	font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	backgroundTexture.loadFromFile("../Files/Textures/BattleBackgrounds.png");
	backgroundSprite.setScale({ 8.f, 8.f });

	actionBarTexture.loadFromFile("../Files/Textures/ActionBar.png");
	actionBarSprite.setPosition({ 0.f, 896.f });

	pokeBarTexture.loadFromFile("../Files/Textures/pokeBar.png");
	pokeBarSprite.setPosition({ 210.f, 95.f });
	pokeBarSprite.setScale({ 6.f, 6.f });

	trainerBackTexture.loadFromFile("../Files/Textures/TrainerBack.png");
	trainerBackRect = { 0, 0, 64, 64 };
	trainerBackSprite.setScale({ 8.f, 8.f });
	trainerBackSprite.setPosition({ 200.f, 384.f });
	trainerBackSprite.setTextureRect(trainerBackRect);
}

void Combat::update(sf::RenderWindow* _window)
{
	if(!matchmaking)
	{
		bool suu;
		sendPacket << client.MATCHMAKING;

		if (client.socket.send(sendPacket) == sf::Socket::Done)
			std::cerr << "send connection\n";
		else
			std::cerr << "Failed to send connection\n";

		if (client.socket.receive(receivePacket) == sf::Socket::Done)
			receivePacket >> suu;

		if (!suu)
			std::cerr << "pas assez de joueur";
		else
			std::cerr << "letsgoooo";

	}
}

void Combat::draw(sf::RenderWindow* _window)
{
	backgroundSprite.setTexture(backgroundTexture);
	_window->draw(backgroundSprite);

	pokeBarSprite.setTexture(pokeBarTexture);
	_window->draw(pokeBarSprite);

	actionBarSprite.setTexture(actionBarTexture);
	_window->draw(actionBarSprite);
}