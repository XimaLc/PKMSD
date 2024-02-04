#include "Combat.h"

Combat::Combat()
{
	team.load();

	font.loadFromFile("../Files/Font/Pokemon.ttf");

	backgroundTexture.loadFromFile("../Files/Textures/BattleBackgrounds.png");
	backgroundSprite.setScale({ 8.f, 8.f });

	actionBarTexture.loadFromFile("../Files/Textures/ActionBar.png");
	actionBarSprite.setPosition({ 0.f, 896.f });

	pokeBarTexture.loadFromFile("../Files/Textures/pokeBar.png");

	pokeBarSprite.setPosition({ 210.f, 95.f });
	pokeBarSprite.setScale({ 6.f, 6.f });

	pokeBarSprite2.setPosition({ 1300.f, 700.f });
	pokeBarSprite2.setScale({ 6.f, 6.f });

	trainerBackTexture.loadFromFile("../Files/Textures/TrainerBack.png");
	trainerBackRect = { 0, 0, 64, 64 };
	trainerBackSprite.setScale({ 8.f, 8.f });
	trainerBackSprite.setPosition({ 200.f, 384.f });
	trainerBackSprite.setTextureRect(trainerBackRect);

	pokemonName.setFillColor(sf::Color::Black);

	pokemonName2.setFillColor(sf::Color::Black);
	pokemonName2.setPosition(1320.f, 725.f);

	pokemonHp.setFillColor(sf::Color::Black);

	pokemonHp2.setFillColor(sf::Color::Black);
	pokemonHp2.setPosition(1450.f, 770.f);

	for (auto i : team.getPokemons())
		actualHp.push_back(i.getStat("hp"));

	pokemonName2.setString(team.getPokemons()[0].getName());
	pokemonHp2.setString(std::to_string(actualHp[0]) + " / " + std::to_string(team.getPokemons()[0].getStat("hp")));
}

void Combat::update(sf::RenderWindow* _window)
{
}

void Combat::draw(sf::RenderWindow* _window)
{
	backgroundSprite.setTexture(backgroundTexture);
	_window->draw(backgroundSprite);

	pokeBarSprite.setTexture(pokeBarTexture);
	_window->draw(pokeBarSprite);

	pokeBarSprite2.setTexture(pokeBarTexture);
	_window->draw(pokeBarSprite2);

	actionBarSprite.setTexture(actionBarTexture);
	_window->draw(actionBarSprite);

	pokemonName2.setFont(font);
	_window->draw(pokemonName2);

	pokemonHp2.setFont(font);
	_window->draw(pokemonHp2);
}