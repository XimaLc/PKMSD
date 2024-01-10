#pragma once
#include "Type.h"
#include <string>
#include <vector>
#include <map>
class Pokemon
{
private:
	int id;
	std::string name;
	int typeId1;
	int typeId2;
	int evolution_state;
	std::map<std::string, int> stats;

	static std::vector<Pokemon> pokemons;
public:
	inline static std::vector<Pokemon> getPokemons() { return pokemons; }
	inline static void addPokemon(Pokemon _pokemon) { pokemons.push_back(_pokemon); }

	inline void setId(int _id) { id = _id; }
	inline void setName(std::string _name) { name = _name; }
	inline void setEvolutionState(int _evolution_state) { evolution_state = _evolution_state; }
	inline void setStats(std::map<std::string, int> _stats) { stats = _stats; }

	void setTypes(int _typeName1, int _typeName2);

	Pokemon();
	Pokemon(int id, std::string _name, int _type1, int _type2, int _evolution_state, std::map<std::string, int> _stats);
};

