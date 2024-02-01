#include "Capture.h"

Capture::Capture()
{
	
}

Capture::Capture(PokemonSafari _poke)
{
	pokemonEnemy = _poke;
	catchChance = 50.f;
	fleeChance = 20.f;
	fondTxt.loadFromFile(TexturePath"BattleBackgrounds.png");
	fondSpr.setTexture(fondTxt);
	fondSpr.setScale({ 8.f, 8.f });
	trainerTxt.loadFromFile(TexturePath"TrainerBack.png");
	trainerRect = { 0, 0, 64, 64 };
	trainerSpr.setTexture(trainerTxt);
	trainerSpr.setScale({ 8.f, 8.f });
	trainerSpr.setPosition({ 200.f, 384.f });
	trainerSpr.setTextureRect(trainerRect);
	pokeBarTxt.loadFromFile(TexturePath"pokeBar.png");
	pokeBarSpr.setTexture(pokeBarTxt);
	pokeBarSpr.setPosition({ 210.f, 95.f });
	pokeBarSpr.setScale({ 6.f, 6.f });
	actionBarTxt.loadFromFile(TexturePath"ActionBar.png");
	actionBarSpr.setTexture(actionBarTxt);
	actionBarSpr.setPosition({ 0.f, 896.f });

	pokemonEnemy.setPos({ 1380.f, 380.f });
	pokemonEnemy.getSpr()->setScale({ 0.5f, 0.5f });

	font.loadFromFile(FontsPath"Pokemon.ttf");

	pkmName.setPosition(280.f, 150.f);
	pkmName.setCharacterSize(50);
	pkmName.setFillColor(sf::Color::Black);
	pkmName.setString(pokemonEnemy.getName());

	buttons.reserve(4);
	buttons[0] = new Button("../Files/Textures/button.png", 250, 280, 400, 80, "Ball", 30);
	buttons[1] = new Button("../Files/Textures/button.png", 250, 280, 400, 80, "Rock", 30);
	buttons[2] = new Button("../Files/Textures/button.png", 250, 280, 400, 80, "Mud", 30);
	buttons[3] = new Button("../Files/Textures/button.png", 250, 280, 400, 80, "Run", 30);
}

Capture::~Capture()
{

}

void Capture::update(sf::RenderWindow* _window)
{
	
}

void Capture::draw(sf::RenderWindow* _window)
{
	fondSpr.setTexture(fondTxt);
	_window->draw(fondSpr);
	trainerSpr.setTextureRect(trainerRect);
	trainerSpr.setTexture(trainerTxt);
	_window->draw(trainerSpr);
	pokeBarSpr.setTexture(pokeBarTxt);
	_window->draw(pokeBarSpr);
	actionBarSpr.setTexture(actionBarTxt);
	_window->draw(actionBarSpr);
	pokemonEnemy.draw(_window);
	pkmName.setFont(font);
	_window->draw(pkmName);
}