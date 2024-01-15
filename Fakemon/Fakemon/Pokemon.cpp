#include "Pokemon.h"

std::vector<Pokemon> Pokemon::pokemons;

void Pokemon::setPath(std::string _path)
{
	path = _path;
	setTexture();
}

void Pokemon::setTexture()
{
	
	std::string shinyStr;
	if (isShiny)
		shinyStr = "Shiny/";
	else
		shinyStr = "Base/";

	texture.loadFromFile("../Files/Textures/Pokemons/" + shinyStr + path + ".png");
}

void Pokemon::setTypes(int _typeId1, int _typeId2)
{
	typeId1 = _typeId1;
	typeId2 = _typeId2;
}

void Pokemon::displayById(int id, bool _isShiny, sf::RenderWindow& window)
{
	pokemons[id - 1].changeIsShiny(_isShiny);
	pokemons[id-1].display(window);
}

void Pokemon::display(sf::RenderWindow& window)
{
	sprite.setTexture(texture);
	window.draw(sprite);
}

void Pokemon::changeIsShiny(bool _isShiny)
{
	isShiny = _isShiny;
	setTexture();
}

Pokemon::Pokemon() 
{
	isShiny = false;
}

Pokemon::Pokemon(int id, std::string _name, int _type1, int _type2, int _evolution_state, std::map<std::string, int> _stats)
{
	name = _name;
	typeId1 = _type1;
	typeId2 = _type2;
	evolution_state = _evolution_state;
	stats = _stats;
}
