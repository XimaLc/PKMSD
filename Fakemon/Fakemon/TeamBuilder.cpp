#include "TeamBuilder.h"

TeamBuilder::TeamBuilder()
{
	editTeam = false;
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

	loadPokemon();

	x = 0;
	for (auto i : team.getPokemons())
	{
		tmpTS = TeamSlot();
		tmpTS.setTeamIndex(x);
		tmpTS.setPos({ 1030 + (x * 145.f), 10.f });
		slots.push_back(tmpTS);
		x++;
	}
}

TeamBuilder::~TeamBuilder()
{
}

void TeamBuilder::loadPokemon()
{
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
		}
	}

	int x{ 0 };
	for (auto& it : this->slots)
	{
		if (it.isPressed())
		{
			currentTeamIndex = it.getTeamIndex();
			pb.changePokemon(&team.getPokemons()[x]);
		}

		it.setPokemon(team.getPokemons()[x]);
		pb.changePokemon(&team.getPokemons()[x]);

			
		it.update(mousePos);
		x++;
	}

	if (boutons["droite"]->isPressed())
	{
		start += amount;
		if (start > 151) 
			start = 1;
		
		loadPokemon();
	}
	
	if (boutons["gauche"]->isPressed())
	{
		start -= amount;
		if (start <= 0)
			start = 142;

		loadPokemon();
	}
}

void TeamBuilder::draw(sf::RenderWindow* _window)
{
	_window->draw(shape);

	for (auto i : tabs)
		i.draw(_window);

	for (auto i : boutons)
		i.second->render(_window);

	//for (auto i : slots) veut plus s'afficher : Violation d'acces
	//	i.draw(_window);

	pb.draw(_window);
}