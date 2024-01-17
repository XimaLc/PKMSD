#include "PokemonTab.h"

PokemonTab::PokemonTab() {}

PokemonTab::PokemonTab(Pokemon _pokemon)
{
	texture.loadFromFile("../Files/Textures/Pokemons/Base/" + _pokemon.getPath() + ".png");
	sprite.setScale({ 0.1, 0.1 });
	pokemon = _pokemon;
}

void PokemonTab::setPosition(sf::Vector2f _pos)
{
	sprite.setPosition(_pos);
}

void PokemonTab::draw(sf::RenderWindow* _window)
{
	sprite.setTexture(texture);
	_window->draw(sprite);
}
