#include "DB.h"

std::string DB::removeUnderscore(std::string _str)
{
	for (int i = 0; i < _str.length(); i++)
	{
		if (_str[i] == '_')
			_str[i] = ' ';
	}
	return _str;
}

std::vector<int> DB::stringToVectorInt(std::string str)
{
	std::vector<int> res;
	std::stringstream ss(str);
	std::string tmp;
	while (std::getline(ss, tmp, ','))
	{
		res.push_back(std::stoi(tmp));
	}
	return res;
}



void DB::loadTypes()
{
	int id;
	std::string name, weaks, neutrals, resists, immunes;

	std::string string;
	std::istringstream iss;

	std::ifstream file("../Files/DB/Types.tsv", std::ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, string);
			iss.clear();
			if (string.find("//") == std::string::npos)
			{
				iss.str(string);
				iss >> id >> name >> weaks >> neutrals >> resists >> immunes;
				Type* tmp = new Type();
				tmp->setId(id);
				tmp->setName(removeUnderscore(name));
				tmp->setWeak(stringToVectorInt(weaks));
				tmp->setNeutral(stringToVectorInt(neutrals));
				tmp->setResist(stringToVectorInt(resists));
				tmp->setImmune(stringToVectorInt(immunes));

				Type::addType(*tmp);

				delete tmp;
			}
		}
		file.close();
	}
}


void DB::loadPokemons()
{
	std::string name, path, movePool;
	int id, evolution_state, type1, type2;
	std::map<std::string, int> stats;

	std::string string;
	std::istringstream iss;

	std::ifstream file("../Files/DB/Pokemons.tsv", std::ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, string);
			iss.clear();
			if (string.find("//") == std::string::npos)
			{
				iss.str(string);
				iss >> id >> path >> name >> type1 >> type2 >> evolution_state >> stats["hp"] >> stats["atk"] >> stats["def"] >> stats["spA"] >> stats["spD"] >> stats["spd"] >> stats["bst"] >> movePool;
				Pokemon* tmp = new Pokemon();
				tmp->setId(id);
				tmp->setName(removeUnderscore(name));
				tmp->setPath(path);
				tmp->setTypes(type1, type2);
				tmp->setEvolutionState(evolution_state);
				tmp->setStats(stats);
				tmp->setMovePool(stringToVectorInt(movePool));
				Pokemon::addPokemon(*tmp);
				
				delete tmp;
			}
		}
		file.close();
	}
}


DB::DB()
{
	loadPokemons();
	loadTypes();
}
