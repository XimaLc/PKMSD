#include "TeamBuilder.h"

TeamBuilder::TeamBuilder()
{
	currentTeamIndex = 0;
	start = 1;
	amount = 10;
	this->boutons["gauche"] = new Button("../Files/Textures/gauche.png", 10, 1025, 44.5, 44.5);
	this->boutons["droite"] = new Button("../Files/Textures/droite.png", 700, 1025, 44.5, 44.5);

	shape.setFillColor(sf::Color(211, 211, 211));
	shape.setSize({ 1920, 1080 });

	PokemonTab tmpPT;
	TeamSlot tmpTS;
	int x{0};
	pokemons = DB::getSelectablePokemons(start, amount);
	start += amount;

	for (auto i : pokemons)
	{
		tmpPT = PokemonTab(i);
		tmpPT.setPosition({ 25.f, x*100.f });
		tabs.push_back(tmpPT);
		x++;
	}

	x = 0;
	for (auto i : team.getPokemons())
	{
		tmpTS = TeamSlot();
		tmpTS.setPos({ 25.f, 1025 + (x * 100.f) });
		x++;
	}
}

TeamBuilder::~TeamBuilder()
{
}


void TeamBuilder::update(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->boutons)
		it.second->update(mousePos);



	for (auto& it : this->tabs)
	{
		it.update(mousePos);
		if (it.isPressed())
		{
			team.addPokemon(it.getPokemon(), currentTeamIndex);
			if (currentTeamIndex < 5)
				currentTeamIndex++;
			else
				currentTeamIndex = 0;
		}
	}

	if (boutons["droite"]->isPressed())
	{
		pokemons = DB::getSelectablePokemons(start, amount);
		start += amount;
		if (start > 151)
			start = 1;
		PokemonTab tmp;
		tabs.clear();
		int x{ 0 };
		for (auto i : pokemons)
		{
			tmp = PokemonTab(i);
			tmp.setPosition({ 25.f, x * 100.f });
			tabs.push_back(tmp);
			x++;
		}
	}
	
	if (boutons["gauche"]->isPressed())
	{
		start -= amount;
		if (start <= 1)
			start = 142;
		pokemons = DB::getSelectablePokemons(start, amount);

		PokemonTab tmp;
		tabs.clear();
		int x{ 0 };
		for (auto i : pokemons)
		{
			tmp = PokemonTab(i);
			tmp.setPosition({ 25.f, x * 100.f });
			tabs.push_back(tmp);
			x++;
		}
	}
}

void TeamBuilder::draw(sf::RenderWindow* _window)
{
	_window->draw(shape);
	for (auto i : tabs)
		i.draw(_window);

	for (auto i : boutons)
		i.second->render(_window);
}