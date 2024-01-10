#pragma once
#include "Pokemon.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>

class DB
{
private:

public:
	std::string removeUnderscore(std::string _str);

	void loadPokemons();


	DB();
};

