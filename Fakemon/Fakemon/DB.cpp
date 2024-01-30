#include "DB.h"

std::map<std::string, sf::Texture> DB::pokemonTextures;

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

Move DB::getMoveById(int _id)
{
	std::string name;
	int id, type, category, pp, power, accuracy;

	std::string string;
	std::istringstream iss;

	std::ifstream file("../Files/DB/Moves.tsv", std::ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, string);
			iss.clear();
			if (string.find("//") == std::string::npos)
			{
				iss.str(string);
				iss >> id >> name >> type >> category >> pp >> power >> accuracy;
				if (id == _id)
				{
					Move move(id, removeUnderscore(name), type, category, pp, power, accuracy);
					file.close();
					return move;
				}
			}
		}
		file.close();
	}
}

std::vector<Move> DB::getMovePool(std::vector<int> _movePool)
{
	std::vector<Move> res;

	std::string name;
	int id, type, category, pp, power, accuracy;

	std::string string;
	std::istringstream iss;

	std::ifstream file("../Files/DB/Moves.tsv", std::ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, string);
			iss.clear();
			if (string.find("//") == std::string::npos)
			{
				iss.str(string);
				iss >> id >> name >> type >> category >> pp >> power >> accuracy;
				if (std::find(_movePool.begin(), _movePool.end(), id) != _movePool.end())
				{
					Move move(id, removeUnderscore(name), type, category, pp, power, accuracy);
					res.push_back(move);
				}
				if (res.size() == _movePool.size())
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

std::vector<Move> DB::getMoves(std::vector<int> _movePool, int _startId, int _amount)
{
	std::vector<Move> res;

	std::string name;
	int id, type, category, pp, power, accuracy;

	std::string string;
	std::istringstream iss;

	std::ifstream file("../Files/DB/Moves.tsv", std::ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, string);
			iss.clear();
			if (string.find("//") == std::string::npos)
			{
				iss.str(string);
				iss >> id >> name >> type >> category >> pp >> power >> accuracy;
				if (id >= _startId && std::find(_movePool.begin(), _movePool.end(), id) != _movePool.end())
				{
					Move move(id, removeUnderscore(name), type, category, pp, power, accuracy);
					res.push_back(move);
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

void DB::loadTextures()
{
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
				pokemonTextures[path].loadFromFile("../Files/Textures/Pokemons/Base/" + path + ".png");
			}
		}
		file.close();
	}
}