#include "TeamBuilder.h"

TeamBuilder::TeamBuilder()
{
	PokemonTab tmp;
	int x{0};
	pokemons = DB::getPokemons(1, 10);
	for (auto i : pokemons)
	{
		tmp = PokemonTab(i);
		tmp.setPosition({ 100.f, x*100.f });
		tabs.push_back(tmp);
		x++;
	}
}

TeamBuilder::~TeamBuilder()
{
}


void TeamBuilder::update(sf::RenderWindow* _window)
{

}

void TeamBuilder::draw(sf::RenderWindow* _window)
{
	for (auto i : tabs)
		i.draw(_window);
}