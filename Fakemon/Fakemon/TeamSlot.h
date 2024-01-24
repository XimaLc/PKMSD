#pragma once
#include <SFML/Graphics.hpp>
#include "Pokemon.h"

class TeamSlot
{
private:
	Pokemon pokemon;
	int teamIndex;

	sf::RectangleShape shape;

public:
	TeamSlot();

	inline void setPokemon(Pokemon _p) { pokemon = _p; }
	inline Pokemon getPokemon() { return pokemon; }
	inline void setTeamIndex(int _i) { teamIndex = _i; }
	inline int getTeamIndex() { return teamIndex; }
	
	void setPos(sf::Vector2f _pos);
	
	
	
	void draw(sf::RenderWindow * window);
};