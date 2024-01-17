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

Pokemon DB::getPokemonById(int _id)
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
				if (id == _id)
				{
					Pokemon pokemon(id, path, removeUnderscore(name), type1, type2, evolution_state, stats, stringToVectorInt(movePool));
					file.close();
					return pokemon;
				}
			}
		}
		file.close();
	}
}

std::vector<Pokemon> DB::getPokemons(int _startId, int _amount)
{
	std::vector<Pokemon> res;

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
				if (id >= _startId && res.size() < _amount)
				{
					Pokemon pokemon(id, path, removeUnderscore(name), type1, type2, evolution_state, stats, stringToVectorInt(movePool));
					res.push_back(pokemon);
				}
				if (res.size() == _amount)
				{
					file.close();
					return res;
				}
			}
		}
		file.close();
		return res;
	}
}

std::vector<Pokemon> DB::getSelectablePokemons(int _startId, int _amount)
{
	std::vector<Pokemon> res;

	std::string name, path, movePool;
	int id, evolution_state, type1, type2;
	std::map<std::string, int> stats;
	bool isSelectable;

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
				iss >> id >> path >> name >> type1 >> type2 >> evolution_state >> stats["hp"] >> stats["atk"] >> stats["def"] >> stats["spA"] >> stats["spD"] >> stats["spd"] >> stats["bst"] >> isSelectable >> movePool;
				if (isSelectable)
				{
					if (id >= _startId && res.size() < _amount)
					{
						Pokemon pokemon(id, path, removeUnderscore(name), type1, type2, evolution_state, stats, stringToVectorInt(movePool));
						res.push_back(pokemon);
					}
				}
				if (res.size() == _amount)
				{
					file.close();
					return res;
				}
			}
		}
		file.close();
		return res;
	}
}
