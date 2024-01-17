#include "PokemonTab.h"

PokemonTab::PokemonTab() {}

PokemonTab::PokemonTab(Pokemon _pokemon)
{
	shape.setSize({ 1000, 90 });
	shape.setFillColor(sf::Color::Red);
	pokemonTexture.loadFromFile("../Files/Textures/Pokemons/Base/" + _pokemon.getPath() + ".png");
	typeTexture.loadFromFile("../Files/Textures/Types.png");

	font.loadFromFile("../Files/Font/Pokemon.ttf");
	
	pokemonSprite.setScale({ 0.1, 0.1 });

	type1Sprite.setTextureRect({ 0, 44 * (_pokemon.getType1() - 1), 200,44});
	type1Sprite.setScale(0.6, 0.6);
	type2Sprite.setTextureRect({ 0, 44 * (_pokemon.getType2() - 1), 200,44});
	type2Sprite.setScale(0.6, 0.6);


	text.setString(_pokemon.getName());
	text.setFillColor(sf::Color::Black);

	pokemon = _pokemon;
}

const bool PokemonTab::isPressed() const
{
	return false;
}

void PokemonTab::setPosition(sf::Vector2f _pos)
{
	pokemonSprite.setPosition(_pos);
	shape.setPosition(_pos.x - 5, _pos.y + 5);
	text.setPosition(_pos.x + 100, _pos.y + 25);
	type1Sprite.setPosition(_pos.x + 300, _pos.y + 20);
	type2Sprite.setPosition(_pos.x + 300, _pos.y + 55);
}

void PokemonTab::update(const sf::Vector2f mousePos)
{

}

void PokemonTab::draw(sf::RenderWindow* _window)
{
	pokemonSprite.setTexture(pokemonTexture);
	type1Sprite.setTexture(typeTexture);
	type2Sprite.setTexture(typeTexture);
	text.setFont(font);
	_window->draw(shape);
	_window->draw(pokemonSprite);
	_window->draw(text);
	_window->draw(type1Sprite);
	_window->draw(type2Sprite);
}
