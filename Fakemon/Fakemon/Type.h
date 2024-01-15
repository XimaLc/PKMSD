#pragma once
#include <iostream>
#include <map>
#include <vector>

enum Type_relation { weak, neutral, resist, immune};

class Type
{
private:
	int id;
	std::string name;
	std::vector<int> weak;
	std::vector<int> neutral;
	std::vector<int> resist;
	std::vector<int> immune;

	static std::vector<Type> types;
public:
	inline static std::vector<Type> getTypes() { return types; }
	inline static void addType(Type _type) { types.push_back(_type); }
	
	inline void setId(int _id) { id = _id; }
	inline void setName(std::string _name) { name = _name; }
	inline void setWeak(std::vector<int> _weak) { weak = _weak; }
	inline void setNeutral(std::vector<int> _neutral) { neutral = _neutral; }
	inline void setResist(std::vector<int> _resist) { resist = _resist; }
	inline void setImmune(std::vector<int> _immune) { immune = _immune; }
};

