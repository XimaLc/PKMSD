#include "Pokemon.h"

std::vector<Pokemon> Pokemon::pokemons;

void Pokemon::setTypes(int _typeId1, int _typeId2)
{
	typeId1 = _typeId1;
	typeId2 = _typeId2;
}

Pokemon::Pokemon() {}

Pokemon::Pokemon(int id, std::string _name, int _type1, int _type2, int _evolution_state, std::map<std::string, int> _stats)
{
	name = _name;
	typeId1 = _type1;
	typeId2 = _type2;
	evolution_state = _evolution_state;
	stats = _stats;
}
