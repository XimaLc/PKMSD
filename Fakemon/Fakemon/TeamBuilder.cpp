#include "TeamBuilder.h"

TeamBuilder::TeamBuilder()
{
	this->boutons["gauche"] = new Button("../Files/Textures/gauche.png", 500, 500, 177, 178);
	this->boutons["droite"] = new Button("../Files/Textures/droite.png", 750, 500, 177, 178);

	shape.setFillColor(sf::Color(211, 211, 211));
	shape.setSize({ 1920, 1080 });

	PokemonTab tmp;
	int x{0};
	pokemons = DB::getPokemons(1, 10);
	for (auto i : pokemons)
	{
		tmp = PokemonTab(i);
		tmp.setPosition({ 25.f, x*100.f });
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
	_window->draw(shape);
	for (auto i : tabs)
		i.draw(_window);

	for (auto i : boutons)
		i.second->render(_window);
}