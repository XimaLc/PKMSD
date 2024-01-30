#include "TeamBuilder.h"

TeamBuilder::TeamBuilder()
{
	listType = POKEMONS;

	editTeam = false;
	currentTeamIndex = 0;
	pkmStart = 1;
	moveStart = 1;
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

TeamBuilder::~TeamBuilder() {}

void TeamBuilder::loadPokemon()
{
	pokemons = DB::getSelectablePokemons(pkmStart, amount);

	PokemonTab tmp;
	pokemonTabs.clear();
	int x{ 0 };
	for (auto i : pokemons)
	{
		tmp = PokemonTab(i);
		tmp.setPosition({ 25.f, x * 100.f });
		pokemonTabs.push_back(tmp);
		x++;
	}
}

void TeamBuilder::loadMove(Pokemon pokemon)
{
	moves = DB::getMoves(pokemon.getMovePool(), moveStart, amount);

	MoveTab tmp;
	moveTabs.clear();
	int x{ 0 };
	for (auto i : moves)
	{
		tmp = MoveTab(i);
		tmp.setPosition({ 25.f, x * 100.f });
		moveTabs.push_back(tmp);
		x++;
	}
}

void TeamBuilder::update(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->boutons)
		it.second->update(mousePos);
	
	if (listType == POKEMONS)
	{
		for (auto& it : this->pokemonTabs)
		{
			it.update(mousePos);
			if (it.isPressed())
			{
				team.addPokemon(it.getPokemon(), currentTeamIndex);
			}
		}
	}
	else if (listType == MOVES)
	{
		for (auto& it : this->moveTabs)
		{
			it.update(mousePos);
			if (it.isPressed())
				team.addMove(it.getMove(), currentMoveIndex, currentTeamIndex);
		}
	}

	int x{ 0 };
	for (auto& it : this->slots)
	{
		if (it.isPressed())
		{
			listType = POKEMONS;
			currentTeamIndex = it.getTeamIndex();
			pb.changePokemon(&team.getPokemons()[x]);
		}

		pb.changePokemon(&team.getPokemons()[currentTeamIndex]);
		it.setPokemon(team.getPokemons()[x]);

		it.update(mousePos);
		x++;
	}

	pb.update(mousePos);
	if (pb.isMoveSlotPressed())
	{
		currentMoveIndex = pb.getPressedSlot();
		listType = MOVES;
		moveStart = 1;
		loadMove(team.getPokemons()[currentTeamIndex]);
	}

	if (boutons["droite"]->isPressed())
	{
		if (listType == POKEMONS)
		{
			pkmStart += amount;
			if (pkmStart > 151) 
				pkmStart = 1;
			
			loadPokemon();
		}
		else if (listType == MOVES)
		{
			moveStart += amount;
			if (moveStart >= 22)
				moveStart = 1;

			loadMove(team.getPokemons()[currentTeamIndex]);
		}
	}
	
	if (boutons["gauche"]->isPressed())
	{
		if (listType == POKEMONS)
		{
			pkmStart -= amount;
			if (pkmStart <= 0)
				pkmStart = 142;

			loadPokemon();
		}
		else if (listType == MOVES)
		{
			moveStart -= amount;
			if (moveStart < 1)
				moveStart = 21;

			loadMove(team.getPokemons()[currentTeamIndex]);
		}
	}
}

void TeamBuilder::draw(sf::RenderWindow* _window)
{
	_window->draw(shape);
	
	if(listType == POKEMONS)
		for (auto i : pokemonTabs)
			i.draw(_window);
	
	if(listType == MOVES)
		for (auto i : moveTabs)
			i.draw(_window);

	for (auto i : boutons)
		i.second->render(_window);
	
	for (auto i : slots)
		i.draw(_window);
	
	pb.draw(_window);
}