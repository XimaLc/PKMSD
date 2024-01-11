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
	std::map<int, Type_relation> table_types;

	static std::vector<Type> types;
public:
	inline static std::vector<Type> getTypes() { return types; }
	inline static void addTypes(Type _type) { types.push_back(_type); }
};

