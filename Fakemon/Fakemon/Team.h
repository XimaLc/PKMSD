#pragma once
#include "Pokemon.h"

#include <json.hpp>
#include <iostream>

class Team
{
private:
	std::string name;
	std::vector<Pokemon> team;

public:
	Team();
	//Team(int pId1, int pId2, int pId3, int pId4, int pId5, int pId6, int mId1, int mId2, int mId3, int mId4, int mId5, int mId6, int mId7, int mId8, int mId9, int mId10, int mId11, int mId12, int mId13, int mId14, int mId15, int mId16, int mId17, int mId18, int mId19, int mId20, int mId21, int mId22, int mId23, int mId24);

	void addMove(Move _move, int moveIndex, int teamIndex);

	void save();

	void load();

	inline void addPokemon(Pokemon _p, int i) { team[i] = _p; }
	inline std::vector<Pokemon> getPokemons() { return team; }
};

