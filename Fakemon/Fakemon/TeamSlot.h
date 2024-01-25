#pragma once
#include <SFML/Graphics.hpp>
#include "Pokemon.h"
#include "tools.h"

enum slotStates { slotIDLE = 0, slotHOVER, slotPRESSED };

class TeamSlot
{
private:
	Pokemon pokemon;
	sf::Sprite sprite;
	sf::Texture texture;
	int teamIndex;

	sf::RectangleShape shape;
	sf::Color color;
	float timer;
	int state;
public:
	TeamSlot();

	void setPokemon(Pokemon _p);
	inline Pokemon getPokemon() { return pokemon; }
	inline void setTeamIndex(int _i) { teamIndex = _i; }
	inline int getTeamIndex() { return teamIndex; }
	
	void setPos(sf::Vector2f _pos);
	void update(const sf::Vector2f mousePos);
	void draw(sf::RenderWindow * window);
};