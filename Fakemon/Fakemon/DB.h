#pragma once
#include <fstream>
#include <sstream>

#include "Pokemon.h"

enum Types { Steel = 1, Fighting, Dragon, Water, Electric, Fairy, Fire, Ice, Bug, Normal, Grass, Poison, Psychic, Rock, Ground, Ghost, Dark, Flying};

class DB
{
private:

public:
	static std::string removeUnderscore(std::string _str);
	static std::vector<int> stringToVectorInt(std::string str);


	static Pokemon getPokemonById(int _id);
	static std::vector<Pokemon> getPokemons(int _startId, int _amount);
};

