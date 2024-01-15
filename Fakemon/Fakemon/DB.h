#pragma once
#include "Pokemon.h"
#include "Type.h"

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
	std::vector<int> stringToVectorInt(std::string str);


	void loadTypes();
	void loadPokemons();



	DB();
};

