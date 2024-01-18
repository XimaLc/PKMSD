#include "PokemonSafari.h"

PokemonSafari::PokemonSafari()
{
	
}

PokemonSafari::PokemonSafari(Pokemon _pokemon)
{
	id = _pokemon.getId();
	path = _pokemon.getPath();
	name = _pokemon.getName();
	type1 = _pokemon.getType1();
	type2 = _pokemon.getType2();
	evolution_state = _pokemon.getEvolutionState();
	stats = _pokemon.getStats();
	movePool = _pokemon.getMovePool();

	pos = { fRand(40.f, 1880.f), fRand(40.f, 1020.f) };
	velocity = { 0.f, 0.f };
	masse = 0.1f;
	max_force = 50.f;
	vit_max = 200.f;
	txt.loadFromFile(TexturePath"Pokemons/Base/" + path + ".png");
	spr.setTexture(txt);
	spr.setOrigin(spr.getGlobalBounds().width / 2, spr.getGlobalBounds().height / 2);
	spr.setScale(0.1f, 0.1f);
}

PokemonSafari::~PokemonSafari()
{
}

void PokemonSafari::update(sf::Vector2f _steering)
{
	acceleration = _steering / masse;
	velocity = Truncate(velocity + acceleration * GetDeltaTime(), vit_max);
}

void PokemonSafari::draw(sf::RenderWindow* _window)
{
	spr.setTexture(txt);
	spr.setPosition(pos);
	_window->draw(spr);
}