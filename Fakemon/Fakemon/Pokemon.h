#pragma once
#include "SFML/Graphics.hpp"
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
	bool isShiny;
	std::string path;
	std::vector<int> movePool;

	sf::Texture texture;
	sf::Sprite sprite;

	static std::vector<Pokemon> pokemons;
public:
	inline static std::vector<Pokemon> getPokemons() { return pokemons; }
	inline static void addPokemon(Pokemon _pokemon) { pokemons.push_back(_pokemon); }

	inline void setId(int _id) { id = _id; }
	inline void setName(std::string _name) { name = _name; }
	inline void setEvolutionState(int _evolution_state) { evolution_state = _evolution_state; }
	inline void setStats(std::map<std::string, int> _stats) { stats = _stats; }
	inline void setMovePool(std::vector<int> _movePool) { movePool = _movePool; }

	void setPath(std::string _path);
	void setTexture();
	void setTypes(int _typeName1, int _typeName2);

	static void displayById(int id, bool _isShiny, sf::RenderWindow& window);
	void display(sf::RenderWindow& window);

	void changeIsShiny(bool _isShiny);

	Pokemon();
	Pokemon(int id, std::string _name, int _type1, int _type2, int _evolution_state, std::map<std::string, int> _stats);
};

