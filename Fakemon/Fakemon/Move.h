#pragma once
#include <iostream>

enum Category { physical, special, status };

class Move
{
private:
	int id;
	std::string name;
	int type;
	int category;
	int pp;
	int power;
	int accuracy;
public:
	inline void setId(int _id) { id = _id; }
	inline void setName(std::string _name) { name = _name; }
	inline void setType(int _type) { type = _type; }
	inline void setCategory(int _category) { category = _category; }
	inline void setPP(int _pp) { pp = _pp; }
	inline void setPower(int _power) { power = _power; }
	inline void setAccuracy(int _accuracy) { accuracy = _accuracy; }

	inline int getId() { return id; }
	inline std::string getName() { return name; }
	inline int getType() { return type; }
	inline int getCategory() { return category; }
	inline int getPP() { return pp; }
	inline int getPower() { return power; }
	inline int getAccuracy() { return accuracy; }

	Move();
	Move(int _id, std::string _name, int _type, int _category, int _pp, int _power, int _accuracy);
};

